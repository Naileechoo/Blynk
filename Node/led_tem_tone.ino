#include "DHT.h"               
#include <Wire.h>              
#include <SPI.h>  
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);
#define DHTTYPE DHT22
#define DHTPIN  D4
DHT dht(DHTPIN, DHTTYPE, 15);
#include <Adafruit_NeoPixel.h>
#define NUMSLEDs 2
#define PINSLEDs 10
const int buzzer = D8;
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel (NUMSLEDs,PINSLEDs,NEO_RGB + NEO_KHZ800);
void setup ()
{
  pinMode(PINSLEDs,OUTPUT);
  SLEDs.begin();
  SLEDs.show();
  Serial.begin(115200);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(buzzer,OUTPUT);
  delay(1000);
}
void loop() 
{
  float h = dht.readHumidity();     
  float t = dht.readTemperature();  
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from DHT sensor!");
  }
  else
  {
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0, 0);
    OLED.setTextSize(1);
    OLED.println(String("H:") + String(h, 0) + " %");
    OLED.setCursor(0, 30);
    OLED.println(String("T:") + String(t, 0) + " ");
    OLED.write(247);
    OLED.print("C");
    OLED.display();
  }
  if(t<28)
  {
    SLEDs.setPixelColor(0, SLEDs.Color( 0,100, 0));
    SLEDs.show();
    tone(buzzer,100);
  }
  else if(t>27)
  {
    SLEDs.setPixelColor(0, SLEDs.Color( 0, 0,200));
    SLEDs.show();
    tone(buzzer,0);
  }
}
