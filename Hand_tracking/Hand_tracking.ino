const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;
const int ledPin4 = 11;
const int ledPin5 = 12;

int fingerStates[5] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the finger states from the serial port
    String fingerStatesString = Serial.readStringUntil('\n');

    // Split the string into an array of integers
    int index = 0;
    for (int i = 0; i < fingerStatesString.length(); i++) {
      if (fingerStatesString.charAt(i) == ',') {
        fingerStates[index++] = fingerStatesString.substring(i - 1, i).toInt();
      }
    }

    // Call the led function based on finger states
    led(fingerStates);
  }
}

void led(int fingerUp[]) {
  if (fingerUp[0] == 0 && fingerUp[1] == 0 && fingerUp[2] == 0 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 0 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 0 && fingerUp[4] == 0) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 0) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
  } else if (fingerUp[0] == 0 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 1) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
  } else if (fingerUp[0] == 1 && fingerUp[1] == 1 && fingerUp[2] == 1 && fingerUp[3] == 1 && fingerUp[4] == 1) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
  }
}
