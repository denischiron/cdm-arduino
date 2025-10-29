/*
  Angular sensor + XInput (Gamepad)
  Language: Wiring/Arduino
*/

#include <XInput.h>

// XInput Config Settings
const unsigned long CycleTime = 5000;  // ms

// XInput : Joystick Setup
const int JoyMax = 32767;  // int16_t max
const double angle_precision = (2 * PI) / (CycleTime / 4);  // 4 because 250 Hz update rate
double angleValueInRadians = 0.0;

// Angular Sensor Arduino analog input 
int angularSensorID = A1;

// Angular Sensor value 
int angleValueInDegree = 0;
int angularSensorValue = 0;

double degreesToRadians = PI / 180.0;


void setup() {
  XInput.begin();
}

void loop() {

  // Angular sensor data : 
  angularSensorValue = analogRead(angularSensorID);
  angleValueInDegree = map(angularSensorValue, 99, 920, 0, 360); // Degrees

  // In Radians :
  angleValueInRadians = angleValueInDegree * degreesToRadians; // Radians

  // Compute angle projection on both axis 
	int axis_x = sin(angleValueInRadians) * JoyMax;
	int axis_y = cos(angleValueInRadians) * JoyMax;

  // Send axis values from Arduino-gamepad to PC :
	XInput.setJoystick(JOY_LEFT, axis_x, axis_y);  // Clockwise
	XInput.setJoystick(JOY_RIGHT, -axis_x, axis_y);  // Counter-clockwise
	XInput.send();

}
