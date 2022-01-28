#include <TM1637.h>
// Pin 3 - > DIO
// Pin 2 - > CLK
TM1637 tm1637(2, 3);

void setup() {
  tm1637.init();
    tm1637.setBrightness(5);
  // put your setup code here, to run once:
  
}

void loop() {
  tm1637.display(12 4);
 tm1637.switchColon();
    delay(1000);

}
