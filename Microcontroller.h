#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include "Led.h"
#include "UltrasonicSensor.h"

//ledController
class Microcontroller
 {
  private:
    Led* leds;
    int numLeds;
    UltrasonicSensor& sensor;

  public:
    Microcontroller(Led* leds, int numLeds, UltrasonicSensor& sensor);
    void updateLeds();
};

#endif
