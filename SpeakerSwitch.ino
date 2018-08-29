#include "Arduino.h"
#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>
#include "WebWiFiScan.h"
#include "Relay.h"
#include <EEPROM.h>

#define pinLED BUILTIN_LED
#define pinRelay1 D8
#define pinRelay2 D7
//#define IP_STATIC
#define DEBUG
//#define DEBUG_ON
//#define POLISH


String version = "1.0.8";
const char* ssid = ""; //                                                               "; //64 char
const char* pass = ""; //                                                                "; //64 char

const char* myssid = "TEST";
const char* mypass = "testtest";

//dane dla AP
const char* ap_ssid = "SpeakerSwitch";   // SSID AP
const char* ap_pass = "12345678";  // password do AP
int ap_channel= 7; //numer kanału dla AP
Relay R1;
Relay R2;

extern ESP8266WebServer server;
extern const char* modes[] ; //= {"NULL","STA","AP","STA+AP"
extern const char* phymodes[]; // = { "","B", "G", "N"};
unsigned long minutes5 = 60000*5;
boolean ifAP = true;  //AP włączony
unsigned long APtime = 0;  //czas pracy AP
uint8_t etemp = 0;    // zmienne określająca czy należy zmienić zawarość EEPROM.
uint8_t Eetemp = 63; //adres w EEPROM

#ifdef IP_STATIC
// ustaw dane wg swojej sieci
IPAddress IPadr(10,110,2,105); //stały IP
IPAddress netmask(255,255,0,0);
IPAddress gateway(10,110,0,1);
#endif

void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
#endif
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
  R1.setPin(pinRelay1);
  R1.begin();
  R1.setOff();
  R2.setPin(pinRelay2);
  R2.begin();
  R2.setOff();
  //ustaw SSID, pass i kanał dla AP
  WiFi.softAP(ap_ssid, ap_pass, ap_channel);
#ifdef IP_STATIC
  WiFi.config(IPadr,gateway,netmask);  // stały IP
#endif
  WiFi.mode(WIFI_AP_STA); //tryb AP_STATION

  EEPROM.begin(128);
  delay(20);
  EEPROM.get(Eetemp,etemp);

#ifdef DEBUG
  Serial.print("etemp = ");
  Serial.println(etemp);
#endif
  if (etemp==0xFF or etemp==0){
   etemp = 1;
   EEPROM.put(0, myssid);
   EEPROM.put(64, mypass);
   EEPROM.put(Eetemp,etemp);
   delay(30); 
   EEPROM.get(0, ssid);
   EEPROM.get(64, pass);
//   WiFi.mode(WIFI_AP_STA); //tryb AP_STATION 
   WiFi.begin(ssid, pass);
   
  }else{
    if(etemp==1){
    EEPROM.get(0, ssid);
    EEPROM.get(64, pass); 
  //  WiFi.mode(WIFI_AP_STA); //tryb AP_STATION 
    WiFi.begin(ssid, pass);
    };
 //    WiFi.mode(WIFI_AP_STA); //tryb AP_STATION
     WiFi.begin();  
  };

  EEPROM.end();
  int it = 30;
  while ((WiFi.status() != WL_CONNECTED) and it>0) {  //  czekaj na połączenie z WiFi
   delay(500);
   it-- ;
#ifdef DEBUG
   Serial.print(".");
#endif
  }
 #ifdef DEBUG 
  if (it>0) {
   Serial.println("");
   Serial.println("WiFi połączone");
   Serial.println(WiFi.localIP());
   Serial.println(WiFi.macAddress());
   Serial.print("Tryb pracy: ");
   Serial.println(modes[WiFi.getMode()]);
   Serial.print("Tryb modulacji: ");
   Serial.println(phymodes[WiFi.getPhyMode()]);
   Serial.print("Nr kanału: ");
   Serial.println(WiFi.channel());
   Serial.print("IP AP: ");
   Serial.println(WiFi.softAPIP() );
  }else {
   Serial.println();
   Serial.println("Brak połączenia z WiFi!.");
   Serial.println(modes[WiFi.getMode()]);
   Serial.println("-------------------");
   Serial.println(ssid);
   Serial.println(pass);
  }
#endif
 
 setservers();

};

void loop()
{
  server.handleClient();
 if (WiFi.status() != WL_CONNECTED){ //gdy brak połaczenia
  digitalWrite(pinLED, LOW);
  APtime = 0;
  ifAP = true;
  if (WiFi.getMode() != WIFI_AP_STA){
    #ifdef DEBUG
       Serial.println(WiFi.getMode());
    #endif
   WiFi.mode(WIFI_AP_STA);
   }
 }else                      //gdy jest połączenie
 { // wyłącz LED gdy jest połączenie z WiFi
  digitalWrite(pinLED, HIGH);
  
  if (ifAP and (APtime == 0)) {
  APtime = (millis() + minutes5);
  };
  if (ifAP and (millis() >= APtime)) {
   if (WiFi.getMode() != WIFI_STA){
    WiFi.mode(WIFI_STA);
    ifAP = false;
    };
  };
 };
}

