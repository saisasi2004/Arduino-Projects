#include<Servo.h>
Servo Servo1;
int servoPin=5;
int potPin=A0;

void setup() {
  Servo1.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(potPin);
  int angle=map(reading, 0, 1023, 0, 180);
  Serial.println(angle);
Servo1.write(angle);
}
