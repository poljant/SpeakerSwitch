/*
 * WebWiFiScan.h
 *
 *  Created on: 11.04.2017
 *      Author: Jan Trzciński poljant@post.pl
 */

#ifndef WEBWIFISCAN_H_
#define WEBWIFISCAN_H_


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

String HTMLHeader();
String HTMLFooter();
String HTMLPage();
String HTMLPage1();
String HTMLPage2();
String HTMLWiFiScan();
void setservers(void);





#endif /* WEBWIFISCAN_H_ */
