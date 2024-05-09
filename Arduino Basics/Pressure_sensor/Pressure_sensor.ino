int prepin=A0;
int ledpin=9;
int preval;
void setup() {
  // put your setup code here, to run once:
pinMode(prepin,INPUT);
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
preval=analogRead(prepin);
preval=map(preval,0,1023,0,255);
analogWrite(ledpin,preval);
Serial.println(preval);
}
