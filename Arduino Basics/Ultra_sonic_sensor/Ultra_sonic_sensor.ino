int ULTRASONIC_TRIG_PIN=8;
int ULTRASONIC_ECHO_PIN=9;
int BUZZ_PIN=10;
void setup() {
  // put your setup code here, to run once:
  
pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
pinMode(ULTRASONIC_ECHO_PIN, INPUT);
pinMode(BUZZ_PIN,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; 
  Serial.println(distance);
  if (distance < 30) {  
    digitalWrite(BUZZ_PIN,HIGH);
  }
  else
{
  digitalWrite(BUZZ_PIN,LOW);
}
}
