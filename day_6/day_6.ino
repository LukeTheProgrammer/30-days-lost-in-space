int sensorPin = A0;   // select the *analog zero* input pin for probing the photoresistor
int onboardLED = 13;  // select the pin for the HERO's built-in LED
int sensorValue = 0;  // variable that we'll use to store the value reading from the sensor
 
void setup() {
 Serial.begin(9600);
 pinMode(onboardLED, OUTPUT);
}
 
void loop() {
  // Serial.println("Hello Earthling");
  // delay(500);
  // Serial.println("Take me to your leader");
  // delay(1000);

  // Pulse the builtin LED for a time determined by the sensor
  sensorValue = analogRead(sensorPin);
  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);
 
  // Read the analog sensor value and send it to serial
  Serial.println(sensorValue);
  delay(sensorValue);
}