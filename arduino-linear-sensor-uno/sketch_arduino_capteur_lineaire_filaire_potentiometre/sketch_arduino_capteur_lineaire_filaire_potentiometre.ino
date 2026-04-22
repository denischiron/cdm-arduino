/*
  Linear sensor SP1
  Language: Wiring/Arduino
*/


float linearSensorValue = 0;
int linearSensorID = A1;

float distanceCm = 0;

int zeroValue = 7;
int oneMeterValue = 767;
float zeroOneMeterRange = oneMeterValue - zeroValue;

void setup() {
  Serial.begin(9600);
}

void loop() {

  linearSensorValue = float(analogRead(linearSensorID));

  distanceCm = 100.0 * (linearSensorValue - zeroValue) / zeroOneMeterRange;

  Serial.println(distanceCm);

  delay(100);
}
