int buzzpin=13;
int infrapin=3;
void setup() {
  // put your setup code here, to run once:
pinMode(infrapin,LOW);
pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(infrapin)==HIGH)
{
  digitalWrite(buzzpin,LOW);
}
else
{
  digitalWrite(buzzpin,HIGH);
}
}
