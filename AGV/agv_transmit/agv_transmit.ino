#include <WiFi.h>

const char *ssid = "Sai SasivardhaN";
const char *password = "Saisasi2004";
const char *robotIPAddress = "192.168.147.1"; // Replace with the IP address of your robot

struct JoystickData {
  int xAxis;
  int yAxis;
};

JoystickData joystickData;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

}

void loop() {
  // Read the joystick inputs
  joystickData.xAxis = analogRead(A0);
  joystickData.yAxis = analogRead(A1);

  // Send the joystick data to the robot
  sendJoystickData(joystickData);

  // Print the joystick data for debugging
  Serial.print("X: ");
  Serial.print(joystickData.xAxis);
  Serial.print("\tY: ");
  Serial.println(joystickData.yAxis);

  delay(50); // Adjust the delay based on your requirements
}

void sendJoystickData(JoystickData data) {
  WiFiClient client;
  
  if (client.connect(robotIPAddress, 80)) {
    // Create a JSON-like string to send the data
    String payload = "{\"xAxis\": " + String(data.xAxis) + ", \"yAxis\": " + String(data.yAxis) + "}";
    
    // Send HTTP POST request with the payload
    client.println("POST /update HTTP/1.1");
    client.println("Host: " + String(robotIPAddress));
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(payload.length()));
    client.println();
    client.print(payload);

    delay(10);

    Serial.println("Data sent to the robot");
  } else {
    Serial.println("Connection to robot failed");
  }

  client.stop();
}
