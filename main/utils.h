#ifndef UTILS_H
#define UTILS_H

#define LIGHT_OFF 0
#define LIGHT_GRE 1
#define LIGHT_YEL 2
#define LIGHT_RED 3

#include <Arduino.h>

/* Pin helper for tri-color LED control */
void setTriColor(uint8_t pinA, uint8_t pinB, uint8_t code);

#endif // UTILS_H