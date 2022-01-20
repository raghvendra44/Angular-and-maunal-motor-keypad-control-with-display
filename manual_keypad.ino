byte manual_keypad(int sp)
{
  lcd.clear();lcd.setCursor(0, 0);lcd.print("MAN");
  char num = customKeypad.getKey();
  
  while(fin == 1)
  {
    num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}

    if(num == '2')
    {
      sp = sp +(sp *5)/100;
      if(speed < 150){speed = 151;}
      if(speed > 18000){speed = 18000;}
      rmcs.Speed(slave_id,sp);
      rmcs.Acceleration(slave_id,int(float(sp)+float(sp)*0.34));
      lcd.setCursor(13, 1);lcd.print(F("INC"));
      lcd.setCursor(0, 1);lcd.print(F("Spd:"));
      lcd.setCursor(4, 1);lcd.print(float(sp )/60.00);
    }

    else if(num == '8')
    {
      sp = sp -(sp*5)/100;
      if(speed < 150){speed = 151;}
      if(speed > 18000){speed = 18000;}
      rmcs.Speed(slave_id,sp );
      rmcs.Acceleration(slave_id,int(float(sp)+float(sp)*0.34));
      lcd.setCursor(13, 1);lcd.print(F("DEC"));
      lcd.setCursor(0, 1);lcd.print(F("Spd:"));
      lcd.setCursor(4, 1);lcd.print(float(sp )/60.00);
    }
    
    else if(num == '4')
    {
      Serial.println(float(rmcs.Position_Feedback(slave_id))/23.00);
      Serial.println(F("CW "));
      rmcs.Enable_Digital_Mode(slave_id,0);        //To enable motor in digital speed control mode. 0-fwd,1-reverse direction.
      for(int i = 0;i<4;i++)
      {
        Serial.println(float(rmcs.Position_Feedback(slave_id))/23.00);
        lcd.setCursor(13, 1);lcd.print(F("CW "));
        lcd.setCursor(4, 0);lcd.print(F("posn: "));
        lcd.setCursor(10, 0);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.00);
        lcd.setCursor(0, 1);lcd.print(F("Spd:"));
        lcd.setCursor(4, 1);lcd.print(float(sp )/60.00);
        delay(10);
      }
      rmcs.Brake_Motor(slave_id,0);
      Serial.println(float(rmcs.Position_Feedback(slave_id))/23.00);
      lcd.setCursor(4, 0);lcd.print(F("posn: "));
      lcd.setCursor(10, 0);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.00);
    }

    else if(num == '6')
    {
      Serial.println(F("CCW"));
      rmcs.Enable_Digital_Mode(slave_id,1);        //To enable motor in digital speed control mode. 0-fwd,1-reverse direction. 
      for(int i = 0;i<4;i++)
      {
        Serial.println(float(rmcs.Position_Feedback(slave_id))/23.00);
        lcd.setCursor(13, 1);lcd.print(F("CCW"));
        lcd.setCursor(0, 1);lcd.print(F("Spd:"));
        lcd.setCursor(4, 1);lcd.print(sp);
        lcd.setCursor(4, 0);lcd.print(F("posn: "));
        lcd.setCursor(10, 0);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.00);
        delay(10);
      }
      rmcs.Brake_Motor(slave_id,1);
      Serial.println(float(rmcs.Position_Feedback(slave_id))/23.00);
      lcd.setCursor(4, 0);lcd.print(F("posn: "));
      lcd.setCursor(10, 0);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.00);
    }

    else if(num == '5')
    {
      rmcs.Brake_Motor(slave_id,1);
      Serial.println(F("Break"));
      lcd.setCursor(13, 1);lcd.print(F("Brk"));
      lcd.setCursor(0, 1);lcd.print(F("Speed:"));
      lcd.setCursor(7, 1);lcd.print("0");
      delay(500);
    }
    
    else if(num == '*')
    {
      lcd.setCursor(10, 1);lcd.print(F("Change"));
      delay(500);
      return 1;
      break;
    }
    else if(num == 'D')
    {
      lcd.setCursor(12, 1);lcd.print(F("Exit"));
      delay(500);
      return 0;
      break;
    }
    
    else if(num == 'A'){fin = home_posn_call();}
  }
}
