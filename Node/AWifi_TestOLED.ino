#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);
void setup()
{
  Serial.begin(115200);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //initialize with the I2C addr 0x3C (for the 128x64)
}
void loop() {
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(0,0);
  OLED.setTextSize(1);
  OLED.println("Size1");
  OLED.setCursor(35,20);
  OLED.setTextSize(2);
  OLED.println("Size2");
  OLED.display();
}
