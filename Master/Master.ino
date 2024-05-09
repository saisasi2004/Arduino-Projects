#include <Wire.h>

#define SLAVE_ADDRESS 9 // Address of the slave Arduino

void setup() {
  Serial.begin(9600);
  Wire.begin(); // Initialize I2C communication
}

void loop() {
  Wire.requestFrom(SLAVE_ADDRESS, 1); // Request 1 byte from slave Arduino

  while (Wire.available()) {
    char data = Wire.read(); // Read the data sent by slave Arduino
    Serial.println(data);    // Print received data
  }

  delay(1000); // Wait for a second before requesting data again
}
