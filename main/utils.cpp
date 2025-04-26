#include "utils.h"

void setTriColor(uint8_t pinA, uint8_t pinB, uint8_t code) {
  /* code: 0‑off, 1‑green, 2‑yellow, 3‑red */
  switch (code) {
    case LIGHT_GRE:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      break;

    case LIGHT_YEL:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      break;

    case LIGHT_RED:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      break;

    case LIGHT_OFF:
    default:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      break;
  }
}
