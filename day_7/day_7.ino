int sensorPin = A0;   // analog zero input pin
int onboardLED = 13;  // HERO's built-in LED
int sensorValue = 0;
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;

void setup() {
 Serial.begin(9600);
 pinMode(onboardLED, OUTPUT);
}

void PrintBatteryPercentage() {
  // print the elasped time
  Serial.print(ticks);
  Serial.print(" ms  charge at ");
 
  // convert the integers to decimal numbers, divide them and print...
  PercentFull=100*((double)batteryLevel / (double)batteryCapacity);
  Serial.print(PercentFull);
 
  // print a percent character and line return...
  Serial.println("%");
}

void loop() {
  sensorValue = analogRead(sensorPin);

  batteryLevel += sensorValue;
  ticks += wait;
 
  if (batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms     ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity;
    ticks = 0;
    delay(20000);
  } else {
    PrintBatteryPercentage();
  }
 
  delay(wait);
}
