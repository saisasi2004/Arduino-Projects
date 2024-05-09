const int PWM_M1=6; 
const int PWM_M2=5; 

const int MOTOR_1_PIN_1=8;
const int MOTOR_1_PIN_2=9;

const int MOTOR_2_PIN_1=2; 
const int MOTOR_2_PIN_2=3;

int speed=255;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_M1,OUTPUT);
  pinMode(PWM_M2,OUTPUT);
  
  pinMode(MOTOR_1_PIN_1,OUTPUT);
  pinMode(MOTOR_2_PIN_1,OUTPUT);
  
  pinMode(MOTOR_1_PIN_2,OUTPUT);
  pinMode(MOTOR_2_PIN_2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char val = Serial.read();
    if(val == 'F')   //Forward
    {
        Serial.println("Forward");
  analogWrite(PWM_M1, speed);
  analogWrite(PWM_M2, speed);
  
  digitalWrite(MOTOR_1_PIN_1, HIGH);
  digitalWrite(MOTOR_2_PIN_1, LOW);
  
  digitalWrite(MOTOR_1_PIN_2, HIGH);
  digitalWrite(MOTOR_2_PIN_2, LOW);
    }
    else if(val == 'B')   //Backward
    {
        Serial.println("Backward");
  analogWrite(PWM_M1, speed);
  analogWrite(PWM_M2, speed);
  
  digitalWrite(MOTOR_1_PIN_1, LOW);
  digitalWrite(MOTOR_2_PIN_1, HIGH);
  
  digitalWrite(MOTOR_1_PIN_2, LOW);
  digitalWrite(MOTOR_2_PIN_2, HIGH);
    }
    else if(val == 'L')  //Left
    { 
        Serial.println("TurnLeft");
  analogWrite(PWM_M1, 0);
  analogWrite(PWM_M2, speed);
  
  digitalWrite(MOTOR_1_PIN_1, HIGH);
  digitalWrite(MOTOR_2_PIN_1, LOW);
  
  digitalWrite(MOTOR_1_PIN_2, HIGH);
  digitalWrite(MOTOR_2_PIN_2, LOW);
    }
    else if(val == 'R')  //Right
    {
      Serial.println("TurnRight");
  analogWrite(PWM_M1, speed);
  analogWrite(PWM_M2, 0);
  
  digitalWrite(MOTOR_1_PIN_1, HIGH);
  digitalWrite(MOTOR_2_PIN_1, LOW);
  
  digitalWrite(MOTOR_1_PIN_2, HIGH);
  digitalWrite(MOTOR_2_PIN_2, LOW);
    }
    
    else if(val == 'S')  //Stop
    { 
        Serial.println("Stop");
  digitalWrite(MOTOR_1_PIN_1, LOW);
  digitalWrite(MOTOR_2_PIN_1, LOW);
  
  digitalWrite(MOTOR_1_PIN_2, LOW);
  digitalWrite(MOTOR_2_PIN_2, LOW);
    }
}
}
