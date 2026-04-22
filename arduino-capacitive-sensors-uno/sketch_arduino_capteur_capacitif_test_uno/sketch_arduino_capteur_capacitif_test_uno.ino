/*
  Test 
  Language: Wiring/Arduino
*/


int digitalSensorID1 = 2;
int digitalSensorID2 = 3;
int digitalSensorID3 = 4;
int digitalSensorID4 = 5;
int digitalSensorID5 = 6;


void setup() {

  pinMode(digitalSensorID1, INPUT_PULLUP);
  pinMode(digitalSensorID2, INPUT_PULLUP);
  pinMode(digitalSensorID3, INPUT_PULLUP);
  pinMode(digitalSensorID4, INPUT_PULLUP);
  pinMode(digitalSensorID5, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {

  if (digitalRead(digitalSensorID1) == HIGH) {
    Serial.println("sensor1");
  }

  if (digitalRead(digitalSensorID2) == HIGH) {
    Serial.println("sensor2");
  }

  if (digitalRead(digitalSensorID3) == HIGH) {
    Serial.println("sensor3");
  }

  if (digitalRead(digitalSensorID4) == HIGH) {
    Serial.println("sensor4");
  }

  if (digitalRead(digitalSensorID5) == HIGH) {
    Serial.println("sensor5");
  }

  delay(100);
}
