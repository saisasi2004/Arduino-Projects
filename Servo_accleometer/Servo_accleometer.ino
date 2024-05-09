#include<Servo.h>
#include <Wire.h>

Servo S;

int ADXL345 = 0x53;
int X_out, Y_out, Z_out;
int servopin=3;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D); //talk to POWER_CTL Register - 0x2D
  
  Wire.write(8); // Bit D3 High for measuring enable (8dec -> 0000 1000 binary)
  Wire.endTransmission();
  delay(10);

  S.attach(servopin);
  
}

void loop() {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);

  X_out = ( Wire.read() | Wire.read() << 8);
  Y_out = ( Wire.read() | Wire.read() << 8);
  Z_out = ( Wire.read() | Wire.read() << 8);


  Serial.print("X-axis: ");
  Serial.print(X_out);
  Serial.print("    ");
  Serial.print("Y-axis: ");
  Serial.print(Y_out);
  Serial.print("    ");
  Serial.print("Z-axis: ");
  Serial.println(Z_out);
  delay(100);

int angle=map(X_out,-255,255,0,180);
S.write(angle);
  
}
