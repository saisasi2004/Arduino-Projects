int apin=13;
int bpin=12;
int cpin=11;
int dpin=10;
int epin=9;
int fpin=8;
int gpin=7;
int ppin=6;

void setup() {
  // put your setup code here, to run once:
pinMode(apin,OUTPUT);
pinMode(bpin,OUTPUT);
pinMode(cpin,OUTPUT);
pinMode(dpin,OUTPUT);
pinMode(epin,OUTPUT);
pinMode(fpin,OUTPUT);
pinMode(gpin,OUTPUT);
pinMode(ppin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,HIGH);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,LOW);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,LOW);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,LOW);
digitalWrite(epin,LOW);
digitalWrite(fpin,LOW);
digitalWrite(gpin,LOW);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,LOW);
digitalWrite(dpin,HIGH);
digitalWrite(epin,HIGH);
digitalWrite(fpin,LOW);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,LOW);
digitalWrite(fpin,LOW);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,LOW);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,LOW);
digitalWrite(epin,LOW);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,LOW);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,LOW);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,LOW);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,HIGH);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,LOW);
digitalWrite(epin,LOW);
digitalWrite(fpin,LOW);
digitalWrite(gpin,LOW);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,HIGH);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,HIGH);
digitalWrite(bpin,HIGH);
digitalWrite(cpin,HIGH);
digitalWrite(dpin,HIGH);
digitalWrite(epin,LOW);
digitalWrite(fpin,HIGH);
digitalWrite(gpin,HIGH);
digitalWrite(ppin,LOW);
delay(1000);

digitalWrite(apin,LOW);
digitalWrite(bpin,LOW);
digitalWrite(cpin,LOW);
digitalWrite(dpin,LOW);
digitalWrite(epin,LOW);
digitalWrite(fpin,LOW);
digitalWrite(gpin,LOW);
digitalWrite(ppin,HIGH);
delay(1000);
}
