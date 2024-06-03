void setup() {
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);
  // 7번 핀을 Digital Input으로 설정
  pinMode(7, INPUT);
}

void loop() {
  int readValue = digitalRead(7);
  // 시리얼 모니터에 값 출력
  Serial.println(readValue);

  // 7번 핀에서 읽은 값에 따라 LED On/Off 제어
  if (readValue == HIGH) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
