#include<Servo.h>
Servo S1;
Servo S2;
int xpin=A0;
int ypin=A1;
int spin=2;
int servopin1=3;
int servopin2=5;
int lpin=6;
void setup() {
  // put your setup code here, to run once:
pinMode(xpin,INPUT);
pinMode(ypin,INPUT);
pinMode(spin,INPUT);
digitalWrite(spin,HIGH);
pinMode(lpin,OUTPUT);
Serial.begin(9600);
S1.attach(servopin1);
S2.attach(servopin2);
}

void loop() {
  // put your main code here, to run repeatedly:
int xval=analogRead(xpin);
int yval=analogRead(ypin);
int sval=digitalRead(spin);
Serial.print(" X value =  ");
Serial.print(xval);
Serial.print(" y value =  ");
Serial.print(yval);
Serial.print(" S value =  ");
Serial.println(sval);

int angle1=map(xval, 0, 1023, 0, 180);
S1.write(angle1);

int angle2=map(yval, 0, 1023, 0, 180);
S2.write(angle2);

if(sval==0)
{
  digitalWrite(lpin,HIGH);
}
else
{
  digitalWrite(lpin,LOW);
}
}
