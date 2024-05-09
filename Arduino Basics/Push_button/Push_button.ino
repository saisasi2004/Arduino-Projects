int buttonpin=3;
int ledpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonpin,INPUT);
digitalWrite(buttonpin,HIGH);
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(buttonpin);
Serial.println(val);
if(val==0)
{
  digitalWrite(ledpin,HIGH);
}
else
{
  digitalWrite(ledpin,LOW);
}
}
