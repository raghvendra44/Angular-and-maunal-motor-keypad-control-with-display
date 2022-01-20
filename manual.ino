byte manual_mode()
{
  lcd.clear();lcd.setCursor(6, 0);lcd.print("RPM Range");
  lcd.setCursor(1, 1);lcd.print("2 ~ 300");
  delay(2500);
  lcd.clear();lcd.setCursor(0, 0);lcd.print("MAN");

  lcd.setCursor(0, 1);lcd.print("Enter SPEED:    ");
  char num = customKeypad.getKey();  
  String sp = "";
  while(fin == 1)
  {
    num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}  
    
    if(num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || 
    num == '6' || num == '7' || num == '8' || num == '9' || num == '0')  
    // enter speeed
    {
      sp = enter_num(sp,num);
      lcd.setCursor(12, 1);lcd.print(sp);
      Serial.print(num);
    }
        
    else if(num == '#' && num != 'D')
    {
      rmcs.Speed(slave_id,sp.toInt());                   //Set speed within range of 0-65535 or 0-(maximum speed of base motor)
      //lcd.clear();lcd.setCursor(0, 0);lcd.print(F("MAN"));
      lcd.clear();lcd.setCursor(2, 0);lcd.print(F("2: Inc speed"));
      lcd.setCursor(2, 1);lcd.print(F("8: Dec speed"));
      delay(2000);
      lcd.clear();lcd.setCursor(2, 0);lcd.print(F("4: Move CW"));
      lcd.setCursor(2, 1);lcd.print(F("6: Move CCW"));
      delay(2000);
      lcd.clear();lcd.setCursor(2, 0);lcd.print(F("5: Apply break"));
      lcd.setCursor(2, 1);lcd.print(F("D: Add new spd"));
      delay(2000);
      fin = manual_keypad(sp.toInt()*60);
      sp = "";
      if(fin == 1)
      {
        lcd.clear();lcd.setCursor(0, 0);lcd.print("MAN");
        lcd.setCursor(1, 1);lcd.print("RPM: 2.5 -> 300");
        delay(2500);
        lcd.setCursor(0, 1);lcd.print("Enter SPEED:    ");
      }
      else{rmcs.Brake_Motor(slave_id,0);}
    }

    else if(num == '*')                               //Backspace function
    {
      sp = backspace(sp);
      lcd.setCursor(12, 1);lcd.print(" ");lcd.setCursor(13, 1);lcd.print(" ");lcd.setCursor(14, 1);lcd.print(" ");lcd.setCursor(15, 1);lcd.print(" ");  
      lcd.setCursor(12, 1);lcd.print(sp);
      Serial.println();
      Serial.print(sp);
    }
    
    else if(num == 'D')                            // Exit function
    {
      speed=400;
      lcd.clear();
      rmcs.Brake_Motor(slave_id,0);
      break;
    }
    else if(num == 'B'){angl_call();}
    else if(num == 'A'){home_posn_call();}
  }
  lcd.clear();lcd.setCursor(0, 0);lcd.print("MANUAL CONTROL");
  lcd.setCursor(4, 1);lcd.print("ENDED");
  delay(1000);
  return 0;
}
