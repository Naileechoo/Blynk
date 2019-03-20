#include "DHT.h"

 

#define DHTPIN 2

#define DHTTYPE DHT11

 int buzzer_module = 14;  //D5

DHT dht(DHTPIN, DHTTYPE);

 

void setup() {
   Serial.begin(115200); 
   pinMode(buzzer_module, OUTPUT);
   dht.begin();
}
void loop()
{    float t = dht.readTemperature();
   if ( isnan(t)) {

     Serial.println("Failed to read from DHT sensor!");

      return;

   }
   if (t>28)
      digitalWrite(buzzer_module, LOW);
   else
     digitalWrite(buzzer_module, HIGH);

   Serial.print("Temperature: "); 

   Serial.print(t);
   Serial.print(" *C ");
      delay(1000);
}
