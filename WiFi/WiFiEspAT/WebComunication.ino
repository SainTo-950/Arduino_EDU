#include <WiFiEspAT.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3); // TX, RX

// 서버 Host 주소를 입력합니다. (혹은 IP)
const char* server = "";

// Client 객체 선언
WiFiClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial1.begin(9600);
  WiFi.init(Serial1);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  // WiFi와의 연결을 기다립니다.
  Serial.println("Waiting for connection to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }
  Serial.println();
  Serial.println("Connected to WiFi network.");

  // 서버로 HTTP GET 메시지를 보냅니다.
  Serial.println("Starting connection to server...");
  if (client.connect(server, 8080)) {
    Serial.println("connected to server");

    client.println("GET /connectionTest?Msg=ArduinoConnection");
    // client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.flush();
  }
}

void loop() {

  // if there are incoming bytes available
  // from the server, read them and print them
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();

    // do nothing forevermore
    while (true);
  }
}
