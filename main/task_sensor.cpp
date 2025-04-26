#include <Arduino.h>
#include <DHT20.h>
#include <Wire.h>
#include "task_sensor.h"
#include "app_config.h"


// Global variables
float gTemp = 0.0f;
float gHum = 0.0f;

// Local variables
DHT20 dht20;

void initSensor() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200); 
  Serial.println("Initializing DHT20 sensor...");

  Wire.begin(GPIO_NUM_11, GPIO_NUM_12);

  // Initialize DHT20 sensor
  if (dht20.begin()) {
    Serial.println("DHT20 sensor initialized successfully");
  } else {
    Serial.println("Failed to initialize DHT20 sensor! Check wiring.");
  }
}

void taskReadSensor(void) {
  dht20.read();

  // Reading temperature in Celsius
  float temperature = dht20.getTemperature();
  // Reading humidity
  float humidity = dht20.getHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // save the information to the global variables
    gTemp = temperature;
    gHum = humidity;

      // Print the results
    Serial.print("Humidity: ");
    Serial.print(gHum);
    Serial.print("%  Temperature: ");
    Serial.print(gTemp);
    Serial.println("°C");
  }
}