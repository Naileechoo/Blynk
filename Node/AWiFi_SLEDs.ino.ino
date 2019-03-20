#include <Adafruit_NeoPixel.h>
#define NUMSLEDs 2
#define PINSLEDs 10
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel (NUMSLEDs,PINSLEDs,NEO_RGB + NEO_KHZ800);
void setup ()
{
  pinMode(PINSLEDs,OUTPUT);
  SLEDs.begin();
  SLEDs.show();
}
void loop()
{
  int val = map(analogRead(A0),0,1023,0,255);
  SLEDs.setPixelColor(0, SLEDs.Color( 0,val, 0));
  SLEDs.setPixelColor(1, SLEDs.Color(val,val, 0));
  SLEDs.show();
}
