void home_posn()
{
   int slave_id = 7;
  
   rmcs.Absolute_position(slave_id,0);
   lcd.setCursor(0,1);lcd.print("Angle:");
   while(1)       //Keep reading positions. Exit when reached.
   {
      lcd.setCursor(6,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23.00);
      delay(10);
      
      if(rmcs.Position_Feedback(slave_id)==0)
      {
         Serial.println(F("Home Position reached"));
         lcd.setCursor(0,0);lcd.print("ANGL");
         lcd.setCursor(0,1);lcd.print("Done :");
         lcd.setCursor(6,1);lcd.print(float(rmcs.Position_Feedback(slave_id))/23);
         break;
      }
   }
   delay(2000);
}
