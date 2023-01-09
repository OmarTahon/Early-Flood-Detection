
#include "../config.h"
#include "deepSleep.h"

void enterDeepSleep() {
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_SEC); // wake up in 15 minutes
  esp_deep_sleep_start();
}