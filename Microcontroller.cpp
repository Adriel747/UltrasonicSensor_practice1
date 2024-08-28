#include "Microcontroller.h"

Microcontroller::Microcontroller(Led* leds, int numLeds, UltrasonicSensor& sensor) 
  : leds(leds), numLeds(numLeds), sensor(sensor) {}

void Microcontroller::updateLeds() {
  float distance = sensor.getDistance();

  for (int i = 0; i < numLeds; i++) {
    if (distance > (30 * (i + 1))) {
      leds[i].on();
    } else {
      leds[i].off();
    }
  }

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
}
