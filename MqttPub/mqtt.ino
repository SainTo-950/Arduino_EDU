// MQTTClient 라이브러리를 라이브러리 매니저에서 다운받으세요.
#include <MQTTClient.h>
// Arduino UNO R4 기준 라이브러리
#include <WiFiS3.h>

WiFiClient wifiClient;    // MQTT Pub에 사용할 wifi client 정의
const char* serverURL = "192.168.0.38";    // Server IP 정의

MQTTClient mqtt = MQTTClient(256);    // MQTT Client 객체 정의

// MQTT Client Setting
void setPubClient() {
  mqtt.begin(serverURL, 1883, wifiClient);

  while(!mqtt.connect("arduino", "", "")) {
    Serial.print(".");
    delay(100);
  }
}

// Data Publish
void publishData() {
  mqtt.loop();
  Serial.println("Data publish");
  // {Topic} / {Msg} 형태입니다.
  mqtt.publish("test/ArduinoTopic", "Message");
}

void setup() {
  // 이전에 WiFi 연결 과정이 필요합니다.
  setPubClient();
}

void loop() {
  publishData();
}
