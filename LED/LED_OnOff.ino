// 아두이노 시작 시 설정을 넣는 부분
void setup() {
  // 8번 Pin의 Mode를 OUTPUT으로 설정
  pinMode(8, OUTPUT);
}

// 무한루프가 돌며 프로세스를 실행하는 부분
void loop() {
  // 8번 Pin에 HIGH 값을 대입 (LED ON)
  digitalWrite(8, HIGH);
  // 1초간 대기
  delay(1000);

  // LED OFF
  digitalWrite(8, HIGH);
  delay(1000);
}
