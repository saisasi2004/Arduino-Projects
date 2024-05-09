int micpin=A0;
void setup() {
  // put your setup code here, to run once:
pinMode(micpin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(micpin);

int db=map(val,1023,0,43,120);
Serial.print("Loudness is:- ");
Serial.print(db);
Serial.print(" ");
Serial.println("dB");
delay(300);
}
