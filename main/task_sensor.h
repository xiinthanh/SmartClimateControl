#ifndef TASK_SENSOR_H
#define TASK_SENSOR_H

void taskReadSensor(void);
void initSensor(void);

// Global temperature and humidity variables
extern float gTemp;
extern float gHum;

#endif // TASK_SENSOR_H