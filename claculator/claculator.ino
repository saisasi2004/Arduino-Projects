#include<Keypad.h>
#include<LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

double num1,num2 ;
double total;
char operation,button;
const byte ROWS = 4;  
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'c','0','=','/'}
};
byte rowPins[ROWS] = { 0, 1, 2, 3 };// row pins
byte colPins[COLS] = { 4, 5, 6, 13 }; // column pins
  
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

void domath() 
{
  switch(operation)
  {
    
    case '+': // Addition
      total = num1+num2;
      break;
    case '-': // Subtraction 
      total = num1-num2;
      break;
    case '/': // Division.
      total = num1/num2;
      break;
    case '*': // Multiplication
      total = num1*num2;
      break;
     case '%': // Modulus
      total = (int)num1%(int)num2;
      break;
  }
  lcd.clear();
  // Based on case selected print our total and 
  lcd.setCursor(0,1);
  lcd.print('=');
  lcd.setCursor(1,1);
  lcd.print(total);
}
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Calculator");
delay(2000);
lcd.clear();
}

void loop() {
  
while(1) // First loop. Composing first number. Until operator pressed
  {
    button = kpd.getKey(); // Button read
    if (button >='0' && button <='9') // If user pressed numeric value, 1 character at a time.
    {
      lcd.clear();
      num1 = num1*10 + (button -'0'); //First operand composing
      lcd.setCursor(0,0); // Select first row on lcd
      lcd.print(num1); // Print current number1
      
    }
    
    //Inputting operator
    if (num1 !=0 && (button=='+' || button=='-' || button=='*' || button=='/' || button=='%'))
    {
      operation = button; // operation remembers what mathematical operation user wants on numbers
      lcd.setCursor(0,1); // set cursor to row 2
      lcd.print(operation); // print our operator
      break;
    }
  }
  
  while(1) // Second loop. Inputting second operand. Until '=' pressed
  {
    button = kpd.getKey(); // Button read
    if (button >='0' && button <='9') // Getting chars from keypad for second number
    {
      num2 = num2*10 + (button -'0'); //Second operand composing
      lcd.setCursor(1,1); // Select second row, second column on lcd
      lcd.print(num2); // Print current operand2
    
    }

    if (button == '=' && num2 !=0) //Do calculation if '=' is pressed
    {
      domath(); //Calls domath() subroutine
      break;
    }
      
  }
 
  while(1) // Clearing screen for next calculation
  {
    //Waits ‘=’ key to be pressed so it can reset program and start over.
    button = kpd.getKey();;
    if (button =='c')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      num1=0;
      num2=0;
      total=0;
      operation=0;
      break;
    }
  }
}
