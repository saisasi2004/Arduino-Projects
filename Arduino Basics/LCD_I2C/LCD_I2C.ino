#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  lcd.init();                     
  lcd.backlight();
  }
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Presenting you ");
  lcd.setCursor(0,1);
  lcd.print("the most crazy");
  delay(2000);

  lcd.clear();
  lcd.print("character");
  lcd.setCursor(0,1);
  lcd.print("Sai Sasivardhan");
  delay(2000);
  lcd.clear();
  
  }
