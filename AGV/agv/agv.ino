const int X_AXIS_PIN = A0; // Analog pin for X axis
const int Y_AXIS_PIN = A1; // Analog pin for Y axis

void setup() {
  pinMode(MOTOR_1_PIN_1,OUTPUT);
  pinMode(MOTOR_1_PIN_2,OUTPUT);
  pinMode(MOTOR_2_PIN_1,OUTPUT);
  pinMode(MOTOR_2_PIN_2,OUTPUT);
  pinMode(MOTOR_3_PIN_1,OUTPUT);
  pinMode(MOTOR_3_PIN_2,OUTPUT); 
  pinMode(MOTOR_4_PIN_1,OUTPUT);
  pinMode(MOTOR_4_PIN_2,OUTPUT); 
}

void loop() {
  int xAxisValue = analogRead(X_AXIS_PIN);
  int yAxisValue = analogRead(Y_AXIS_PIN);

  int motor1Speed = map(yAxisValue, -255, 255 ,0 ,255); // Mapping Y axis for Motors 1 and 3
  int motor2Speed = map(xAxisValue, -255, 255 ,0 ,255); // Mapping X axis for Motors 2 and 4

  // Motor control based on joystick values for Mecanum wheels
  if (motor1Speed > 0) {
    analogWrite(MOTOR_2_PIN_1, abs(motor1Speed));
    digitalWrite(MOTOR_2_PIN_2, LOW);
    analogWrite(MOTOR_3_PIN_1, abs(motor1Speed));
    digitalWrite(MOTOR_3_PIN_2, LOW);

    // Forward-left diagonal movement
    if (motor2Speed > 0) {
      analogWrite(MOTOR_1_PIN_1, abs(motor2Speed));
      digitalWrite(MOTOR_1_PIN_2, LOW);
      analogWrite(MOTOR_4_PIN_1, 0);
      digitalWrite(MOTOR_4_PIN_2, LOW);
    }
    // Forward-right diagonal movement
    else if (motor2Speed < 0) {
      digitalWrite(MOTOR_1_PIN_1, LOW);
      analogWrite(MOTOR_1_PIN_2, abs(motor2Speed));
      digitalWrite(MOTOR_4_PIN_1, 0);
      analogWrite(MOTOR_4_PIN_2, abs(motor2Speed));
    }
    // Pure forward movement
    else {
      digitalWrite(MOTOR_1_PIN_1, abs(motor1Speed));
      digitalWrite(MOTOR_1_PIN_2, LOW);
      digitalWrite(MOTOR_4_PIN_1, abs(motor1Speed));
      digitalWrite(MOTOR_4_PIN_2, LOW);
    }
  } else if (motor1Speed < 0) {
    digitalWrite(MOTOR_2_PIN_1, LOW);
    analogWrite(MOTOR_2_PIN_2, abs(motor1Speed));
    digitalWrite(MOTOR_3_PIN_1, LOW);
    analogWrite(MOTOR_3_PIN_2, abs(motor1Speed));

    // Backward-left diagonal movement
    if (motor2Speed > 0) {
      digitalWrite(MOTOR_1_PIN_1, 0);
      analogWrite(MOTOR_1_PIN_2, abs(motor2Speed));
      analogWrite(MOTOR_4_PIN_1, 0);
      digitalWrite(MOTOR_4_PIN_2, LOW);
    }
    // Backward-right diagonal movement
    else if (motor2Speed < 0) {
      analogWrite(MOTOR_1_PIN_1, 0);
      digitalWrite(MOTOR_1_PIN_2, LOW);
      digitalWrite(MOTOR_4_PIN_1, 0);
      analogWrite(MOTOR_4_PIN_2, abs(motor2Speed));
    }
    // Pure backward movement
    else {
      digitalWrite(MOTOR_1_PIN_1, LOW);
      digitalWrite(MOTOR_1_PIN_2, abs(motor1Speed));
      digitalWrite(MOTOR_4_PIN_1, LOW);
      digitalWrite(MOTOR_4_PIN_2, abs(motor1Speed));
    }
  } else {
    // Pure left movement
    if (motor2Speed > 0) {
      digitalWrite(MOTOR_1_PIN_1, abs(motor2Speed));
      digitalWrite(MOTOR_1_PIN_2, LOW);
      digitalWrite(MOTOR_4_PIN_1, 0);
      digitalWrite(MOTOR_4_PIN_2, LOW);
      digitalWrite(MOTOR_2_PIN_1, 0);
      analogWrite(MOTOR_2_PIN_2, abs(motor2Speed));
      digitalWrite(MOTOR_3_PIN_1, abs(motor2Speed));
      digitalWrite(MOTOR_3_PIN_2, LOW);
    }
    // Pure right movement
    else if (motor2Speed < 0) {
      digitalWrite(MOTOR_1_PIN_1, 0);
      digitalWrite(MOTOR_1_PIN_2, abs(motor2Speed));
      digitalWrite(MOTOR_4_PIN_1, abs(motor2Speed));
      digitalWrite(MOTOR_4_PIN_2, LOW);
      analogWrite(MOTOR_2_PIN_1, abs(motor2Speed));
      digitalWrite(MOTOR_2_PIN_2, LOW);
      digitalWrite(MOTOR_3_PIN_1, LOW);
      analogWrite(MOTOR_3_PIN_2, abs(motor2Speed));
    } else {
      // Stop all motors if there's no joystick input
      digitalWrite(MOTOR_1_PIN_1, LOW);
      digitalWrite(MOTOR_1_PIN_2, LOW);
      digitalWrite(MOTOR_2_PIN_1, LOW);
      digitalWrite(MOTOR_2_PIN_2, LOW);
      digitalWrite(MOTOR_3_PIN_1, LOW);
      digitalWrite(MOTOR_3_PIN_2, LOW);
      digitalWrite(MOTOR_4_PIN_1, LOW);
      digitalWrite(MOTOR_4_PIN_2, LOW);
    }
  }
}
