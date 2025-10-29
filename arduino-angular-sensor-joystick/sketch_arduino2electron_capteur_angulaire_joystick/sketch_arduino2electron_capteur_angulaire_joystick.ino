/*
  Angular sensor + Joystick
  Language: Wiring/Arduino
  Board : Leonardo
*/

#include "Joystick.h"

// Angular Sensor Arduino analog input 
int angularSensorID = A1;

// Angular Sensor value 
int angularSensorValue = 0;
int angleValue = 0;
int prevAngleValue = 0;

void setup() {
  Joystick.begin(false);
}

void loop() {

  // Angular sensor data : 
  angularSensorValue = analogRead(angularSensorID);
  angleValue = map(angularSensorValue, 99, 920, 0, 360) ;

  int diffValue = angleValue - prevAngleValue;

  if (diffValue >  180) diffValue -= 360;
  if (diffValue < -180) diffValue += 360;
    
  if (diffValue != 0) {
 
    /* Send angle value  as a Joystick */
    Joystick.setXAxisRotation(angleValue);
    Joystick.sendState();

    prevAngleValue = angleValue;
  }
  
  delay(100);
}
