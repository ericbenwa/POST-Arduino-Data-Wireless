#include <SPI.h>
#include <WiFi.h>

//
// EDIT: change the SSID and password to match your network
//
char ssid[] = "yournetwork";  // your network SSID (name)
char pass[] = "yourpassword";        // your network password
int status = WL_IDLE_STATUS;
WiFiClient client;

//
// EDIT: server address to match your domain
//
char server[] = "www.yourdomain.com";

// this is the data that will be passed into your POST and matches your mysql column
int yourarduinodata = 999;
String yourdatacolumn = "yourdata=";
String yourdata;

void setup() {
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
  
  // Combine yourdatacolumn header (yourdata=) with the data recorded from your arduino
  // (yourarduinodata) and package them into the String yourdata which is what will be
  // sent in your POST request
  yourdata = yourdatacolumn + yourarduinodata;
  
  httpRequest();
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

// this method makes a HTTP connection to the server
void httpRequest() {
  // if there's a successful connection, send the HTTP PUT request
  if (client.connect(server, 80)) {
    Serial.println("connecting...");

    //
    // EDIT: the URL to the location of your insert_mysql.php on your web-host
    //
    client.println("POST /insert_mysql.php HTTP/1.1");

    //
    // EDIT: Host to match your domain
    //
    client.println("Host: www.yourdomain.com");
    client.println("User-Agent: Arduino/1.0");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded;");
    client.print("Content-Length: ");
    client.println(yourdata.length());
    client.println();
    client.println(yourdata);
  } 
  else {
    // if you couldn't make a connection:
    Serial.println("Connection failed");
    Serial.println("Disconnecting.");
    client.stop();
  }
}
