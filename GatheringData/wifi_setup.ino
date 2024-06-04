#define WLED 9 // LED 9번 Pin

void wifiSetup() {
  pinMode(WLED, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    digitalWrite(WLED, HIGH);
  }

  Serial1.begin(9600);
  WiFi.init(Serial1);

  // 와이파이 모듈과 통신에 실패하는지 확인
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    digitalWrite(WLED, HIGH);
    // 실패했다면 아두이노의 시리얼포트 옆의 빨간 버튼을 눌러줍니다
    while (true);
  }

  // WiFi와의 연결을 기다립니다.
  Serial.println("Waiting for connection to WiFi");  
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WLED, HIGH);
    connectWiFi();
    delay(1000);
    Serial.print('.');
    digitalWrite(WLED, LOW);
  }
  digitalWrite(WLED, LOW);
  Serial.println();

  Serial.println("Connected to WiFi network.");
}

void chkWiFi() {
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WLED, HIGH);
    while(true);
  }
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    digitalWrite(WLED, HIGH);
    while (true);
  }
}

void connectWiFi() {
  // 설정한 와이파이 이름과 비밀번호로 접속 시도
  int status = WiFi.begin(ssid, pass);
  if (status == WL_CONNECTED) {
  } else {
    WiFi.disconnect();
  }
}
