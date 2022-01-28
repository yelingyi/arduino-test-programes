#include <Adafruit_TFTLCD.h>
#include <Adafruit_GFX.h>
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
void setup() {
  Serial.begin(9600);
  Serial.println(tft.width());
  Serial.println(tft.height());
  tft.reset();
  Serial.println(tft.readID());
  tft.begin(tft.readID());
  tft.fillScreen(0x0000);
  tft.setTextColor(0x2FE8);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("Shiina Mashiro");
  //tft.drawLine(x1, y1, x2, y2, color);
  tft.fillRect(50, 100, 100, 100, 0x0FE2);
  tft.drawLine(50, 100, 150, 200, 0xF2DF);
  tft.drawLine(150, 100, 50, 200, 0xF2DF);
  tft.drawFastVLine(100, 100,100, 0xF2DF);
  tft.drawFastHLine(50, 150,100, 0xF2DF);
  tft.drawRect(50, 100, 100, 100, 0xF2DF);
  tft.drawCircle(100, 150, 50, 0xF2DF);
  tft.drawTriangle(100,100,65,185,135,185,0xF2DF);
  tft.drawRoundRect(25, 75, 150, 150, 150/5, 0xF2DF);
}
void loop() {

}
