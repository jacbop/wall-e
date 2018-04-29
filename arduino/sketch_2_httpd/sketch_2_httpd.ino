#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

char* ssid = "Wilberding";
char* password = "b00sh45A";

ESP8266WebServer server;

uint8_t pin_relay = 16;

void setup() {
  pinMode(pin_relay, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());

  server.on("/",[](){server.send(200, "text/plain", "Hello World");});
  server.on("/grind", grind);
  server.begin();
}

void loop() {
  server.handleClient();
}

void grind() {
  digitalWrite(pin_relay, true);
  server.send(200, "OK");
 // delay(5000);
 // digitalWrite(pin_relay, false);
}

