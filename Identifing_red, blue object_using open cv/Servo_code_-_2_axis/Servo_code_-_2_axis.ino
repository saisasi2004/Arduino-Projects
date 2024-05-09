#include <Servo.h>

Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(9600);
  servoX.attach(9);  // Connect servo to pin 9
  servoY.attach(10); // Connect servo to pin 10
}

void loop() {
  if (Serial.available() > 0) {
    int posX = Serial.parseInt();
    int posY = Serial.parseInt();

    if (posX >= 0 && posX <= 180 && posY >= 0 && posY <= 180) {
      Serial.print(posX);
      Serial.print(posY);
      servoX.write(posX);
      servoY.write(posY);
    }
  }
}
