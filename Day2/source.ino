#include <DHT11.h>

#define LED_PIN 3 // Trig Pin 설정
#define TRIG 9 // Trig Pin 설정
#define ECHO 8 // Echo Pin 설정

// 온/습도 센서 Pin 2로 설정
DHT11 dht11(2);

// 온/습도 변수 값 선언
int temperature = 0;
int humidity = 0;

// 거리 변수 값 선언
long distance = 0;

// Count 변수 값 선언
int detectedCnt = 0;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  long duration = 0;
  // 온습도 센서에서 값을 읽어들여 옴
  int result = dht11.readTemperatureHumidity(temperature, humidity);
  if (result == 0) {
  } else {
      Serial.println(DHT11::getErrorString(result));
  }

  // 초음파 센서 값 읽어들여 옴
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17 /1000;

  Serial.print("Temp : ");
  Serial.print(temperature);
  Serial.print("\tHum : ");
  Serial.print(humidity);
  Serial.print("\tDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");

  // 거리가 10cm 이내면 LED를 켠다
  if (distance <= 10) {
    digitalWrite(LED_PIN, HIGH);
  }

  // LED가 켜져 있는지 확인한다
  if (digitalRead(LED_PIN)) {
    // 켜져있으면 detectedCnt 값을 1 증가시킨다
    detectedCnt++;
  }

  // detectedCnt 값이 3이라면 (3초가 지났을 상황) LED를 끈다
  if (detectedCnt > 3) {
    digitalWrite(LED_PIN, LOW);
    detectedCnt = 0;
  }

  delay(1000);
}
