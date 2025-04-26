#include <Arduino.h>
#include "app_config.h"
#include "utils.h"
#include "task_sensor.h"
#include "task_cooler.h"
#include "software_timer.h"

#define INIT 0
#define OFF 1
#define ON 2

#define ON_TIME 5   // cooler will turn on for 5s

int cooler_status;  // Current state of the cooler
int cooler_timer_id;   // Timer ID for the cooler

void initCooler(int timer_id) {
  pinMode(PIN_COOLER_A, OUTPUT);
  pinMode(PIN_COOLER_B, OUTPUT);

  cooler_timer_id = timer_id;
  cooler_status = INIT;
  setTriColor(PIN_COOLER_A, PIN_COOLER_B, LIGHT_OFF);
  Serial.println("Cooler initialized");
}

void taskCooler(void) {
  switch(cooler_status) {
    case INIT:
      // Initialize the cooler and move to OFF state
      cooler_status = OFF;
      break;

    case OFF:
      // Cooler is off
      setTriColor(PIN_COOLER_A, PIN_COOLER_B, LIGHT_OFF);

      // If temperature is warm, turn on the cooler
      if (gTemp >= T_WARM_MIN) {
        cooler_status = ON;
        setTimer(cooler_timer_id, ON_TIME);  // Start the timer for ON_TIME seconds
      }
      break;

    case ON:
      // Cooler is on
      setTriColor(PIN_COOLER_A, PIN_COOLER_B, LIGHT_GRE);  // Turn on cooler with green light
      if (isTimerExpired(cooler_timer_id)) {
        // If the timer has expired (ON_TIME has passed), turn off the cooler
        cooler_status = OFF;
      }
      break;
  }
}
