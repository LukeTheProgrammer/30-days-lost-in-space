int LED1 = 10;
int LED2 = 11;
int LED3 = 12;
int Switch1 = 2; 
int Switch2 = 3;
int Switch3 = 4;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
}

void flashLED(int LED, int SWITCH) {
  if (digitalRead(SWITCH) == HIGH) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  } else {
    digitalWrite(LED, LOW);
  }
}

void blinkenLights(int LED) {
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);
}

void loop() {
  // flashLED(LED1, Switch1);
  // flashLED(LED2, Switch2);
  // flashLED(LED3, Switch3);
  if (digitalRead(Switch1) == HIGH) {
    // digitalWrite(LED1, HIGH);
    blinkenLights(LED1);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(Switch2) == HIGH) {
    // digitalWrite(LED2, HIGH);
    blinkenLights(LED2);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(Switch3) == HIGH) {
    // digitalWrite(LED3, HIGH);
    blinkenLights(LED3);
  } else {
    digitalWrite(LED3, LOW);
  }
}