// Sensor.cpp
#include "Sensor.h"
#include <XInput.h>

Sensor::Sensor(int pin, int buttonId) {
  sensorPin   = pin;
  sensorValue = 0;
  gamepadButton = buttonId;

  pinMode(pin, INPUT_PULLUP);
}

void Sensor::update() {

  sensorValue = digitalRead(sensorPin); // Integer

   if (sensorValue == 1) {
    XInput.press(gamepadButton);
  } else {
    XInput.release(gamepadButton);
  }
}