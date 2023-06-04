// Code written by Inventr.io for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure
 
 
int Light = 12; // The HERO Board Pin that the LED is wired to
 #define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int forwardButtPin = 9;
const int backButtPin = 8;
const int buttonPin = 10;
String level1[15][2];

void setup() {
 Serial.begin(9600) ;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
    pinMode(forwardButtPin, INPUT_PULLUP);
    pinMode(backButtPin, INPUT_PULLUP);
 
  // Print a message to the LCD.
 // lcd.print("yosef and elly");
  byte floatingGun[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00110,
    B00100,
    B00000
  };
  lcd.createChar(0, floatingGun);
  byte backwardGunPlayer[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B11010,
    B01111,
    B00010,
    B00101
  };
  lcd.createChar(6, backwardGunPlayer);
   
   byte floor[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  lcd.createChar(1, floor);
    
   byte emptyFloor[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
  };
  lcd.createChar(5, emptyFloor);

  byte flag[8] = {
    B11111,
    B11111,
    B11111,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000
  };
  lcd.createChar(2, flag);
   
  byte player[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B00100,
    B01010
  };
  byte player2[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B01011,
    B11110,
    B01000,
    B10100
  };
  lcd.createChar(3, player);


byte playerJumping[8] = {
   
   
    B00100,
    B01110,
    B00100,
    B01010,
    B00000,
    B00000,
    B00000,
    B00000
    
  };
  lcd.createChar(4, playerJumping);
 
  
}

int cursorX = 0;
int cursorY = 1;
int buttonState = 0;  // variable for reading the pushbutton status
int forwardButtState = 0;
int backButtState = 0;
bool justJumped = false;

void playerJumping(){lcd.write(byte(4));}
void player(){lcd.write(byte(3));}
void flag(){lcd.write(byte(2));}
void emptyFloor(){lcd.write(byte(5));}
void floor(){lcd.write(byte(1));}
void backwardGunPlayer(){lcd.write(byte(6));}
void floatingGun(){lcd.write(byte(0));}

void youLose()
{
   lcd.clear();
  lcd.print("you lost:(");
  delay(1000);
  lcd.clear();
  lcd.print("restarting...");
  delay(500);
  //cursorX = 0;
}
void youWin()
{
    lcd.clear();
  lcd.print("you won!!");
  delay(1000);
  lcd.clear();
  lcd.print("restarting...");
  delay(500);
  //cursorX = 0;
}





void loop() {
  
   lcd.clear();
   
lcd.setCursor(15,0);
flag();
  buttonState = digitalRead(buttonPin);
  forwardButtState = digitalRead(forwardButtPin);
  backButtState = digitalRead(backButtPin);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if(cursorX < 15 && forwardButtState == LOW)
  {cursorX++;}
  else if(backButtState == LOW && cursorX > 0 )
  {
    cursorX--;
  }
  
  
  lcd.setCursor(cursorX, 0);
  
  if(buttonState == LOW && justJumped == false)
  {
    lcd.write(byte(4));
    justJumped = true;
  }
  else if(cursorX != 5){
    lcd.write(byte(3));
    justJumped = false;
    }
  //lcd.print(millis() / 1000);
  
  //lcd.print(xValue);
 for(int i = 0; i< 16; i++)
{
  lcd.setCursor(i,1);
  if(i!=5)
  lcd.write(byte(1));
  else if(cursorX != 5 || buttonState == LOW)
  lcd.write(byte(5));
  else
  {
    lcd.write(byte(3));
    delay(50);
  }

}
 delay(200);
  if(cursorX==5 && buttonState != LOW)
  {
   youLose();
  cursorX = 0;
  }
  if(cursorX==15)
  {
    youWin();
  cursorX = 0;
  }


}
