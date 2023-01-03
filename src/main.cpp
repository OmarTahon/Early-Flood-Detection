/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-water-sensor
 */
#include <Arduino.h>
// #include <WiFi.h>

#define POWER_PIN  17 // ESP32 pin GIOP17 connected to sensor's VCC pin
#define SIGNAL_PIN 36 // ESP32 pin GIOP36 (ADC0) connected to sensor's signal pin
#define SENSOR_MIN 0
#define SENSOR_MAX 521

int value = 0; // variable to store the sensor value
int level = 0; // variable to store the water level

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  level = map(value, SENSOR_MIN, SENSOR_MAX, 0, 4); // 4 levels
  Serial.print("Water level: ");
  Serial.println(level);

  delay(1000);
}






// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <WiFiAP.h>
 
// // #define LED_BUILTIN 2   // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED
 
// // Set these to your desired credentials.
// const char *ssid = "Ya3m";
// const char *password = "browhat1";
 
// WiFiServer server(80);
 
 
// void setup() {
//   // pinMode(LED_BUILTIN, OUTPUT);
 
//   Serial.begin(115200);
//   Serial.println();
//   Serial.println("Configuring access point...");
 
//   // You can remove the password parameter if you want the AP to be open.
//   WiFi.softAP(ssid, password);
//   IPAddress myIP = WiFi.softAPIP();
//   Serial.print("AP IP address: ");
//   Serial.println(myIP);
//   server.begin();
 
//   Serial.println("Server started");
// }
 
// void loop() {
//   WiFiClient client = server.available();   // listen for incoming clients
 
//   if (client) {                             // if you get a client,
//     Serial.println("New Client.");           // print a message out the serial port
//     String currentLine = "";                // make a String to hold incoming data from the client
//     while (client.connected()) {            // loop while the client's connected
//       if (client.available()) {             // if there's bytes to read from the client,
//         char c = client.read();             // read a byte, then
//         Serial.write(c);                    // print it out the serial monitor
//         if (c == '\n') {                    // if the byte is a newline character
 
//           // if the current line is blank, you got two newline characters in a row.
//           // that's the end of the client HTTP request, so send a response:
//           if (currentLine.length() == 0) {
//             // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//             // and a content-type so the client knows what's coming, then a blank line:
//             client.println("HTTP/1.1 200 OK");
//             client.println("Content-type:text/html");
//             client.println();
 
//             // the content of the HTTP response follows the header:
//             client.print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
//             client.print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");
 
//             // The HTTP response ends with another blank line:
//             client.println();
//             // break out of the while loop:
//             break;
//           } else {    // if you got a newline, then clear currentLine:
//             currentLine = "";
//           }
//         } else if (c != '\r') {  // if you got anything else but a carriage return character,
//           currentLine += c;      // add it to the end of the currentLine
//         }
 
//         // Check to see if the client request was "GET /H" or "GET /L":
//         // if (currentLine.endsWith("GET /H")) {
//         //   digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
//         // }
//         // if (currentLine.endsWith("GET /L")) {
//         //   digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
//         // }
//       }
//     }
//     // close the connection:
//     client.stop();
//     Serial.println("Client Disconnected.");
//   }
// }


// #include <Arduino.h>
// #include <WiFi.h>

// #include "../config/config.h"
// #include "Device Drivers/wifi-connection.h"
// #include "Device Drivers/ota.h"
// #include "Device Drivers/deep-sleep.h"
// #include "Device Drivers/mqtt.h"
// #include "Device Drivers/leak-detect.h"
// #include "Device Drivers/attention.h"

// #ifdef __arm__
// // should use uinstd.h to define sbrk but Due causes a conflict
// extern "C" char* sbrk(int incr);
// #else  // __ARM__
// extern char *__brkval;
// #endif  // __arm__

// RTC_DATA_ATTR int bootCount = 0;
// RTC_DATA_ATTR int leakStatus;
// bool leakChanged;
// int8_t wifi_strength;

// const unsigned long intervalAlertMillis = 30000;  // How often to alert when leak sensor is wet
// RTC_DATA_ATTR unsigned long prevMillisAlert = 0;

// const long minIntervalMQTT   = 300000;    // Minimum interval at which to publish metrics (5m = 300,000 milli), higher when sleeping
// RTC_DATA_ATTR unsigned long prevMillisMQTT = 0;   // Stores last time sensor was published

// // unsigned long int wraps back to 0 after 4,294,967,295 milliseconds or around 50 days
// // This variable is used to approximately track time while in deep sleep (instead of calling millis)
// RTC_DATA_ATTR unsigned long millisOffset = 0;

// esp_sleep_wakeup_cause_t wakeup_reason;

// void updateWiFiSignalStrength() {
//   if(WiFi.isConnected()) {
//     //serial_println(F("[WIFI] Updating signal strength..."));
//     wifi_strength = WiFi.RSSI();
//     Serial.print("[WIFI] signal strength: ");
//     Serial.println(wifi_strength);
//   }
// }

// // void callback(){
// //   //placeholder callback function
// //   Serial.println("[CALLBACK] Touchpad activated");
// // }

// void setup() {

//   Serial.begin(115200);

//   // Increment boot number and print it every reboot
//   ++bootCount;
//   Serial.println("Boot number: " + String(bootCount));

//   int sleep_sec = TIME_TO_SLEEP_SEC;
//   bool forceMqttUpdate = false;

//   // Check leak status
// //   checkLeakStatus();

//   // If leak status changes, blink and force MQTT update
// //   if (leakChanged == true) {
// //     // play_sound();
// //     blink_now();
// //     forceMqttUpdate = true;
// //   }

//   // If wet, do sound alert every intervalAlertMillis
// //   if (leakStatus == 1) {
// //     // Check if alert interval has expired
// //     if (millisOffset - prevMillisAlert >= intervalAlertMillis) {
// //       prevMillisAlert = millisOffset;
// //       play_sound();
// //       blink_now();
// //     }

//     // set sleep sec to use WET_SLEEP_SEC, which is shorter because
//     // touch sensor is disabled to avoid constant wakeups when wet.
//     // sleep_sec = WET_SLEEP_SEC;
// //   }
// //   setup_sleep(sleep_sec);


//   // publish a new MQTT message every minIntervalMQTT millis
//   // if ((millisOffset - prevMillisMQTT >= minIntervalMQTT) || (forceMqttUpdate == true)) {
//     // Save the last time a new reading was published
//     // prevMillisMQTT = millisOffset;
//     connectWiFi();
//     updateWiFiSignalStrength();
//     mqttConnect();
//     sendUpdateToMQTT();
//   // }

//   // When dry, setup interrupt on Touch Pad 3 (GPIO15)
//   // Avoids waiting for timer wakeup interval when leak is present
// //   if (leakStatus == 0) {
// //     touchAttachInterrupt(T3, callback, THRESHOLD);
// //     // Configure Touchpad as wakeup source
// //     esp_sleep_enable_touchpad_wakeup();
// //   }

//   // if (millisOffset > 4000000000) {
//   //   Serial.println("Rebooting due to milliOffset before wraps");
//   //   ESP.restart();
//   // }

// //  Check OTA update on first boot
//   if (bootCount == 1) {
//     connectWiFi();  // Need to make sure WiFi connected since it's conditional above
//     setupOTA();
//     delay(2000);
//     // takes a few attempts.  worked on count=11 (2s each)
//     unsigned short maxRetry = 20;
//     unsigned short countRetry = 0;
//     while(countRetry <= maxRetry) {
//         Serial.println("[OTA] count: " + String(countRetry));
//         countRetry++;
//         ArduinoOTA.handle();
//         delay(2000);
//     }
//   }

// //   deep_sleep(sleep_sec);
// }

// void loop() {
// }