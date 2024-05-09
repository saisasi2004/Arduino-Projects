#include <Wire.h>

#define SLAVE_ADDRESS 9 // Address of the slave Arduino
#define DATA_SIZE 5      // Size of the data array

byte sensorData[DATA_SIZE]; // Array to store sensor data

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS); // Initialize I2C communication as slave
  Wire.onRequest(sendData);  // Register the onRequest event
  randomSeed(analogRead(0)); // Seed the random number generator
  generateRandomData();      // Generate random sensor data
}

void loop() {
  // Do nothing in the loop, the data is sent only when requested by master
}

void sendData() {
  Wire.write(sensorData, DATA_SIZE); // Send the data to the master Arduino
}

void generateRandomData() {
  for (int i = 0; i < DATA_SIZE; i++) {
    sensorData[i] = random(255); // Generate random data between 0 and 255
    Serial.println(sensorData[i]);
  }
}
