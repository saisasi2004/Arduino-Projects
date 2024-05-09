#include <DHT.h>



#define Type DHT22
int sensepin=2;
DHT HT(sensepin,Type);
float humidity;
float tempC;
float tempF;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

Serial.print("Humidity: ");
Serial.println(humidity);

Serial.print("Temperature C: ");
Serial.println(tempC);

Serial.print("Temperature F: ");
Serial.println(tempF);

delay(3000);
}
