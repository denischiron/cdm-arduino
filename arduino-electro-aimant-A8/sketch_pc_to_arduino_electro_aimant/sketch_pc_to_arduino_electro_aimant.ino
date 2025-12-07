/*
  Serial Call and Response in ASCII
  Language: Wiring/Arduino
*/

// Les relais sont connectés au entrées Arduino : D2, D3, D4, D5, D6

int firstRelayDigitalID = 2;
int arduinoLEDDigitalID = 13;
int onOffDelay = 100;


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
void toggleRelay(int relayDigitalID, bool state) {  
  digitalWrite(relayDigitalID, state);
  digitalWrite(arduinoLEDDigitalID, state);   
}

void loop() {

   if (Serial.available() > 0) {

    // PC => ARDUINO
    char data = Serial.read();

    // Reçoit le caractère "B" : on désactive tous les aimants
    if (data == 'B') {

      toggleRelay(firstRelayDigitalID, HIGH);
      toggleRelay(firstRelayDigitalID + 1, HIGH);
      toggleRelay(firstRelayDigitalID + 2, HIGH);
      toggleRelay(firstRelayDigitalID + 3, HIGH);
      toggleRelay(firstRelayDigitalID + 4, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID, LOW);
      toggleRelay(firstRelayDigitalID + 1, LOW);
      toggleRelay(firstRelayDigitalID + 2, LOW);
      toggleRelay(firstRelayDigitalID + 3, LOW);
      toggleRelay(firstRelayDigitalID + 4, LOW);

    } else  if (data == 'A') {

     // Reçoit le caractère "B" : on désactive tous les aimants en cascade, l'un après l'autre
      toggleRelay(firstRelayDigitalID, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID, LOW);

      delay(onOffDelay);

      toggleRelay(firstRelayDigitalID + 1, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID + 1, LOW);

      delay(onOffDelay);

      toggleRelay(firstRelayDigitalID + 2, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID + 2, LOW);

      delay(onOffDelay);

      toggleRelay(firstRelayDigitalID + 3, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID + 3, LOW);

      delay(onOffDelay);

      toggleRelay(firstRelayDigitalID + 4, HIGH);
      delay(onOffDelay);
      toggleRelay(firstRelayDigitalID + 4, LOW);

    } else {
      
      // Reçoit un ccaractère entre "1" et "5" : on en déduit le no entre 1 et 5
      int slotNo = data - '0';
      int relayDigitalID = firstRelayDigitalID - 1 + slotNo;

      // 1 => firstRelayDigitalID
      // 2 => firstRelayDigitalID + 1
      // 3 => firstRelayDigitalID + 2
      // 4 => firstRelayDigitalID + 3
      // 5 => firstRelayDigitalID + 4
      toggleRelay(relayDigitalID, HIGH);

      delay(onOffDelay);

      toggleRelay(relayDigitalID, LOW);

    }
  }

  delay(100);          
}
