#include "UnitTest.h"
#include <Arduino.h>

void UnitTest::testLedOn() {
    Led led(13);
    led.on();
    if (led.isOn()) {
        Serial.println("Test Led On: PASSED");
    } else {
        Serial.println("Test Led On: FAILED");
    }
}

void UnitTest::testLedOff() {
    Led led(13);
    led.off();
    if (!led.isOn()) {
        Serial.println("Test Led Off: PASSED");
    } else {
        Serial.println("Test Led Off: FAILED");
    }
}

void UnitTest::testLedToggle() {
    Led led(13);
    led.toggle();
    if (led.isOn()) {
        Serial.println("Test Led Toggle: PASSED");
    } else {
        Serial.println("Test Led Toggle: FAILED");
    }
}

void UnitTest::testLedInitialState() {
    Led led(13);
    if (!led.isOn()) {
        Serial.println("Test Led Initial State: PASSED");
    } else {
        Serial.println("Test Led Initial State: FAILED");
    }
}

void UnitTest::testUltrasonicSensorClose() {
    UltrasonicSensor sensor(9, 10); // Pines arbitrarios
    float distance = sensor.getDistance();
    if (distance < 20.0) {
        Serial.println("Test Ultrasonic Sensor Close: PASSED");
    } else {
        Serial.println("Test Ultrasonic Sensor Close: FAILED");
    }
}

void UnitTest::testUltrasonicSensorFar() {
    UltrasonicSensor sensor(9, 10); // Pines arbitrarios
    float distance = sensor.getDistance();
    if (distance > 100.0) {
        Serial.println("Test Ultrasonic Sensor Far: PASSED");
    } else {
        Serial.println("Test Ultrasonic Sensor Far: FAILED");
    }
}

void UnitTest::testMicrocontrollerObjectClose() {
    Led leds[] = {Led(13), Led(12)};
    UltrasonicSensor sensor(9, 10);
    Microcontroller mc(leds, 2, sensor);

    mc.updateLeds();
    if (leds[0].isOn() && leds[1].isOn()) {
        Serial.println("Test Microcontroller Object Close: PASSED");
    } else {
        Serial.println("Test Microcontroller Object Close: FAILED");
    }
}

void UnitTest::testMicrocontrollerObjectFar() {
    Led leds[] = {Led(13), Led(12)};
    UltrasonicSensor sensor(9, 10);
    Microcontroller mc(leds, 2, sensor);

    mc.updateLeds();
    if (!leds[0].isOn() && !leds[1].isOn()) {
        Serial.println("Test Microcontroller Object Far: PASSED");
    } else {
        Serial.println("Test Microcontroller Object Far: FAILED");
    }
}

void UnitTest::testMicrocontrollerObjectAtLimit() {
    Led leds[] = {Led(13), Led(12)};
    UltrasonicSensor sensor(9, 10);
    Microcontroller mc(leds, 2, sensor);

    mc.updateLeds();
    if (leds[0].isOn() && !leds[1].isOn()) {
        Serial.println("Test Microcontroller Object At Limit: PASSED");
    } else {
        Serial.println("Test Microcontroller Object At Limit: FAILED");
    }
}

void UnitTest::testLedToggleMultipleTimes() {
    Led led(13);
    bool initialState = led.isOn();

    for (int i = 0; i < 10; i++) {
        led.toggle();
    }

    if (led.isOn() == initialState) {
        Serial.println("Test Led Toggle Multiple Times: PASSED");
    } else {
        Serial.println("Test Led Toggle Multiple Times: FAILED");
    }
}
