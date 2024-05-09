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
}

void loop() {
  // put your main code here, to run repeatedly:
while(GPS.available()>0){
  gps.encode(GPS.read());
  if(gps.location.isUpdated()){
    Serial.print("Latitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print("   ");
    Serial.print("Longitude: ");
    Serial.print(gps.location.lng(), 6);
    Serial.print("   ");
    Serial.print("  Altitude: ");
    Serial.println(gps.altitude.meters());
  }
}
}
