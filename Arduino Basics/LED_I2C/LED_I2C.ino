#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET     4

Adafruit_SSD1306 display(OLED_RESET);



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C) ;
    
  display.clearDisplay();

  }

void loop() {
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("ROBOTICS");
display.display();
delay(2000);

display.clearDisplay();

display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(1,0);
display.println("IS FUTURE");
display.display();
delay(2000);

display.clearDisplay();
}
