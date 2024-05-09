#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define GSM_RX 2
#define GSM_TX 3
#define GPS_RX 4
#define GPS_TX 5
#define GPS_BAUD 9600
#define GSM_BAUD 9600

SoftwareSerial gsmSerial(GSM_RX, GSM_TX); // RX, TX
SoftwareSerial gpsSerial(GPS_RX, GPS_TX); // RX, TX

TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPS_BAUD);
  gsmSerial.begin(GSM_BAUD);
}

void loop() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        sendSMS(gps.location.lat(), gps.location.lng());
      }
    }
  }
}

void sendSMS(float latitude, float longitude) {
  gsmSerial.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
  gsmSerial.print("AT+CMGS=\"7661991859\"\r"); // Replace PHONE_NUMBER with recipient's phone number
  delay(1000);
  gsmSerial.print("Latitude: ");
  gsmSerial.print(latitude, 6);
  gsmSerial.print(", Longitude: ");
  gsmSerial.print(longitude, 6);
  gsmSerial.println((char)26); // End AT command with Ctrl+Z
  delay(1000);
}
