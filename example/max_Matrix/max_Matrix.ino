#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);
unsigned long delaytime=1000;
byte a[8]={B10000000,B11000000,B11100000,B11110000,B11111000,B11111100,B11111110,B11111111};
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  lc.setRow(0,5,a[5]);
  lc.setRow(0,6,a[6]);
  lc.setRow(0,7,a[7]);
}
void loop() { 

}
