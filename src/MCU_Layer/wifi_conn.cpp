

#include "wifi_conn.h"
#include "../config.h"

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");
}

void disconnectWiFi() {
    if (WiFi.status() == WL_CONNECTED) {
        WiFi.disconnect();
        WiFi.mode(WIFI_OFF);
        Serial.println("[WIFI] disconnect/off complete");
    }
}
