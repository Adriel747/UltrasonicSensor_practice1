#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  private:
    const unsigned char OFF = 0;
    const unsigned char ON = 1;

    unsigned char pin;
    unsigned char state;

  public:
    Led(unsigned char pin);
    void off();
    void on();
    void toggle();
    bool isOn() const;
};

#endif
