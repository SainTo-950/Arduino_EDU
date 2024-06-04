#include <WiFiEspAT.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3); // TX, RX

// ssid = 와이파이 이름
// pass = 와이파이 비밀번호
const char ssid[] = "";
const char pass[] = "";

void setup() {

  Serial.begin(9600);
  while (!Serial);

  Serial1.begin(9600);
  WiFi.init(Serial1);

  // 와이파이 모듈과 통신에 실패하는지 확인
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    // 실패했다면 아두이노의 시리얼포트 옆의 빨간 버튼을 눌러줍니다
    while (true);
  }

  Serial.println("Scanning available networks...");
  listNetworks();
}

void loop() {
  delay(10000);
  Serial.println("Scanning available networks...");
  listNetworks();
  Serial.print("SSID : ");
  Serial.print(ssid);
  Serial.print(" PW : ");
  Serial.println(pass);

  // 설정한 와이파이 이름과 비밀번호로 접속 시도
  int status = WiFi.begin(ssid, pass);
  if (status == WL_CONNECTED) {
    Serial.println();
    Serial.println("Connected to WiFi network.");
    while(true);
  } else {
    WiFi.disconnect();
    Serial.println();
    Serial.println("Connection to WiFi network failed.");
  }
}

// WiFi 리스트를 보여주는 코드
void listNetworks() {
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1)
  {
    Serial.println("Couldn't get a WiFi connection");
    while (true);
  }

  Serial.print("number of available networks: ");
  Serial.println(numSsid);

  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet + 1);
    Serial.print(") ");
    Serial.print("Signal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tSSID: ");
    Serial.println(WiFi.SSID(thisNet));
    Serial.flush();
  }
  Serial.println();
}
