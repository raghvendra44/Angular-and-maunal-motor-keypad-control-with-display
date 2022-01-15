void manual_mode()
{
  lcd.clear();lcd.setCursor(0, 0);lcd.print("MANUAL");
  lcd.setCursor(0, 1);lcd.print("Enter SPEED:");
  char num = customKeypad.getKey();
  
  String sp = "";

  while(true)
  {
    num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}  
    
    if(num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || 
    num == '6' || num == '7' || num == '8' || num == '9' || num == '0')  
    // enter speeed
    {
      sp = "";
      lcd.setCursor(0, 1);lcd.print("Enter SPEED:");
      sp = enter_num(sp,num);
      lcd.setCursor(12, 1);lcd.print(sp);
      Serial.print(num);
      char number = customKeypad.getKey();
      while(true)
        {
          number = customKeypad.getKey();
          while(!number){number = customKeypad.getKey();}
          if(number == '1' || number == '2' || number == '3' || number == '4' || number == '5' || 
          number == '6' || number == '7' || number == '8' || number == '9' || number == '0')
          {
            sp = enter_num(sp,number);
            lcd.setCursor(12, 1);lcd.print(sp);
            Serial.print(number);
          }
          else if(number == '*')                               //Backspace function
          {
            sp = backspace(sp);
            lcd.setCursor(12, 1);lcd.print(" ");lcd.setCursor(13, 1);lcd.print(" ");lcd.setCursor(14, 1);lcd.print(" ");lcd.setCursor(15, 1);lcd.print(" ");  
            lcd.setCursor(12, 1);lcd.print(sp);
            Serial.println();
            Serial.print(sp);
          }
          else if(number == 'D'){break;}
        }
    }
        
    else if(num == '#','A','C' && num != 'D')
    {
      rmcs.Speed(slave_id,sp.toInt());                   //Set speed within range of 0-65535 or 0-(maximum speed of base motor)
      lcd.clear();lcd.setCursor(0, 0);lcd.print(F("MAN"));
      lcd.setCursor(4, 0);lcd.print(F("C:CW"));
      lcd.setCursor(10, 0);lcd.print(F("A:ACW"));
      
      long int Current_position = rmcs.Position_Feedback(slave_id);
      if(num == 'C')                            // Clockwise function
      {
        Serial.println(F("CW"));
        rmcs.Enable_Digital_Mode(slave_id,0);        //To enable motor in digital speed control mode. 0-fwd,1-reverse direction. 
        lcd.setCursor(0, 1);lcd.print(F("Speed:"));
        lcd.setCursor(7, 1);lcd.print(sp);
        delay(500);
        rmcs.Brake_Motor(slave_id,0);
      }
      
      else if(num == 'A')                            // Anti - Clockwise function
      {
        Serial.println(F("ACW"));
          
        rmcs.Enable_Digital_Mode(slave_id,1);        //To enable motor in digital speed control mode. 0-fwd,1-reverse direction. 
        lcd.setCursor(0, 1);lcd.print(F("Speed:"));
        lcd.setCursor(7, 1);lcd.print("-"+sp);
        delay(500);
        rmcs.Brake_Motor(slave_id,0);
      }
    }
      
    else if(num == 'B')                            // Apply breaks to motor function
    {
      Serial.println(F("Break"));
      rmcs.Brake_Motor(slave_id,0);
    }
    
    else                            // Exit function
    {
      rmcs.Brake_Motor(slave_id,0);
      lcd.clear();lcd.setCursor(0, 0);lcd.print("MANUAL CONTROL");
      lcd.setCursor(4, 1);lcd.print("ENDED");
      delay(1000);
      speed=400;
      lcd.clear();
      break;
    }
  }
}
