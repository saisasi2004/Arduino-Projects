#include <IRremote.h>
int LED_P=9;
IRrecv IR(11);
void setup(){
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(LED_P,OUTPUT);
}

void loop(){
   if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData,HEX);
    if(IR.decodedIRData.decodedRawData==0xE718FF00)
    {
      digitalWrite(LED_P,HIGH);
    }
if(IR.decodedIRData.decodedRawData==0xAD52FF00)
    {
      digitalWrite(LED_P,LOW);
    }    
    delay(1500);
    IR.resume();
   }
  
}
