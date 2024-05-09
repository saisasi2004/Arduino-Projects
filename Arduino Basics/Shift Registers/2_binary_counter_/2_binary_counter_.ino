int latchpin=11;
int clockpin=10;
int datapin=12;

byte LED1s=0b00000000;
int num=0;

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
Serial.print(LED1s,BIN);
Serial.print(" - ");
Serial.println(num);
num=num+1;
LED1s=LED1s+1;
delay(500);
}
