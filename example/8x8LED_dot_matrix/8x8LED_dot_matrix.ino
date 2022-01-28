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
void SO(uint8_t dataPin1,uint8_t dataPin2, uint8_t clockPin, uint8_t bitOrder, uint8_t val1,uint8_t val2)
{
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    if (bitOrder == LSBFIRST)
    {
      digitalWrite(dataPin1, !!(val1 & (1 << i)));
      digitalWrite(dataPin2, !!(val2 & (1 << i)));

    }
    else
    {
      digitalWrite(dataPin1, !!(val1 & (1 << (7 - i))));
      digitalWrite(dataPin2, !!(val2 & (1 << (7 - i))));
    }
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}
void WriteData (int Data1,int DP1,int Data2,int DP2)
{
    digitalWrite(5,LOW); 
    SO(DP1,DP2,4,MSBFIRST,Data1,Data2);
    digitalWrite(5,HIGH);  
}
void writeline (int line,int data)
{
  switch (line)
  {
    case 1:{WriteData(127,3,data,2);break;}
    case 2:{WriteData(191,3,data,2);break;}
    case 3:{WriteData(223,3,data,2);break;}
    case 4:{WriteData(239,3,data,2);break;}
    case 5:{WriteData(247,3,data,2);break;}
    case 6:{WriteData(251,3,data,2);break;}
    case 7:{WriteData(253,3,data,2);break;}
    case 8:{WriteData(254,3,data,2);break;}
  }
}
void loop()
{
  int data[8];
  data[0]=170;
  data[1]=85;
  data[2]=170;
  data[3]=85;
  data[4]=170;
  data[5]=85;
  data[6]=170;
  data[7]=85;
  writeline(1,1);
  delay(1);
  writeline(2,1);
  delay(1);
  writeline(3,1);
  delay(1);
  writeline(4,1);
  delay(1);
  writeline(5,1);
  delay(1);
  writeline(6,1);
  delay(1);
  writeline(7,1);
  delay(1);
  writeline(8,1);
  delay(1);
}
