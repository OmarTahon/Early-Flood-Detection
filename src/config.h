#ifndef CONFIG
#define CONFIG

// How often to wake up from deep sleep
#define TIME_TO_SLEEP_SEC 15 * 60 * 1000000 //15min
#define ALLARM_THRESHOLD 1000 

#define WIFI_SSID "OnePluse Norde 2T 5G"
#define WIFI_PASSWORD "123456"
#define WIFI_TIMEOUT 20000 // 20 seconds
#define WIFI_RECOVER_TIME_MS 1000 // (1-20 seconds)

#define FIREBASE_HOST "https://embedded-esp32-af39b-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_AUTH "AIzaSyBBieDR8odOgCaoT3c2eeY93CBqCaojaTs"

#define POWER_PIN  17 // ESP32 pin GIOP17 connected to sensor's VCC pin
#define SIGNAL_PIN 36 // ESP32 pin GIOP36 (ADC0) connected to sensor's signal pin

#include <Arduino.h>

#endif