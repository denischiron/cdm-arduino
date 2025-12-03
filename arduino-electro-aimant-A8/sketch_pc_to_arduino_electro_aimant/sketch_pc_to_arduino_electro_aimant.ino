/*
  Serial Call and Response in ASCII
  Language: Wiring/Arduino
*/

// Les relais sont connectés au entrées Arduino : D2, D3, D4, D5, D6

int firstRelayDigitalID = 2;
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
  pinMode(firstRelayDigitalID, OUTPUT);
  pinMode(firstRelayDigitalID + 1, OUTPUT);
  pinMode(firstRelayDigitalID + 2, OUTPUT);
  pinMode(firstRelayDigitalID + 3, OUTPUT);
  pinMode(firstRelayDigitalID + 4, OUTPUT);
}

// relayDigitalID : 1 à 5
void toggleRelay(int relayDigitalID) {
  
  

  // Met sous tension le relais (l'aimant est désactivé)
  // Allume la LED
  digitalWrite(relayDigitalID, HIGH);
  digitalWrite(arduinoLEDDigitalID, HIGH);   
  
  delay (2000);
  
  // Annule tension du relais (l'aimant est réactivé)
  digitalWrite(relayDigitalID, LOW);
  digitalWrite(arduinoLEDDigitalID, LOW);
}

void loop() {

   if (Serial.available() > 0) {

    // PC => ARDUINO
    char data = Serial.read();

    // Reçoit le caractère "A" : on désactive tous les aimants
    if (data == 'A') {
      
      toggleRelay(firstRelayDigitalID);
      toggleRelay(firstRelayDigitalID + 1);
      toggleRelay(firstRelayDigitalID + 2);
      toggleRelay(firstRelayDigitalID + 3);
      toggleRelay(firstRelayDigitalID + 4);

    } else {
      
      // Reçoit un ccaractère entre "1" et "5" : on en déduit le no entre 1 et 5
      int slotNo = data - '0';

      // 1 => firstRelayDigitalID
      // 2 => firstRelayDigitalID + 1
      // 3 => firstRelayDigitalID + 2
      // 4 => firstRelayDigitalID + 3
      // 5 => firstRelayDigitalID + 4
      toggleRelay(firstRelayDigitalID - 1 + slotNo);

    }
  }
  
  delay(100);          
}
