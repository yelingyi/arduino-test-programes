#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <TouchScreen.h>
#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif
#define YP A1
#define XM A2
#define YM 29
#define XP 28 
#define TS_MINX 920
#define TS_MINY 120
#define TS_MAXX 150
#define TS_MAXY 940
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BOXSIZE 120
#define PENRADIUS 3
#define MINPRESSURE 10
#define MAXPRESSURE 1000
int oldcolor, currentcolor;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("Paint!"));
  tft.reset();
  tftidentify();
  tft.begin(tft.readID());
  tftdrawinterface();
  pinMode(13, OUTPUT);
  pinMode(30, OUTPUT);
  digitalWrite(30,HIGH);
}
void tftidentify()
{
  uint16_t identifier = tft.readID();
  if(identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if(identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    return;
  }
}
void tftdrawinterface()
{
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
  tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, BLUE);
  tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
  tft.setTextColor(WHITE);
  tft.setCursor(35, 45);
  tft.setTextSize(4);
  tft.println("ON");
  tft.setCursor(150, 45);
  tft.setTextSize(4);
  tft.println("OFF");
  currentcolor = RED;
}
void loop()
{
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    if (p.y < (TS_MINY-5)) {
      Serial.println("erase");
      // press the bottom of the screen to erase 
      tft.fillRect(0, BOXSIZE, tft.width(), tft.height()-BOXSIZE, BLACK);
    }
    // scale from 0->1023 to tft.width
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
    p.x = 240 -p.x;
    p.y = 320 -p.y;
    Serial.print("("); Serial.print(p.x);
    Serial.print(", "); Serial.print(p.y);
    Serial.println(")");
    if (p.y < BOXSIZE) {
       oldcolor = currentcolor;
       if (p.x < BOXSIZE) { 
         currentcolor = RED; 
         tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
         Serial.println("ON");
         digitalWrite(30,HIGH);
       } else if (p.x < BOXSIZE*2) {
         currentcolor = BLUE;
         tft.drawRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, WHITE);
         Serial.println("OFF");
         digitalWrite(30,LOW);
       }
       if (oldcolor != currentcolor) {
          if (oldcolor == RED)
          {
            tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
            tft.setCursor(35, 45);
            tft.setTextSize(4);
            tft.println("ON");
            tft.setCursor(150, 45);
            tft.setTextSize(4);
            tft.println("OFF");
            tft.drawRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, WHITE);
          }
          if (oldcolor == BLUE)
          {
            tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, BLUE); 
            tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
            tft.setCursor(35, 45);
            tft.setTextSize(4);
            tft.println("ON");
            tft.setCursor(150, 45);
            tft.setTextSize(4);
            tft.println("OFF");
            tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
          }
       }
       delay(100);
    }
  }
}