void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int moivalue=analogRead(A0);
Serial.println(moivalue);
 if(moivalue>=500)
 {
  digitalWrite(13,HIGH);
 }
}
