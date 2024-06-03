#include <SoftwareSerial.h>

// 2번 3번을 시리얼 포트로 추가
SoftwareSerial mySerial(2, 3); // TX, RX

void setup() {
  Serial.begin(9600);
  // mySerial.begin(115200);
  mySerial.begin(9600);
  Serial.println("Wi-Fi Connection Start!");
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }

  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
