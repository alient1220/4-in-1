#include"SevSeg.h"
SevSeg sevseg;
int Hour;
int Min;

void setup() 
{
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {8, 9, 10, 11, 12, 13, 14, 15};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins,segmentPins); 
  pinMode(6,INPUT);
  pinMode(17,INPUT);
}

void loop() 
{
  char p6=digitalRead(6);
  char p17=digitalRead(17);
  if(p6 == HIGH)
    Min=Hour=0;
  if(p17 == HIGH)
  {
     Min=Min-1;
     if (Min == -1)
     {
        Min = 59;
        if (Hour == -1) 
          Hour = 23 ;
        else 
          Hour-- ;
     }
  }    
  else
  {
    Min = Min + 1;
    if (Min == 60) 
    {
       Min = 0;
       if (Hour == 24)
          Hour=0;
       else
          Hour++;
    }
  }
  sevseg.setNumber(Hour * 100 + Min, 0);
  for(int i=0;i<500000;i++)
  {
    sevseg.refreshDisplay();
  }
}
