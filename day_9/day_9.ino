int sensorPin = A0;
int sensorValue = 0;
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}
 
void RGB_color(int red_value, int green_value, int blue_value) {
  analogWrite(redPin, red_value);
  analogWrite(greenPin, green_value);
  analogWrite(bluePin, blue_value);
}

double getBatteryPercentage() {
  return (
    ((double)batteryLevel / (double)batteryCapacity) * 100
  );
}

void ShowBatteryPercentage() {
  PercentFull = getBatteryPercentage();
 
  // print the elasped time
  Serial.print(ticks);
  Serial.print(" ms charge at ");
  
  // print the percent charge
  Serial.print(PercentFull);
  
  // print a percent character and line return...
  Serial.println("%");
 
  // Now let's light the LED with the appropriate color...
  if (PercentFull > 0 && PercentFull <= 25) {
    RGB_color(125, 0, 0); // red
  } else if (PercentFull > 25 && PercentFull <= 50) {
    RGB_color(125, 80, 0); // yellow-ish
  } else if (PercentFull > 50 && PercentFull <= 75) {
    RGB_color(0, 125, 125); // blue-ish
  } else if (PercentFull > 75 && PercentFull < 100) {
    RGB_color(125, 125, 125); // white
  }
}

void showBatteryFull() {
  Serial.print(ticks);
  Serial.print(" ms ");
  Serial.println("FULLY CHARGED");
  batteryLevel = batteryCapacity;
  ticks = 0;
  RGB_color(0, 125, 0);
  delay(30000);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  batteryLevel += (sensorValue * 0.25);
  ticks += wait;
 
  if (batteryLevel >= batteryCapacity) {
    showBatteryFull();
  } else {
    ShowBatteryPercentage();
  }
 
  delay(wait);
}