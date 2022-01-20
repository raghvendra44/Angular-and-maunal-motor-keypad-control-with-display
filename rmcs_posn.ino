byte angl_func(int encoder,int speed)
{
  lcd.clear();lcd.setCursor(0, 0);lcd.print(F("Speed: "));
  lcd.setCursor(7, 0);lcd.print(speed/60);
  lcd.setCursor(0, 1);lcd.print(F("Posn: "));
  lcd.setCursor(6, 1);lcd.print(float(encoder/23.74));
  long int inc;int c = 2;
  float prev;

  while(fin == 1)
  {
    char num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}
    
    if(num == '#' || num == 'B')
    {
      if(num == '#')
      {
        inc = encoder;
        c = 2;
        prev = posn(encoder,speed); // posn(encoder pulses),encoder pulses = angle*23.74, 1 degree = 23 encoder pulses.
      }
    
      else if(num =='B')
      {
        Serial.println(inc);
        Serial.println(c);
        Serial.println(inc*c);
        prev = posn(inc*c,speed);
        c = c + 1;
      }      
      lcd.clear();lcd.setCursor(0, 1);lcd.print(F("prev: "));
      lcd.setCursor(5, 1);lcd.print(prev);
      lcd.setCursor(0, 0);lcd.print(F("Speed: "));
      lcd.setCursor(6, 0);lcd.print(float(speed)/60.00);
    }

    else if(num =='*')
    {
      lcd.setCursor(10, 0);lcd.print(F("Change"));
      delay(500);
      return 1;
      break;
    }
    else if(num =='D')
    {
      lcd.clear();lcd.setCursor(0, 0);lcd.print(F("MAN"));
      lcd.setCursor(4, 0);lcd.print(F("Prev: "));
      lcd.setCursor(9, 0);lcd.print(prev);
      delay(500);
      return 0;
      break;
    }
    else if(num =='A'){fin = home_posn_call();}
    else if(num == 'C'){fin = man_call();}

    else if(num == '2')
    {
      speed = speed+(speed*5)/100;      
      lcd.setCursor(0, 0);lcd.print(F("Speed: "));
      lcd.setCursor(7, 0);lcd.print(float(speed)/60.00);
      lcd.setCursor(13, 0);lcd.print(F("INC"));
      Serial.print(speed);
    }

    else if(num == '8')
    {
      speed = speed-(speed*5)/100;
      if(speed < 150){speed = 151;}
      lcd.setCursor(0, 0);lcd.print(F("Speed: "));
      lcd.setCursor(7, 0);lcd.print(float(speed)/60.00);
      lcd.setCursor(13, 0);lcd.print(F("DEC"));
      Serial.print(speed);
    }
  }
  return prev;
}

int posn(long int encoder,int speed)
{
   int slave_id = 7;
   Serial.print(F("Sending absolute position command :"));
   Serial.println(encoder);
   rmcs.Speed(slave_id,speed);
   rmcs.Acceleration(slave_id,int(float(speed)+float(speed)*0.34));
   rmcs.Absolute_position(slave_id,encoder);
   while(1)
    {
    Serial.print(F("Position Feedback :\t"));
    Serial.println(float(rmcs.Position_Feedback(slave_id))/23.74);
    lcd.clear();lcd.setCursor(0,0);lcd.print(F("Speed: "));
    lcd.setCursor(8,0);lcd.print(rmcs.Speed_Feedback(slave_id)/60);
    lcd.setCursor(0,1);lcd.print(F("Angle: "));
    lcd.setCursor(7,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.74);
    //delay(10);
    
    if((rmcs.Position_Feedback(slave_id) >= (encoder - 2) && rmcs.Position_Feedback(slave_id) <= (encoder + 2)))
    //if(Current_position == encoder) 
        {
          
           Serial.print(F("Position reached :"));
           Serial.print(float(rmcs.Position_Feedback(slave_id))/23.74);
           Serial.print(F("\t error in goal :"));
           Serial.println(float(encoder)/23.74 - float(rmcs.Position_Feedback(slave_id))/23.74);
           break;
        }
     }
     Serial.println(F("-------------Loop ended-------------"));
     
     lcd.clear();lcd.setCursor(0,0);lcd.print(F("Speed: "));
     lcd.setCursor(7,0);lcd.print(rmcs.Speed_Feedback(slave_id)/60);
     lcd.setCursor(0,1);lcd.print("Done: ");
     lcd.setCursor(6,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.74);
     delay(2000);
     return float(rmcs.Position_Feedback(slave_id))/23.74;
}
