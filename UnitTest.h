#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "Led.h"
#include "UltrasonicSensor.h"
#include "Microcontroller.h"

class UnitTest {
public:
    UnitTest() {}
    void testLedOn();
    void testLedOff();
    void testLedToggle();
    void testLedInitialState();
    void testUltrasonicSensorClose();
    void testUltrasonicSensorFar();
    void testMicrocontrollerObjectClose();
    void testMicrocontrollerObjectFar();
    void testMicrocontrollerObjectAtLimit();
    void testLedToggleMultipleTimes();
};

#endif
