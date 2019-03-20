#define sw1 D3                    // Define D3 as switch pin
#define ledPin1 D0                // Define D0 as LED pin
int st_sw1 = 0;
void setup()
{
  pinMode(ledPin1, OUTPUT);       // Set pin as output
  pinMode(sw1, INPUT);            // set pin as input
}
void loop()
{
  st_sw1 = digitalRead(sw1);      // Read input 
  digitalWrite(ledPin1, not(st_sw1)); // Invert output
}
