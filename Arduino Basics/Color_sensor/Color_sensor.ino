int S0=4;
int S1=5;
int S2=6;
int S3=7;
int sensorOut=8;

int frequency1=0;
int frequency2=0;
int frequency3=0;

void setup() {
  // put your setup code here, to run once:
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(sensorOut,INPUT);

digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);

frequency1=pulseIn(sensorOut,LOW);

frequency1=map(frequency1,25,70,255,0);

//Serial.print("R= ");
//Serial.print(frequency1);
//Serial.print("  ");
//delay(100);


digitalWrite(S2,HIGH);
digitalWrite(S3,HIGH);

frequency2=pulseIn(sensorOut,LOW);

frequency2=map(frequency2,25,70,255,0);

//Serial.print("G= ");
//Serial.print(frequency2);
//Serial.print("  ");
//delay(100);


digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);

frequency3=pulseIn(sensorOut,LOW);

frequency3=map(frequency3,25,70,255,0);

//Serial.print("B= ");
//Serial.print(frequency3);
//Serial.println("  ");
//delay(100);

if(frequency1>frequency2)
{
  if(frequency1>frequency3)
  {
    Serial.println("RED Color");
  }
  else
  {
    Serial.println("BLUE Color");
  }}
else
{
  if(frequency2>frequency3)
  {
    Serial.println("GREEN Color");  
  }
  else
  {
    Serial.println("BLUE Color");
  }
}
}
