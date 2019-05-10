#include "WiFi.h"
#include "ESPAsyncWebServer.h"

AsyncWebServer server(80);

const char *ssid = "CodeCafeESP32-1";
const char *password = "icecream";

void setup(){
  Serial.begin(115200);
 
  WiFi.softAP(ssid, password);
 
  server.on("/devoxx", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello Devoxx!!");
  });

  Serial.println();
  Serial.print("Connect and go here: ");
  Serial.println(WiFi.softAPIP());
 
  server.begin();
}
 
void loop(){}