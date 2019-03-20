int LED1 = 13;  //D7
int LED2 = 15;  //D8
void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
}
void loop() {
digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);
 delay(1000);
digitalWrite(LED1, HIGH);
digitalWrite(LED2, HIGH);
 delay(1000);
}
