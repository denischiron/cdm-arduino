/*
  Serial message turns on the board internal LED
  Language: Wiring/Arduino
*/

int arduinoLEDDigitalID = 13;

void setup() {
  
  // start serial port at 115200 bps and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // LED
  pinMode(arduinoLEDDigitalID, OUTPUT);
}

void toggleLED(int duration) {
  
  // Allume la LED
  digitalWrite(arduinoLEDDigitalID, HIGH);   
  
  delay (duration);

  // Eteint la LED  
  digitalWrite(arduinoLEDDigitalID, LOW);
}

void loop() {

   if (Serial.available() > 0) {
    // PC => ARDUINO
    char data = Serial.read();
    if (data == 'A') {
      toggleLED(1000);
    } else {
      int slotNo = data - '0';
      toggleLED(slotNo * 200);
    }
  }
  
  delay(100);          
}
