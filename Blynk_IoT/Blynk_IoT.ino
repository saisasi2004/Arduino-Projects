#define BLYNK_TEMPLATE_ID "TMPL3XZiWN4ie"
#define BLYNK_TEMPLATE_NAME "lol"
#define BLYNK_AUTH_TOKEN "fSsUFZhQV5UYiVCP8gqELuIQnuxGV6Su"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Sai Sasivardhan";
char pass[] = "Saisasi2004";

// This function is called every time the Virtual Pin 0 state changes


BLYNK_WRITE(V1){
   int value = param.asInt();
   value ? digitalWrite(D8, HIGH) : digitalWrite(D8, LOW);
  }

void setup(){

  pinMode(D8, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
