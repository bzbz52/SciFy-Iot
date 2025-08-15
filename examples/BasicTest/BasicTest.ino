#include <WiFi.h>
#include <SciFyIot.h>
const char* ssid = "YOUR_WIFI";
const char* pass = "YOUR_PASSWORD";

SciFyIot iot("API Key", "API Secret");

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  String cmd = iot.getLatestCommand();
  if (cmd.length() > 0) {
    Serial.println("Command: " + cmd);
  }
  delay(2000);
}
