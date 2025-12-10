/*
  Sensopad capacitive analog input as gamepadButton
  Language: Wiring/Arduino
  Board: Leonardo
*/

#include <XInput.h>
#include "Sensor.h"

Sensor sensorA1(A1, BUTTON_Y);
Sensor sensorA2(A2, BUTTON_Y);
Sensor sensorA3(A3, BUTTON_Y);
Sensor sensorA4(A4, BUTTON_Y);
Sensor sensorA5(A5, BUTTON_Y);

/*
Sensor sensorA1(A1, BUTTON_Y);
Sensor sensorA2(A2, BUTTON_B);
Sensor sensorA3(A3, BUTTON_A);
Sensor sensorA4(A4, BUTTON_X);
Sensor sensorA5(A5, DPAD_UP);
*/

void setup() {
  XInput.begin();
}


void loop() {
  
  sensorA1.update();
  sensorA2.update();
  sensorA3.update();
  sensorA4.update();
  sensorA5.update();

  delay(100);
          
}
