# SpeakerSwitch
Speaker Switch.

The system allows you to switch speaker sets.
The device uses the WeMos D1 mini module.
Not all loudspeakers can be connected in parallel with loudspeakers.
Such connection increases the load on the amplifier which may cause sound distortion or damage to the amplifier.
Therefore, if you decide to connect additional speakers, you should reduce the control of the speakers.

To connect the speakers, unscrew the cover.
The connector for two cables (four screws) is for connecting the amplifier.
Watch out for the + (red) and - (minus) wires, so as not to cause phase reverses in the speakers, because the sound may be unpleasant.
Left contacts left channel -L + (plus red), right channel -R +.
The four-cable connector (eight screws) is for connecting speakers.
Contacts from the left speakers B the left channel + BL-, right channel + BR-,
further loudspeakers A left channel + AR-, right channel + AR-.

The first time you start:
1. Connect to the WiFi network SpeakerSwitch (password: 12345678).
2. Enter the web browser http://192.168.4.1
3. When the web page is launched, select "Scan the WiFi Network",
4. After a short while, a table with available WiFi networks will be displayed on the screen.
   Select the network with which you want to connect,
   enter the password for this network and press "Connect".
5. If you have not made any mistake, after a short time the message will appear on the screen that you have been connected to the WiFi network and will display the IP address of our device in this network. Remember this IP - needed to connect to our device.
6. If we do not get a connection, this should be repeated (4 and 5).
7. After connecting to the chosen WiFi system, the STATION state switches and after 5 minutes the WiFi SpeakerSwitch network is no longer visible. After the connection to our network is broken, AP SpeakerSwitch is available again.

Now we can connect to our WiFi network and connect to the device
	http://IP  (IP of our device).

Speaker control is using the buttons on the website.

"SpeakerA - ON" (red colour) - attached speakers A.
"SpeakerB - ON" (red colour) - attached speakers B.
"SpeakersA+B - OFF" (green color) - speakers attached according to previous buttons.
"SpeakersA+B - ON" {red colour) - both loudspeakers included.

Remote control.
In normal state (without power supply), the A speakers are connected.
http://IP/speaker/B - it only turns on the B speakers, it distorts the others
http://IP/speaker/A - it only turns on the A speakers, it distorts the others
http://IP/speakerAB/1 - attaches all A and B speakers
http://IP/speakerAB/0 - disconnects the speaker's parallel operation, attached speakers A or B
                         depends on the state of the switches "SpeakerA - ON" or "SpeakerB- ON".
                        
