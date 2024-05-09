#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

int rpin=5;
int gpin=6;
int buzzpin=3;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte accessUID[4]={0xA4 ,0x69, 0x53, 0x64};

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  pinMode(gpin,OUTPUT);
  
  pinMode(rpin,OUTPUT);
  
  pinMode(buzzpin,OUTPUT);
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  if(mfrc522.uid.uidByte[0]==accessUID[0] && mfrc522.uid.uidByte[1]==accessUID[1] && mfrc522.uid.uidByte[2]==accessUID[2] && mfrc522.uid.uidByte[3]==accessUID[3]){
    digitalWrite(gpin,HIGH);
    delay(1000);
    digitalWrite(gpin,LOW);

    digitalWrite(buzzpin,HIGH);
    delay(100);
    digitalWrite(buzzpin,LOW);
  }
  else
  {
    digitalWrite(rpin,HIGH);
    delay(1000);
    digitalWrite(rpin,LOW);

    digitalWrite(buzzpin,HIGH);
    delay(5000);
    digitalWrite(buzzpin,LOW);
  }
mfrc522.PICC_HaltA();
}
