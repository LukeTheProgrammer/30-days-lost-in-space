// Code written by Inventr.io for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure
 
 
int Light = 12; // The HERO Board Pin that the LED is wired to
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Light, OUTPUT);
  digitalWrite(Light, HIGH);
}
 
// the loop function runs over and over again forever
void loop() {
  digitalWrite(Light, LOW);
  delay(1000);
  digitalWrite(Light, HIGH);
  delay(500); 
}