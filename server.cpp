// ESP32 TCP Server

#include <WiFi.h>

 

#define SERVER_PORT 4080

 

const char* ssid = "HTL-Weiz";

const char* password = "HTL-Weiz";

 

WiFiServer TCPserver(SERVER_PORT);

 

void setup() {

  Serial.begin(9600);

 

  Serial.println("ESP32 #2: TCP SERVER");

 

  // Connect to Wi-Fi

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);

    Serial.println("Connecting to WiFi...");

  }

  Serial.println("Connected to WiFi");

 

  // Print TCP Server address:

  Serial.print("ESP32 #2: TCP Server IP address: ");

  Serial.println(WiFi.localIP());

 

  // Start listening for a TCP client

  TCPserver.begin();

}

 

void loop() {

  // Wait for a TCP client from ESP32 #1:

  WiFiClient client = TCPserver.available();

 

  // if client

  //   == NULL while cli #

  //           .connected while (client.a #)

 

  //               client.stop

 

  if (client) {

    // Read the command from the TCP client:

    while (client.connected()) {

      while (client.available()) {

        // Serial.println(client.available());

        int command = client.read();

        Serial.print("ESP32 #2: - Received command: ");

        Serial.println(command);

        client.stop();

      }

     

    }

  }

}