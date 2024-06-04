#define SNSR 4 // HC-SR505 D7번 연결
#define DLED 8 // LED 8번 Pin

void detectedSetup() {
  pinMode(SNSR, INPUT);
  pinMode(DLED, OUTPUT);
  digitalWrite(SNSR, LOW);
}

void detectedStart() {
  if (digitalRead(SNSR) == HIGH) {
    digitalWrite(DLED, HIGH);
    isDetected = true;
  } else {
    digitalWrite(DLED, LOW);
    isDetected = false;
  }
}
