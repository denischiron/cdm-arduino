/*
  Sensopad capacitive analog input as gamepadButton
  Language: Wiring/Arduino
  Board: Leonardo
*/

#include <XInput.h>

int sensorValue = 0;
int sensorID = A1;

int arduinoLEDDigitalID = 13;
bool isPressed = false;

void setup() {

  XInput.setAutoSend(false);
  XInput.begin();


  // LED
  pinMode(arduinoLEDDigitalID, OUTPUT);

}


void loop() {
  
  sensorValue = analogRead(sensorID); // Integer

  if (sensorValue == 0) {

      // Détection
      digitalWrite(arduinoLEDDigitalID, HIGH);

    if (! isPressed) {
      isPressed = true;
      XInput.press(BUTTON_A);
      XInput.send();

    }

  } else {

      // No detection
      digitalWrite(arduinoLEDDigitalID, LOW);  
      
    if (isPressed) {
      isPressed = false;
      XInput.release(BUTTON_A);
      XInput.send();
    }
  }

  delay(500);
          
}