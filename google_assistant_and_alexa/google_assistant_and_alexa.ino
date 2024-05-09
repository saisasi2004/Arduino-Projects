#ifdef ENABLE_DEBUG
  #define DEBUG_ESP_PORT Serial
  #define NODEBUG_WEBSOCKETS
  #define NDEBUG
#endif 

#include <Arduino.h>
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

#include <SinricPro.h>
#include <SinricProSwitch.h>

#if defined(ESP8266)
  #define RELAYPIN_1 D1
  #define RELAYPIN_2 D2
  #define RELAYPIN_3 D3
  #define RELAYPIN_4 D4
  #define RELAYPIN_5 D5
  #define RELAYPIN_6 D6
  #define RELAYPIN_7 D7
  #define RELAYPIN_8 D8
#endif

struct RelayInfo {
  String deviceId;
  String name;
  int pin;
};

std::vector<RelayInfo> relays = {
    {"64ca7a2126edb4da3b4a7f00", "Relay 1", RELAYPIN_1},
    {"64ca7a0f26edb4da3b4a7ee3", "Relay 2", RELAYPIN_2},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 3", RELAYPIN_3},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 4", RELAYPIN_4},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 5", RELAYPIN_5},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 6", RELAYPIN_6},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 7", RELAYPIN_7},
    {"5fxxxxxxxxxxxxxxxxxxxxxx", "Relay 8", RELAYPIN_8}};

#define WIFI_SSID  "Srihari2g"
#define WIFI_PASS  "dhriti2008"
#define APP_KEY    "d24a8c2b-5a10-419d-9fbb-7ad459355a9f"    
#define APP_SECRET "82601a5b-dadc-4392-8ee8-348e5a6aa48c" 

#define BAUD_RATE  115200              

bool onPowerState(const String &deviceId, bool &state) {
  for (auto &relay : relays) {                                                            
    if (deviceId == relay.deviceId) {                                                      
      Serial.printf("Device %s turned %s\r\n", relay.name.c_str(), state ? "on" : "off");     
      digitalWrite(relay.pin, state);                                                         
      return true;                                                                            
    }
  }
  return false; 
}

void setupRelayPins() {
  for (auto &relay : relays) {    
    pinMode(relay.pin, OUTPUT);    
  }
}

void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro() {
  for (auto &relay : relays) {                             
    SinricProSwitch &mySwitch = SinricPro[relay.deviceId];   
    mySwitch.onPowerState(onPowerState);                     
  }

  SinricPro.onConnected([]() { Serial.printf("Connected to SinricPro\r\n"); });
  SinricPro.onDisconnected([]() { Serial.printf("Disconnected from SinricPro\r\n"); });

  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup() {
  Serial.begin(BAUD_RATE);
  setupRelayPins();
  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}
