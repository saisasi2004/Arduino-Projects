int gaspin=A0;
int buzzpin=13;
void setup() {
  // put your setup code here, to run once:
pinMode(gaspin,INPUT);
pinMode(buzzpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int gasval=analogRead(gaspin);
if(gasval>=350)
{
  digitalWrite(buzzpin,HIGH);
}
else
{
  
  digitalWrite(buzzpin,LOW);
}
Serial.println(gasval);
} 
