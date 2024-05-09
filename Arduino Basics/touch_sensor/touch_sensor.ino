int touchpin=3;
int lpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(touchpin,INPUT);
pinMode(lpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(touchpin);
Serial.println(val);
if(val==1)
{
  digitalWrite(lpin,HIGH);
}
else
{
  digitalWrite(lpin,LOW);
}
}
