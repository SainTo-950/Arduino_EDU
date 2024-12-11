#include "WiFiS3.h"
//#include "arduino_secrets.h" 

#define WIFI_LED 3
#define DECT_LED 4

int tempArray[2];
bool tempDetected = false;
int tempHum[2];

long distance = 0;
bool isDetected = false;
int detct = 0;
int detectedCnt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(WIFI_LED, OUTPUT);
  pinMode(DECT_LED, OUTPUT);
  digitalWrite(WIFI_LED, HIGH);
  wifiSetup();
  usSetip();
}

void loop() {
  // put your main code here, to run repeatedly:
  // 연결상태 체크
  chkWiFi();
  getTempHum();
  Serial.print("Temperature: ");
  Serial.print(tempHum[0]);
  Serial.print(" °C\tHumidity: ");
  Serial.print(tempHum[1]);
  Serial.println(" %");
  detectUs();

  chkDiff();
  delay(1000);
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