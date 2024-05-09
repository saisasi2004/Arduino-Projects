int ldrpin=A0;
int buzzpin=13;
int ldrval;
void setup() {
  // put your setup code here, to run once:
pinMode(ldrpin,INPUT);
pinMode(buzzpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ldrval=analogRead(ldrpin);
if(ldrval<=40)
{
  digitalWrite(buzzpin,LOW);
}
else 
{
  digitalWrite(buzzpin,HIGH);
}
Serial.println(ldrval);
}
