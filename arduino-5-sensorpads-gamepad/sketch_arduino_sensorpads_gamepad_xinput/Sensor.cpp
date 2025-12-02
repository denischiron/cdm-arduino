// Sensor.cpp
#include "Sensor.h"
#include <XInput.h>

Sensor::Sensor(int pin, int buttonId) {
  sensorPin   = pin;
  sensorValue = 0;
  isPressed = false;
  gamepadButton = buttonId;
}

void Sensor::update() {

  sensorValue = analogRead(sensorPin); // Integer

   if (sensorValue == 0) {
    // Detection

    if (! isPressed) {
      isPressed = true;
      XInput.press(gamepadButton);

    }

  } else {
      // No detection

    if (isPressed) {
      isPressed = false;
      XInput.release(gamepadButton);
    }
  }
}