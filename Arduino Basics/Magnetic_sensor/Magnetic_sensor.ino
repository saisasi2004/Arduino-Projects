int mpin=2;
int buzzpin=13;

void setup() {
  // put your setup code here, to run once:
pinMode(mpin,INPUT);
pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(mpin)==0)
{
  digitalWrite(buzzpin,HIGH);
}
else
{
  digitalWrite(buzzpin,LOW);
}
}
