int latchPin = 5;
int clockPin = 4;
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
void WriteData (int Data,int DP)
{
  if (DP==2)
  {
    digitalWrite(5,LOW); 
    shiftOut(DP,4,MSBFIRST,Data);
    digitalWrite(5,HIGH);  
  }
  else 
  {
    digitalWrite(7,LOW); 
    shiftOut(DP,6,MSBFIRST,Data);
    digitalWrite(7,HIGH);  
  }
}
void WriteNumber (int num)
{
  switch (num)
  {
    case 0: {WriteData (3,2);break;}
    case 1: {WriteData (159,2);break;}
    case 2: {WriteData (37,2);break;}
    case 3: {WriteData (13,2);break;}
    case 4: {WriteData (153,2);break;}
    case 5: {WriteData (73,2);break;}
    case 6: {WriteData (65,2);break;}
    case 7: {WriteData (31,2);break;}
    case 8: {WriteData (1,2);break;}
    case 9: {WriteData (9,2);break;}

  }
}
void WriteDigit (int digit)
{
  switch (digit)
  {
    case 1: {WriteData (128,3);break;}
    case 2: {WriteData (64,3);break;}
    case 3: {WriteData (32,3);break;}
    case 4: {WriteData (16,3);break;}
  }
}
void loop()
{
  while (1)
  {
    WriteDigit(1);
    WriteNumber(1);
    delay(5);
    WriteDigit(2);
    WriteNumber(2);
    delay(5);
    WriteDigit(3);
    WriteNumber(3);
    delay(5);
    WriteDigit(4);
    WriteNumber(4);
    delay(5);
  }

}
