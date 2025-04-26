#include <Arduino.h>
#include <Arduino.h>
#include "app_config.h"
#include "utils.h"
#include "task_sensor.h"
#include "task_humidifier.h"
#include "software_timer.h"


#define INIT 0
#define OFF 1
#define GREEN 2
#define YELLOW 3
#define RED 4

#define GREEN_TIME 5
#define YELLOW_TIME 3
#define RED_TIME 2

int humidifier_status;
int humidifier_timer_id;

void initHumidifier(int timer_id) {
  pinMode(PIN_HUM_A, OUTPUT);
  pinMode(PIN_HUM_B, OUTPUT);

  humidifier_timer_id = timer_id;
  humidifier_status = INIT;
  setTriColor(PIN_HUM_A, PIN_HUM_B, LIGHT_OFF);
  Serial.println("Humidifier initialized");
}

void taskHumidifier(void) {
  switch (humidifier_status) {
    case INIT:
      humidifier_status = OFF;
      break;

    case OFF:
      setTriColor(PIN_HUM_A, PIN_HUM_B, LIGHT_OFF);
      if (gHum < H_LOW_MAX) {
        humidifier_status = GREEN;
        setTimer(humidifier_timer_id, GREEN_TIME);
      }
      break;

    case GREEN:
      setTriColor(PIN_HUM_A, PIN_HUM_B, LIGHT_GRE);
      if (isTimerExpired(humidifier_timer_id)) {
        humidifier_status = YELLOW;
        setTimer(humidifier_timer_id, YELLOW_TIME);
      }
      break;

    case YELLOW:
      setTriColor(PIN_HUM_A, PIN_HUM_B, LIGHT_YEL);
      if (isTimerExpired(humidifier_timer_id)) {
        humidifier_status = RED;
        setTimer(humidifier_timer_id, RED_TIME);
      }
      break;

    case RED:
      setTriColor(PIN_HUM_A, PIN_HUM_B, LIGHT_RED);
      if (isTimerExpired(humidifier_timer_id)) {
        humidifier_status = OFF;
      }
      break;
  }
}
