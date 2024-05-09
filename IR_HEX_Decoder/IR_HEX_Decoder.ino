#include <IRremote.h>

IRrecv IR(11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData,HEX);
    IR.resume();
}
}
