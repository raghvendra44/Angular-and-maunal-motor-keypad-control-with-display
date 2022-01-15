#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<RMCS2303drive.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7, 6}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LiquidCrystal_I2C lcd(0x27, 16, 2);


//Parameter Settings "Refer datasheet for details" - 

RMCS2303 rmcs;
byte slave_id=7;                    //Choose the slave id of connected drive.
SoftwareSerial myserial(2,3);     //Software Serial port For Arduino Uno. Comment out if using Mega.

int INP_CONTROL_MODE=513;           //IMPORTANT: refer datasheet and set value(integer) according to application 
int PP_gain=32;
int PI_gain=16;
int VF_gain=32;
int LPR=41;
int acceleration=600;
int speed=400;
long int Current_Speed;

void setup()
{
  lcd.backlight();
  lcd.init();
  
  rmcs.Serial_selection(1);
  rmcs.Serial0(9600);
  rmcs.begin(&myserial,9600);

  lcd.setCursor(0,0);lcd.print(F("INITIALISING."));
  delay(350);
  lcd.setCursor(0,0);lcd.print(F("INITIALISING.."));
  delay(350);
  lcd.setCursor(0,0);lcd.print(F("INITIALISING..."));
  delay(350);
  
  rmcs.WRITE_PARAMETER(slave_id,INP_CONTROL_MODE,PP_gain,PI_gain,VF_gain,LPR,acceleration,speed);

  lcd.clear();lcd.setCursor(0,0);lcd.print(F("INITIALISED!"));
  delay(350);
  lcd.clear();lcd.setCursor(0,0);lcd.print(F("INITIALISED!!"));
  delay(350);

  lcd.clear();lcd.setCursor(0,0);lcd.print("A.Home posn");
  lcd.setCursor(0,1);lcd.print("B.Angular");
  lcd.setCursor(15,1);lcd.print("#");
}

void(* reset) (void) = 0;

char state = 'a';
void loop()
{
  Serial.println(F("\n\nCommand options : "));
  Serial.println(F("A.Home"));
  Serial.println(F("B.Angular"));
  Serial.println(F("C.Manual"));
  char customKey = customKeypad.getKey();
  while(!customKey){customKey = customKeypad.getKey();}
  
  if(customKey == '#')
  {
    if(state == 'a'){lcd.clear();lcd.setCursor(0,0);lcd.print("C.Manual");lcd.setCursor(0,1);lcd.print("D.Reset");lcd.setCursor(15,0);lcd.print("#");state='b';}
    else{lcd.clear();lcd.setCursor(0,0);lcd.print(F("A.Home posn"));lcd.setCursor(0,1);lcd.print(F("B.Angular"));lcd.setCursor(15,1);lcd.print(F("#"));state='a';}
  }  

  if (customKey == 'B')
  {
    Serial.println(F("Angular Control"));
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Angular Control");
    lcd.setCursor(2,1);lcd.print("- ( ANGL )");
    delay(2000);
    angular_mode();
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("A.Home posn"));lcd.setCursor(0,1);lcd.print(F("B.Angular"));lcd.setCursor(15,1);lcd.print(F("#"));state='a';
  }

  if(customKey == 'A')
  {
    Serial.println(F("Home posn"));
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Home posn"));
    home_posn();
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("A.Home posn"));lcd.setCursor(0,1);lcd.print(F("B.Angular"));lcd.setCursor(15,1);lcd.print(F("#"));state='a';
  }

  if (customKey == 'C')
  {
    Serial.println(F("Manual Control mode"));
    Serial.println(F("* - Clockwise\n# - Counter Clockwise"));
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Manual Control"));
    lcd.setCursor(2,1);lcd.print(F("- ( MAN )"));
    delay(2000);
    manual_mode();
    Serial.println(F("Ended"));
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("A.Home posn"));lcd.setCursor(0,1);lcd.print(F("B.Angular"));lcd.setCursor(15,1);lcd.print(F("#"));state='a';
  }

  if (customKey == 'D')
  {
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Restarting."));
    delay(250);
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Restarting.."));
    rmcs.ESTOP(slave_id);
    delay(350);
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Restarting..."));
    delay(350);
    reset();
  }
}
