
#include "config.h"
#include "MCU_Layer/deepSleep.h"
#include "MCU_Layer/wifi_conn.h"
// #include "Data_Manager/firebase.h"
#include "Data_Manager/sensor.h"
#include <Firebase_ESP_Client.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"


void sendDataToFirebase(float waterLevel);
void setAlarm(float waterLevel) ;

FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;
bool signupOK = false;
void setup() {
  Serial.begin(115200);
  long st2 = millis();
  connectToWiFi();
  // connectFirebase();

    // Initialize Firebase
  /* Assign the api key (required) */
  config.api_key = FIREBASE_AUTH;

  /* Assign the RTDB URL (required) */
  config.database_url = FIREBASE_HOST;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  // /* Assign the callback function for the long running token generation task */
  // config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

//   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.reconnectWiFi(true);
   long tm2 = millis() - st2;
  Serial.println("time connect :");
  Serial.println(tm2);
  Serial.println("ms");
}

void loop() {
  long st = millis();
  // Read water level sensor and store value in a variable
  float waterLevel = readWaterLevelSensor();

  // Send data to Firebase
  sendDataToFirebase(waterLevel);

  // Set alarm if water level exceeds a certain threshold
  setAlarm(waterLevel);

  long tm = millis() - st;
  Serial.println("time :");
  Serial.println(tm);
  Serial.println("ms");

  // Enter deep sleep mode for 15 minutes
  enterDeepSleep();
}

void sendDataToFirebase(float waterLevel) {
     // Push data to Firebase
      // String path = "/sensorData";

    if (Firebase.ready() && signupOK){
    // Write an Int number on the database path test/int
    if (Firebase.RTDB.push(&fbdo, "Sensor/reading", waterLevel)){
      Serial.println("PASSED");
      Serial.println("PATH: " );
      Serial.println(fbdo.dataPath());
      Serial.println("TYPE: " );
      Serial.println(fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " );
      Serial.println(fbdo.errorReason());
    }
    }
}

void setAlarm(float waterLevel) {


    // Push data to Firebase
    // String alarmPath = "/alarm";
    
    if (Firebase.ready() && signupOK){
    if (waterLevel > ALLARM_THRESHOLD){
    if (Firebase.RTDB.setBool(&fbdo, "checkAlarm/alarm", true)){
      Serial.println("Alarm triggered");
      Serial.println("PASSED");
      Serial.println("PATH: " );
      Serial.println(fbdo.dataPath());
      Serial.println("TYPE: " );
      Serial.println(fbdo.dataType());
    }
    else {
        Serial.println("Error setting alarm");
      Serial.println("FAILED");
      Serial.println("REASON: " );
      Serial.println(fbdo.errorReason());
    }}
    else{
    if (Firebase.RTDB.setBool(&fbdo,"checkAlarm/alarm", false)){
      Serial.println("PASSED");
      Serial.println("PATH: " );
      Serial.println(fbdo.dataPath());
      Serial.println("TYPE: " );
      Serial.println(fbdo.dataType());
    }
    else {
        Serial.println("Error setting alarm");
      Serial.println("FAILED");
      Serial.println("REASON: " );
      Serial.println(fbdo.errorReason());
    }

    }
    }
}
