int LED = 12;
int Switch1 = 2; 

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Switch1, INPUT);
}
 
void loop() {
  if (digitalRead(Switch1) == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}