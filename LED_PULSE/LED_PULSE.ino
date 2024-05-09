#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET     4

Adafruit_SSD1306 display(OLED_RESET);


#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>      

const int PulseWire = 0;       
const int LED = LED_BUILTIN;          
int Threshold = 550;                                   
                           
PulseSensorPlayground pulseSensor;  



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ;
    
  display.clearDisplay();


  Serial.begin(9600);          
  
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       
  pulseSensor.setThreshold(Threshold);   
  
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !"); 
  }

  }

void loop() {



if (pulseSensor.sawStartOfBeat()) {            
int myBPM = pulseSensor.getBeatsPerMinute();  
                                             
       display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("A HeartBeat Happened!");
display.print("BPM:  ");
display.println(myBPM);
display.display();
delay(20);

display.clearDisplay();                
}
}
