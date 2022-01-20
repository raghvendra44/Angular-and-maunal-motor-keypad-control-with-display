byte angular_mode()
{
  lcd.clear();lcd.setCursor(0,0);lcd.print(F("ANGL"));
  String degree="";String sp = "";int stage = 0;
  
  while(fin == 1)
  {
    if(stage == 0){lcd.clear();lcd.setCursor(0,0);lcd.print(F("ANGL"));lcd.setCursor(0, 1);lcd.print(F("Speed: "));lcd.setCursor(12, 1);lcd.print(sp);}
    else if(stage == 1){lcd.setCursor(0, 1);lcd.print(F("Enter Angle:"));}

    char num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}
    
    if(num == '*')
    {
      if(stage == 0)
      {
        String val;
        if(stage == 0){sp = backspace(sp);val = sp;}
        if(stage == 1){degree = backspace(degree);val = degree;}
        lcd.setCursor(12, 1);lcd.print(F(" "));lcd.setCursor(13, 1);lcd.print(F(" "));lcd.setCursor(14, 1);lcd.print(F(" "));lcd.setCursor(15, 1);lcd.print(F(" "));  
        lcd.setCursor(12, 1);lcd.print(val);
        Serial.println();
        Serial.print(val);
      }
      if(stage == 1)
      {
        degree = "";sp ="";stage =0;
      }
    }
    
    else if(num == 'D')
    {
      rmcs.Brake_Motor(slave_id,0);
      delay(1000);
      lcd.clear();
      break;
    }
    
    else if(num == '#')
    {
      if(stage == 0)
      {
        lcd.clear();lcd.setCursor(0,0);lcd.print(F("ANGL"));
        lcd.setCursor(6, 0);lcd.print(F("Speed:"));
        lcd.setCursor(12, 0);lcd.print(sp);
        lcd.setCursor(0, 1);lcd.print(F("Enter Angle:"));
        Serial.println();
        Serial.print(F("Enter Angle: "));
        stage = 1;
      }
      else if(stage == 1)
      {
        degree = String(float(degree.toInt()*23.74));        //encoder pulses = angle*23, 1 degree = 23 encoder pulses.
        fin = angl_func(degree.toInt(),sp.toInt()*60);// angl_func(encoder pulses, speed)
        degree = "";sp ="";stage =0;
        Serial.println();
        Serial.print(F("Enter speed: "));
      }
    }
    else if(num == 'C'){fin = man_call();}
    else if(num == 'A'){fin = home_posn_call();}
    
    else
    {
      String val;
      if(stage == 0){sp = enter_num(sp,num);val = sp;}
      if(stage == 1){degree = enter_num(degree,num);val = degree;}
      lcd.setCursor(12, 1);lcd.print(val);
      Serial.print(num);
    }
  }
  lcd.clear();lcd.setCursor(0, 0);lcd.print(F("ANGULAR CONTROL"));
  lcd.setCursor(4, 1);lcd.print(F("ENDED"));
  delay(500);
  return 0;
}
