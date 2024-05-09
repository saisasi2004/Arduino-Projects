int tiltpin=2;
int ledpin=3;
int buzzpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(tiltpin,INPUT);
pinMode(ledpin,OUTPUT);
pinMode(buzzpin,OUTPUT);
digitalWrite(tiltpin,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(tiltpin);
Serial.println(val);
if(val==0)
{
  digitalWrite(ledpin,HIGH);
  digitalWrite(buzzpin,HIGH);
  delay(1000);
}
else
{
  digitalWrite(ledpin,LOW);
  digitalWrite(buzzpin,LOW);
}
}
