#include "Led.h"

Led::Led(unsigned char pin) : pin(pin), state(OFF) {
  pinMode(pin, OUTPUT);
  off();
}

void Led::off() {
  state = OFF;
  digitalWrite(pin, state);
}

void Led::on() {
  state = ON;
  digitalWrite(pin, state);
}

void Led::toggle() {
  state = !state;
  digitalWrite(pin, state);
}

bool Led::isOn() const {
  return state == ON;
}
