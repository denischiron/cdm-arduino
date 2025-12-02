/*
  Serial Call and Response in ASCII
  Language: Wiring/Arduino
*/

int relayDigitalID = 4;
int arduinoLEDDigitalID = 13;

void setup() {
  
  // start serial port at 115200 bps and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // LED
  pinMode(arduinoLEDDigitalID, OUTPUT);

  // RELAIS
  // pinMode(relayDigitalID, OUTPUT);
}

void toggleRelay(int duration) {
  
  // Met sous tension le relais (l'aimant est désactivé)
  // Allume la LED
  // digitalWrite(relayDigitalID, HIGH);
  digitalWrite(arduinoLEDDigitalID, HIGH);   
  
  delay (duration);
  
  // Annule tension du relais (l'aimant est réactivé)
  // digitalWrite(relayDigitalID, LOW);
  digitalWrite(arduinoLEDDigitalID, LOW);
}

void loop() {

   if (Serial.available() > 0) {
    // PC => ARDUINO
    char data = Serial.read();
    if (data == 'A') {
      toggleRelay(1000);
    } else {
      int slotNo = data - '0';
      toggleRelay(slotNo * 200);
    }
  }
  
  delay(100);          
}
