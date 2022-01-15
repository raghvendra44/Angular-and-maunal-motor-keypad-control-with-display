int posn(int encoder)
{
   int slave_id = 7;
   Serial.print(F("Sending absolute position command :"));
   Serial.println(encoder);
   rmcs.Absolute_position(slave_id,encoder);
   while(1)
    {
    Serial.print(F("Position Feedback :\t"));
    Serial.println(float(rmcs.Position_Feedback(slave_id))/23);
    lcd.clear();lcd.setCursor(0,0);lcd.print("Angular");
    lcd.setCursor(0,1);lcd.print("Angle :");
    lcd.setCursor(7,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23);

    delay(10);
    
    if((rmcs.Position_Feedback(slave_id) >= (encoder - 2) && rmcs.Position_Feedback(slave_id) <= (encoder + 2)))
    //if(Current_position == encoder) 
        {
          
           Serial.print(F("Position reached :"));
           Serial.print(float(rmcs.Position_Feedback(slave_id))/23.00);
           Serial.print(F("\t error in goal :"));
           Serial.println(float(encoder)/23.00 - float(rmcs.Position_Feedback(slave_id))/23.00);
           break;
        }
     }
     Serial.println(F("-------------Loop ended-------------"));
     
     lcd.clear();lcd.setCursor(0,0);lcd.print("Angular");
     lcd.setCursor(0,1);lcd.print("Done :");
     lcd.setCursor(6,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23);
     delay(1000);
     return float(rmcs.Position_Feedback(slave_id))/23.00;
}
