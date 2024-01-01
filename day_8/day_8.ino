int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int msDelay = 250;
 
void setup() {
  // set our pins to drive output to the LEDs (runs once) 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void RGB_color(int red_value, int green_value, int blue_value) {
  // custom function to set three PWM color channels to any given mixture
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}
 
void loop() {
  // Cycle through several different color settings 
  RGB_color(125, 0, 0); // Red
  delay(msDelay);
  RGB_color(0, 125, 0); // Green
  delay(msDelay);
  RGB_color(0, 0, 125); // Blue
  delay(msDelay);
  RGB_color(64, 32, 0); // yellow
  delay(msDelay);
  RGB_color(125, 0, 125); // purple
  delay(msDelay);
  RGB_color(125, 125, 125); // white
  delay(msDelay);
}