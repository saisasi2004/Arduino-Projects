int latchpin=11;
int clockpin=10;
int datapin=12;

byte LED1s=0b10101010;
byte LED2s=0b01010101;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchpin,OUTPUT);
pinMode(datapin,OUTPUT);
pinMode(clockpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchpin,LOW);
shiftOut(datapin,clockpin,LSBFIRST,LED1s);
digitalWrite(latchpin,HIGH);
delay(500);

digitalWrite(latchpin,LOW);
shiftOut(datapin,clockpin,LSBFIRST,LED2s);
digitalWrite(latchpin,HIGH);
delay(500);
}
