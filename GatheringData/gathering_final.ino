#include <WiFiEspAT.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(6, 7); // TX, RX

// ssid = 와이파이 이름
// pass = 와이파이 비밀번호
const char ssid[] = "SainTo_HP";
const char pass[] = "@Tp1dls0Xh4$";

int tempArray[2];
bool tempDetected = false;

int tempHum[2];
bool isDetected = false;

void setup() {
  wifiSetup();
  detectedSetup();
}

void loop() {
  // 연결상태 체크
  chkWiFi();
  // 인체 감지
  detectedStart();
  Serial.print("Detected : ");
  Serial.println(isDetected);
  // temp 값 가져옴
  getTempHum();
  Serial.print("Temperature: ");
  Serial.print(tempHum[0]);
  Serial.print(" °C\tHumidity: ");
  Serial.print(tempHum[1]);
  Serial.println(" %");

  chkDiff();
  // 3초 딜레이
  delay(3000);
}

void chkDiff() {
  bool isChange = false;
  if (tempDetected != isDetected) {
    tempDetected = isDetected;
    isChange = true;
  }

  if (tempArray[0] != tempHum[0] || tempArray[1] != tempHum[1]) {
    tempArray[0] = tempHum[0];
    tempArray[1] = tempHum[1];
    isChange = true;
  }
  // 변경 값이 있다면, 서버로 데이터를 보낸다
  if (isChange) {
    Serial.println("Send Data to Web Server");
    sendData();
  }
}
