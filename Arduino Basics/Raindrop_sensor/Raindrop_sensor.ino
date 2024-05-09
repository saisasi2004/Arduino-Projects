int rpin=A0;
int buzzpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(rpin,INPUT);
pinMode(buzzpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(rpin);
Serial.println(val);

if(val<550)
{
  digitalWrite(buzzpin,HIGH);
}
else
{
  digitalWrite(buzzpin,LOW);
}
}
