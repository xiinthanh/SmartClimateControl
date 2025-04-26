#include <Arduino.h>
#include "app_config.h"
#include "utils.h"
#include "task_sensor.h"
#include "task_heater.h"

void initHeater() {
  pinMode(PIN_HEATER_A, OUTPUT);
  pinMode(PIN_HEATER_B, OUTPUT);
  
  setTriColor(PIN_HEATER_A, PIN_HEATER_B, LIGHT_OFF);
  Serial.println("Heater initialized");
}

void taskHeater(void) {
  if (gTemp >= T_SAFE_MIN && gTemp <= T_SAFE_MAX) {
    // Safe zone: temperature between 20°C and 25°C -> Show GREEN light
    setTriColor(PIN_HEATER_A, PIN_HEATER_B, LIGHT_GRE);
  }
  else if (gTemp >= T_WARM_MIN && gTemp <= T_WARM_MAX) {
    // Warm zone: temperature between 25°C and 28°C -> Show ORANGE light
    setTriColor(PIN_HEATER_A, PIN_HEATER_B, LIGHT_YEL);
  }
  else {
    // Danger zone: temperature < 20°C or >= 28°C -> Show RED light
    setTriColor(PIN_HEATER_A, PIN_HEATER_B, LIGHT_RED);
  }
}

