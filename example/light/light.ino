#define BLINKER_WIFI
#include <Blinker.h>

char auth[] = "df4bc64e12f3";
char ssid[] = "YLY";
char pswd[] = "yly060311";
BlinkerButton Button1("btn-huy");
BlinkerText Text1("tex-r15");
BlinkerText Text2("tex-nc1");
BlinkerNumber Number1("num-q3n");
BlinkerSlider Slider1("ran-by9");
bool tmp=true;
void setup() {
    Serial.begin(115200);
    //BLINKER_DEBUG.stream(Serial);
    //BLINKER_DEBUG.debugAll();
    Blinker.begin(auth, ssid, pswd);
    //Blinker.attachData(dataRead);
    Button1.attach(button1_callback);
    Slider1.attach(slider1_callback);
    Blinker.attachData(dataRead);
  
}

void loop() {
  Blinker.run();
  delay(1000);
}
void dataRead(const String & data)
{
  Serial.print("input:");
  Serial.println(data);
  }
void button1_callback(const String & state)
{
    Number1.unit("m");
    Number1.print(rand());
    Text1.print("HELLO");
    tmp=!tmp;
    if(tmp)
    {
      Text1.print("HELLO");
      Text2.print("WORLD");
      Button1.print("on");
    }
    else
    {
      Text2.print("HELLO");
      Text1.print("WORLD");
      Button1.print("off");
    }

    
}    
void slider1_callback(int32_t value)
{
    Serial.print("slider:");
    Serial.println(value);
}
