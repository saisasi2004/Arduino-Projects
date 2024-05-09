const int redpin=11;
const int grepin=10;
const int blupin=9;
void setup() {
  // put your setup code here, to run once:
pinMode(redpin,OUTPUT);
pinMode(grepin,OUTPUT);
pinMode(blupin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(redpin,HIGH);
digitalWrite(grepin,HIGH);
digitalWrite(blupin,HIGH);
}
