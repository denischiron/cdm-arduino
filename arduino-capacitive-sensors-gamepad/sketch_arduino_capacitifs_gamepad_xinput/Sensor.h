// Sensor.h
#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>

class Sensor {
  private:
    int sensorPin;
    int sensorValue;
    bool isPressed;
    int gamepadButton;

  public:
    Sensor(int pin, int buttonId);
    void update();
};

#endif