int buzzer_module = 14;  //D5
void setup() {
pinMode(buzzer_module, OUTPUT);
}
void loop() {
digitalWrite(buzzer_module, HIGH);
 delay(1000);
digitalWrite(buzzer_module, LOW);
 delay(1000);
}
