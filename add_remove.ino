String backspace(String num)
{
  if(num.length() == 1 || num.length() == 0){num = "";}
  else{num = String(num.toInt()/10);}
  return num;  
}

String enter_num(String num,char new_num)
{
  if(new_num == '*'){}
  else
  {
    if(num.length() == 0){num = new_num;}
    else{num = num + new_num;}
    return num;
  }
}
