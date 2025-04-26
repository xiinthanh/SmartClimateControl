#include <Arduino.h>
#include "app_config.h"
#include "task_heartbeat.h"

#define OFF 0
#define ON 1

int led_status;

void initHeartbeat() {
  pinMode(PIN_STATUS, OUTPUT);
 
  // the LED is off at the start
  led_status = OFF;
  digitalWrite(PIN_STATUS, LOW);
}

void taskBlink(void) {
  // interchange b/w 2 states: ON (1) and OFF (0)
  led_status = 1 - led_status;
  switch (led_status) {
    case ON:
      digitalWrite(PIN_STATUS, HIGH);
      break;
    case OFF:
      digitalWrite(PIN_STATUS, LOW);
      break;
  }
}