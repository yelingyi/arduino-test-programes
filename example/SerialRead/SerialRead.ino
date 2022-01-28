int x;//缓存函数
String comdata = "";//字符串函数
void setup() {
  Serial.begin(115200);//打开串口波特率9600
}
 
void loop() {
  if (Serial.available() > 0)//判读是否串口有数据
  {
    String comdata = "";//缓存清零
    while (Serial.available() > 0)//循环串口是否有数据
    {
      comdata += char(Serial.read());//叠加数据到comdata
      delay(2);//延时等待响应
    }
    if (comdata.length() > 0)//如果comdata有数据
    {
      Serial.println(comdata);//打印comdata数据
    }
  }
}
