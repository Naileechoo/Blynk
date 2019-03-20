//26 red
#include "DHT.h"

 

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int LED1 = 13;  //D7
int LED2 = 15;  //D8
void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
}
 



void loop()
{    float t = dht.readTemperature();
   if ( isnan(t)) {

     Serial.println("Failed to read from DHT sensor!");

      return;

   }
   if (t>26)
      {digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);}
   else
    {digitalWrite(LED1, HIGH);
     digitalWrite(LED2, LOW);}

   Serial.print("Temperature: "); 

   Serial.print(t);
   Serial.print(" *C ");
      delay(1000);
}
