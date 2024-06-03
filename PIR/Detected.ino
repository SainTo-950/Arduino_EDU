#define SNSR 7 // HC-SR505 D7번 연결

void setup() {
  // Serial Monitor 사용, 9600 Rate
  Serial.begin(9600);
  
  pinMode(SNSR, INPUT);
  digitalWrite(SNSR, LOW);

  pinMode(8, OUTPUT);
}

void loop() {
  if (digitalRead(SNSR) == HIGH) {
    Serial.println("Movement detected...");
    digitalWrite(8, HIGH);
  } else {
    Serial.println("Nothing.");
    digitalWrite(8, LOW);
  }
  delay(1000);
}
