#include <Arduino.h>
#include "Led.h"
#include "UltrasonicSensor.h"
#include "Microcontroller.h"
#include "UnitTest.h"
//definicion de ON y OFF
#define ON HIGH
#define OFF LOW

// iniciar pruebas unitarias
void Test(){
    UnitTest unitetest;
    unitetest.testLedOn();
    unitetest.testLedOff();
    unitetest.testLedToggle();
    unitetest.testLedInitialState();
    unitetest.testUltrasonicSensorClose();
    unitetest.testUltrasonicSensorFar();
    unitetest.testMicrocontrollerObjectClose();
    unitetest.testMicrocontrollerObjectFar();
    unitetest.testMicrocontrollerObjectAtLimit();
    unitetest.testLedToggleMultipleTimes();
}
// Definiciones de pines
#define TRIGGER_PIN 12
#define ECHO_PIN 13

// Instancias de los LEDs y sensor
Led led1(23);
Led led2(22);
Led led3(21);
Led leds[] = {led1, led2, led3};

UltrasonicSensor sensor(TRIGGER_PIN, ECHO_PIN);

// Instancia del controlador de LEDs
Microcontroller controller(leds, 3, sensor);

void setup() 
{
  Serial.begin(115200);
  Test();
}

void loop() 
{
  controller.updateLeds();
  delay(10);
}
