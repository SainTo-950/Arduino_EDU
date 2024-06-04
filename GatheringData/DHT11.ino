#include <DHT11.h>

// 온/습도 센서 Pin 2로 설정
DHT11 dht11(2);

void getTempHum() {
  int temperature = 0;
  int humidity = 0;

  // 온습도 센서에서 값을 읽어들여 옴
  int result = dht11.readTemperatureHumidity(temperature, humidity);
  if (result == 0) {
      // 온도 값 Serial에 출력
      tempHum[0] = temperature;
      tempHum[1] = humidity;
  } else {
      Serial.println(DHT11::getErrorString(result));
  }
}
