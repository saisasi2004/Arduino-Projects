#include <WiFi.h>

WiFiUDP udp;
char* ssid = "Sai Sasivardhan";
char* password = "Saisasi2004";
const int localPort = 12345; // Same port as used in transmitter

// Define motor pins
const int MOTOR_1_PIN_1 = 5;
const int MOTOR_1_PIN_2 = 6;
const int MOTOR_2_PIN_1 = 9;
const int MOTOR_2_PIN_2 = 10;
const int MOTOR_3_PIN_1 = 11;
const int MOTOR_3_PIN_2 = 12;
const int MOTOR_4_PIN_1 = 13;
const int MOTOR_4_PIN_2 = 14;

void setup() {
  Serial.begin(115200);
  pinMode(MOTOR_1_PIN_1, OUTPUT);
  pinMode(MOTOR_1_PIN_2, OUTPUT);
  pinMode(MOTOR_2_PIN_1, OUTPUT);
  pinMode(MOTOR_2_PIN_2, OUTPUT);
  pinMode(MOTOR_3_PIN_1, OUTPUT);
  pinMode(MOTOR_3_PIN_2, OUTPUT);
  pinMode(MOTOR_4_PIN_1, OUTPUT);
  pinMode(MOTOR_4_PIN_2, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    udp.begin(localPort);
  } else {
    Serial.println("Failed to connect to WiFi. Check your credentials or restart the ESP32.");
  }
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char packetData[packetSize];
    udp.read(packetData, packetSize);

    String receivedData = String(packetData);
    int pos = receivedData.indexOf(',');
    if (pos != -1) {
      String xValue = receivedData.substring(0, pos);
      String yValue = receivedData.substring(pos + 1);

      int motorSpeedX = map(xValue.toInt(), 0, 1023, -255, 255);
      int motorSpeedY = map(yValue.toInt(), 0, 1023, -255, 255);

      Serial.println(motorSpeedX);
      Serial.println(motorSpeedY);

       if (motorSpeedY > 0) {
        digitalWrite(MOTOR_1_PIN_1, HIGH);
        digitalWrite(MOTOR_1_PIN_2, 0);
        analogWrite(MOTOR_2_PIN_1, abs(motorSpeedY));
        analogWrite(MOTOR_2_PIN_2, 0);
      } else if (motorSpeedY < 0) {
        digitalWrite(MOTOR_1_PIN_1, 0);
        analogWrite(MOTOR_1_PIN_2, abs(motorSpeedY));
        digitalWrite(MOTOR_2_PIN_1, 0);
        analogWrite(MOTOR_2_PIN_2, abs(motorSpeedY));
      } else {
        digitalWrite(MOTOR_1_PIN_1, LOW);
        digitalWrite(MOTOR_1_PIN_2, LOW);
        digitalWrite(MOTOR_2_PIN_1, LOW);
        digitalWrite(MOTOR_2_PIN_2, LOW);
      }

      // Motor 3 and Motor 4 control
      if (motorSpeedX > 0) {
        digitalWrite(MOTOR_3_PIN_1, HIGH);
        digitalWrite(MOTOR_3_PIN_2, 0);
        analogWrite(MOTOR_4_PIN_1, abs(motorSpeedX));
        analogWrite(MOTOR_4_PIN_2, 0);
      } else if (motorSpeedX < 0) {
        digitalWrite(MOTOR_3_PIN_1, 0);
        analogWrite(MOTOR_3_PIN_2, abs(motorSpeedX));
        digitalWrite(MOTOR_4_PIN_1, 0);
        analogWrite(MOTOR_4_PIN_2, abs(motorSpeedX));
      } else {
        digitalWrite(MOTOR_3_PIN_1, LOW);
        digitalWrite(MOTOR_3_PIN_2, LOW);
        digitalWrite(MOTOR_4_PIN_1, LOW);
        digitalWrite(MOTOR_4_PIN_2, LOW);
      }
      
    }
  }
}
