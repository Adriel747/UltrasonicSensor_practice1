#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
  private:
    unsigned char triggerPin;
    unsigned char echoPin;

  public:
    UltrasonicSensor(unsigned char triggerPin, unsigned char echoPin);
    float getDistance();
};

#endif
