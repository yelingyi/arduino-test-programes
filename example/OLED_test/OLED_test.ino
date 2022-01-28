#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();
  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(40,10, "Mashiro");
  u8g2.drawBox(0,0,10,5);
  u8g2.drawFrame(0,54,10,5);
  u8g2.drawBox(118,0,10,5);
  u8g2.drawFrame(118,54,10,5);
  u8g2.drawDisc(32,31,15);
  u8g2.drawCircle(96,31,15);
  u8g2.drawRFrame(5, 10,120,45, 20);
  //u8g2.drawRBox(5, 10,120,45, 20);
  u8g2.drawLine(32, 31, 96, 31);
  u8g2.drawTriangle(96,16, 85,42, 108,42);
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawUTF8(62, 47, "☁");
  u8g2.sendBuffer();
}
