/*
Repeating Wifi Web client

This sketch connects to a router using an Arduino Wifi shield.

Circuit:
* Wifi shield attached to pins 10, 11, 12, 13

created 23 Apr 2012
by Tom Igoe

modified 4 May 2013
by Eric Benoit

http://arduino.cc/en/Tutorial/WifiWebClientRepeating
This code is in the public domain.
*/

#include <SPI.h>
#include <WiFi.h>

char ssid[] = "insertyournetworkhere";  // your network SSID (name)
char pass[] = "insertyourpasswordhere";        // your network password
int keyIndex = 0;                // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;

// initialize the wifi client library
WiFiClient client;


void setup() {
  // start serial port
  Serial.begin(9600);

  // attempt to connect to wifi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection
    delay(10000);
  }

  // you're connected now, so print out the status
  printWifiStatus();
  delay(20000); // after 20 seconds, disconnect
  client.stop();
  Serial.println("Automatically disconnected after 20 seconds.");
}

void loop() {

}

void printWifiStatus() {
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
