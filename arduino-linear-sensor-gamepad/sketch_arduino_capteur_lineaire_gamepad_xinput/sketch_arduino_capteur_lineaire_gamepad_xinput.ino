/*
  Angular sensor + XInput (Gamepad)
  Language: Wiring/Arduino
  Board: Leonardo
*/

#include <XInput.h>

// XInput Config Settings
const unsigned long CycleTime = 5000;  // ms

// XInput : Joystick Setup
const int JoyMax = 32767;  // int16_t max
const double angle_precision = (2 * PI) / (CycleTime / 4);  // 4 because 250 Hz update rate

// Linear Sensor Arduino analog input 
int linearSensorID = A1;

// Linear Sensor value 
int distanceMm = 0;
float linearSensorValue = 0;

int zeroValue = 7;
int oneMeterValue = 767;
float zeroOneMeterRange = oneMeterValue - zeroValue;


void setup() {
  XInput.setAutoSend(false);
  XInput.begin();
  
  XInput.setJoystickRange(0, 1280);
}

void loop() {

  // Angular sensor data : 
  linearSensorValue = float(analogRead(linearSensorID));

  distanceMm = 1000.0 * (linearSensorValue - zeroValue) / zeroOneMeterRange;

  // Send from Arduino-gamepad to PC :
	XInput.setJoystick(JOY_LEFT, distanceMm, 0);
	XInput.send();

}
