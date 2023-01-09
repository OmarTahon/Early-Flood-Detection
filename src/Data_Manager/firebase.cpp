
// #include "firebase.h"
// #include "../config.h"



// void sendDataToFirebase(float waterLevel) {
//      // Push data to Firebase
//       String path = "/sensorData";

//     if (Firebase.ready() && signupOK){
//     // Write an Int number on the database path test/int
//     if (Firebase.RTDB.push(&fbdo, path, waterLevel)){
//       Serial.println("PASSED");
//       Serial.println("PATH: " );
//       Serial.println(fbdo.dataPath());
//       Serial.println("TYPE: " );
//       Serial.println(fbdo.dataType());
//     }
//     else {
//       Serial.println("FAILED");
//       Serial.println("REASON: " );
//       Serial.println(fbdo.errorReason());
//     }
//     }
// }

// void setAlarm(float waterLevel) {


//     // Push data to Firebase
//     String alarmPath = "/alarm";
    
//     if (Firebase.ready() && signupOK){
//     if (waterLevel > ALLARM_THRESHOLD){
//     if (Firebase.RTDB.setBool(&fbdo, alarmPath, true)){
//       Serial.println("Alarm triggered");
//       Serial.println("PASSED");
//       Serial.println("PATH: " );
//       Serial.println(fbdo.dataPath());
//       Serial.println("TYPE: " );
//       Serial.println(fbdo.dataType());
//     }
//     else {
//         Serial.println("Error setting alarm");
//       Serial.println("FAILED");
//       Serial.println("REASON: " );
//       Serial.println(fbdo.errorReason());
//     }}
//     else{
//     if (Firebase.RTDB.setBool(&fbdo, alarmPath, false)){
//       Serial.println("PASSED");
//       Serial.println("PATH: " );
//       Serial.println(fbdo.dataPath());
//       Serial.println("TYPE: " );
//       Serial.println(fbdo.dataType());
//     }
//     else {
//         Serial.println("Error setting alarm");
//       Serial.println("FAILED");
//       Serial.println("REASON: " );
//       Serial.println(fbdo.errorReason());
//     }

//     }
//     }
// }