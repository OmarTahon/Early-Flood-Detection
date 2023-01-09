
#include "sensor.h"
#include "../config.h"


int readWaterLevelSensor() {
    digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
    delay(10);                      // wait 10 milliseconds
    int sensorValue = analogRead(SIGNAL_PIN); // read the analog value from sensor
    digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF
  return sensorValue;
}