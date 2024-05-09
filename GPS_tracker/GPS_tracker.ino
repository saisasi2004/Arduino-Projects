#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 


#include<TinyGPS++.h>
#include<SoftwareSerial.h>

static const int RXpin=3,TXpin=4;
static const int GPSbaud=9600;

TinyGPSPlus gps;

SoftwareSerial GPS(RXpin,TXpin);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
GPS.begin(GPSbaud);
Serial.println("Location: ");


lcd.init();                     
  lcd.backlight();
}

void loop() {
while(GPS.available()>0){
  gps.encode(GPS.read());
  if(gps.location.isUpdated()){
    lcd.setCursor(0,0);
    lcd.print("Latitude: ");
    lcd.print(gps.location.lat(), 6);
    lcd.setCursor(0,1);
    lcd.print("Longitude: ");
    lcd.print(gps.location.lng(), 6);
    Serial.print("   ");
    Serial.print("  Altitude: ");
    Serial.println(gps.altitude.meters());
  }
}
}
