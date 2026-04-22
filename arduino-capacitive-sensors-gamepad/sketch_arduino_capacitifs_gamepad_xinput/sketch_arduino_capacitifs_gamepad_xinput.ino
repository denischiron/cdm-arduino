/*
  Sensopad capacitive analog input as gamepadButton
  Language: Wiring/Arduino
  Board: Leonardo
*/

#include <XInput.h>
#include "Sensor.h"

/*
Sensor sensor1(2, BUTTON_Y);
Sensor sensor2(3, BUTTON_Y);
Sensor sensor3(4, BUTTON_Y);
Sensor sensor4(5, BUTTON_Y);
Sensor sensor5(6, BUTTON_Y);
*/

Sensor sensor1(2, BUTTON_Y);
Sensor sensor2(3, BUTTON_B);
Sensor sensor3(4, BUTTON_A);
Sensor sensor4(5, BUTTON_X);
Sensor sensor5(6, DPAD_UP);


void setup() {
  XInput.begin();
}


void loop() {
  
  sensor1.update();  
  sensor2.update();
  sensor3.update();
  sensor4.update();
  sensor5.update();

  delay(100);
          
}
