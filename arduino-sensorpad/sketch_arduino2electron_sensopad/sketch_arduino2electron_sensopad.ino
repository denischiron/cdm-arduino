/*
  Sensopad capacitive analog input (turns on board internal LED)
  Language: Wiring/Arduino
  Model : UNO
*/

int sensorValue = 0;
int sensorID = A1;
int arduinoLEDDigitalID = 13;

void setup() {
  
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // LED
  pinMode(arduinoLEDDigitalID, OUTPUT);

}

void loop() {
  
  sensorValue = analogRead(sensorID);
  Serial.println(sensorValue);

  if (sensorValue == 0) {
    digitalWrite(arduinoLEDDigitalID, HIGH);  
  } else {
    digitalWrite(arduinoLEDDigitalID, LOW);  
  }

  delay(500);          
}
