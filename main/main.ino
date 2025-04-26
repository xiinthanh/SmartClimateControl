#include "scheduler.h"
#include "software_timer.h"
#include "app_config.h"
#include <Arduino.h>

#include "task_heartbeat.h"
#include "task_sensor.h"
#include "task_heater.h"
#include "task_cooler.h"
#include "task_humidifier.h"


void TIMER_ISR(void *pvParameters) {
  while (1) {
    SCH_Update();
    vTaskDelay(10);
  }
}


void setup() {
  // Initialize all components
  initHeartbeat();
  initSensor();
  initHeater();
  initCooler(0);
  initHumidifier(1);

  
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);
  SCH_Init();


  SCH_Add_Task(timerRun, 0, TICKS(1000));         // Add the timer run task (1 second cycle)

  // Add tasks to the scheduler
  SCH_Add_Task(taskBlink, 0, TICKS(1000));           // Heartbeat LED - blink every 1s
  SCH_Add_Task(taskReadSensor, 0, TICKS(5000));  // Read sensor every 5s
  SCH_Add_Task(taskHeater, 0, TICKS(5000));  // Update heater every 5s (after read new data from sensor)
  SCH_Add_Task(taskCooler, 0, 1);
  SCH_Add_Task(taskHumidifier, 0, 1);

}

void loop() {
  SCH_Dispatch_Tasks();
}
