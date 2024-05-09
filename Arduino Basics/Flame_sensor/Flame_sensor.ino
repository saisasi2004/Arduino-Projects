int fpin=3;
int buzzpin=13;
int flame=HIGH;
void setup() {
  // put your setup code here, to run once:
pinMode(fpin,INPUT);
pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
flame=digitalRead(fpin);
if(flame==LOW)
{
  digitalWrite(buzzpin,HIGH);
}
else
{
   digitalWrite(buzzpin,LOW);
}
}
