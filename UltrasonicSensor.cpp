#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(unsigned char triggerPin, unsigned char echoPin) 
  : triggerPin(triggerPin), echoPin(echoPin) {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::getDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
