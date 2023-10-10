#include <WiFi.h>

 

const char* ssid = "HTL-Weiz";    

const char* password = "HTL-Weiz";

const char* serverAddress = "172.31.183.87";

const int serverPort = 4080;

 

WiFiClient TCPclient;

 

void setup() {

  Serial.begin(9600);

 

 

  Serial.println("ESP32: TCP CLIENT + A BUTTON/SWITCH");

 

 

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);

    Serial.println("Connecting to WiFi...");

  }

  Serial.println("Connected to WiFi");

 

    TCPclient.connect(serverAddress, serverPort);

    if (TCPclient.connected()) {

        Serial.println("Connected to TCP server");

    }

}

 

 

 

void loop() {

 

   

    if (!TCPclient.connected()) {

    Serial.println("NOT CONNECTED");

    delay(1000);

    TCPclient.connect(serverAddress, serverPort);

   

  }

    else if(TCPclient.connected()){

    Serial.println("CONNECTED");

    TCPclient.write(1);

    TCPclient.flush();

    TCPclient.stop();

    delay(1000);

    }

  }