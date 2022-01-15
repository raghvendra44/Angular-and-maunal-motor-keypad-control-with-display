void angular_mode()
{
  lcd.clear();lcd.setCursor(0,0);lcd.print("Angular");
  String degree="";
  lcd.setCursor(0, 1);lcd.print("Enter Angle:");
  
  while(true)
  {
    Serial.print(F("Enter Angle: "));
    
    char num = customKeypad.getKey();
    while(!num){num = customKeypad.getKey();}   
    
    if(num == '*')
    {
      degree = enter_num(degree,num);  
      lcd.setCursor(12, 1);lcd.print(" ");lcd.setCursor(13, 1);lcd.print(" ");lcd.setCursor(14, 1);lcd.print(" ");lcd.setCursor(15, 1);lcd.print(" ");  
      lcd.setCursor(12, 1);lcd.print(degree);
      Serial.println();
      Serial.print(degree);
    }
    else if(num == 'D')
    {
      rmcs.Brake_Motor(slave_id,0);
      lcd.clear();lcd.setCursor(0, 0);lcd.print("ANGULAR CONTROL");
      lcd.setCursor(4, 1);lcd.print("ENDED");
      delay(1000);
      lcd.clear();
      break;
    }
    
    else if(num == '#')
    {
      float prev = posn(degree.toInt()*23); // posn(encoder pulses),encoder pulses = angle*23, 1 degree = 23 encoder pulses.
      degree = "";      
      lcd.clear();
      lcd.setCursor(0, 0);lcd.print("prev :");
      lcd.setCursor(7, 0);lcd.print(prev); 
      lcd.setCursor(0, 1);lcd.print("Enter Angle:");

    }
    else
    {
      if(degree.length() == 0){degree = num;}
      else{degree = degree + num;}
      lcd.setCursor(12, 1);lcd.print(degree);
      Serial.print(num);
    }
  }
}
