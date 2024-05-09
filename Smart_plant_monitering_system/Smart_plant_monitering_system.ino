int gaspin=A1;
int moipin=A0;

int ledpin=13;
int buzzpin=6;
int sensepin=2;
int motpin=7;


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>



#define Type DHT11
DHT HT(sensepin,Type);
float humidity;
float tempC;
float tempF;

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  pinMode(moipin,INPUT);
  pinMode(gaspin,INPUT);
pinMode(buzzpin,OUTPUT);
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
HT.begin();
delay(500);

  lcd.init();                     
  lcd.backlight();
 

  }
void loop()
{
int moivalue=analogRead(moipin);
int gasval=analogRead(gaspin);


 if(moivalue>=500)
 {
  digitalWrite(ledpin,HIGH);
  digitalWrite(buzzpin,HIGH);
 }
 else
 {
  digitalWrite(motpin,HIGH);
 }


if(gasval>=350)
{
  digitalWrite(buzzpin,HIGH);
  digitalWrite(ledpin,HIGH);
}
else
{
  digitalWrite(ledpin,LOW);
  digitalWrite(buzzpin,LOW);
}


humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

Serial.print("Humidity: ");
Serial.println(humidity);

Serial.print("Temperature C: ");
Serial.println(tempC);

Serial.print("Temperature F: ");
Serial.println(tempF);

Serial.print("Toxic Gas Detection: ");
Serial.println(gasval);

Serial.print("Moisture Value: ");
Serial.println(moivalue);

delay(3000);

  
  lcd.setCursor(0,0);
  lcd.print("Humidity is ");
  lcd.print(humidity);
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.print(tempC);
  delay(2000);
  lcd.clear();

  }
