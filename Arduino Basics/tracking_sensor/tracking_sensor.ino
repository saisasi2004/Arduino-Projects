int tpin=3;
int rpin=5;
int gpin=6;
int buzzpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(tpin,INPUT);
pinMode(rpin,OUTPUT);
pinMode(gpin,OUTPUT);
pinMode(buzzpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(tpin)==1)
{
  Serial.println("HIGH");
  digitalWrite(gpin,HIGH);
  digitalWrite(rpin,LOW);
  digitalWrite(buzzpin,LOW);
}
else
{
  Serial.println("LOW");
    digitalWrite(gpin,LOW);
  digitalWrite(rpin,HIGH);
  digitalWrite(buzzpin,HIGH);
}
}
