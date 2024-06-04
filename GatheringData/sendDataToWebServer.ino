// 서버 Host 주소를 입력합니다. (혹은 IP)
const char* server = "192.168.178.92";

// Client 객체 선언
WiFiClient client;

void sendData() {
  if (WiFi.status() != WL_CONNECTED) {
    return;
  }

  if (!client.connected()) {
    Serial.println("Server connection lost. Reconnecting...");
    if (client.connect(server, 8080)) {
      Serial.println("Reconnected to server");
    } else {
      Serial.println("Failed to reconnect to server");
    }
  }

  Serial.println("Starting connection to server....");
  if (client.connect(server, 8080)) {
    String dvcId = "ARD_01";
    String detct = String(isDetected);
    String temp = String(tempHum[0]);
    String hum = String(tempHum[1]);

    String sendMsg = "GET /gatheringData?DVC_ID=" + dvcId
                   + "&DETCT=" + detct
                   + "&TEMP=" + temp
                   + "&HUM=" + hum;
    Serial.println(sendMsg);

    client.println(sendMsg);
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.flush();
  }

  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  Serial.println();
}
