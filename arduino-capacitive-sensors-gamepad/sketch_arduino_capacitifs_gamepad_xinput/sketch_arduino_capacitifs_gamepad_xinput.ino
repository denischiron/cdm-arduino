/*
  Sensopad capacitive analog input as gamepadButton
  Language: Wiring/Arduino
  Board: Leonardo
*/

#include <XInput.h>
#include "Sensor.h"

/*
Sensor sensor1(3, BUTTON_Y);
Sensor sensor2(4, BUTTON_Y);
Sensor sensor3(5, BUTTON_Y);
Sensor sensor4(6, BUTTON_Y);
Sensor sensor5(7, BUTTON_Y);
*/

Sensor sensor1(3, BUTTON_Y);
Sensor sensor2(4, BUTTON_B);
Sensor sensor3(5, BUTTON_A);
Sensor sensor4(6, BUTTON_X);
Sensor sensor5(7, DPAD_UP);


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
