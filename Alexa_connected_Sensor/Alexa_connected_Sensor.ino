#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <DHT.h>

#define APP_KEY         "82601a5b-dadc-4392-8ee8-348e5a6aa48c"
#define APP_SECRET      "0447aecb-8a27-4960-a3a0-30502e19bfae-81da6f95-766e-4371-94f6-31afcfab74c7"
#define ACCESS_KEY      "d24a8c2b-5a10-419d-9fbb-7ad459355a9f"
#define WIFI_SSID       "Sai Sasivardhan"
#define WIFI_PASS       "Saisasi2004"

#define DHT_PIN         2 // Replace with the actual pin you're using
#define DHT_TYPE        DHT11
#define DEVICE_ID       "6545df582be91534cd8b613c"

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println();

  dht.begin();

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true); // Restore device states after a connection is established

  // Add your device(s) to Sinric Pro
  SinricPro.restoreDeviceStates(true); // Restore device states after a connection is established
}

void loop() {
  SinricPro.handle();

  // Read data from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (!isnan(humidity) && !isnan(temperature)) {
    // Report DHT sensor data to Sinric Pro if needed
    // You can add custom actions or events for your device in this loop
  }
}
