#include <DHT11.h>
#include <LCDIC2.h>

// 온/습도 센서 Pin 2로 설정
DHT11 dht11(2);

// LCD 패널 Init
LCDIC2 lcd(0x27, 16, 2);

void setup() {
  // Serial Monitor 사용, 9600 Rate
  Serial.begin(9600);
  // LCD 사용
  lcd.begin();
}

void loop() {
  // LCD 화면 클리어
  lcd.clear();
  int temperature = 0;
  int humidity = 0;

  // 온습도 센서에서 값을 읽어들여 옴
  int result = dht11.readTemperatureHumidity(temperature, humidity);
  if (result == 0) {
      // 온도 값 Serial에 출력
      Serial.print("Temperature: ");
      Serial.print(temperature);
      // LCD 커서를 0, 0으로 옮김
      lcd.setCursor(0, 0);
      // 온도 값 String 형으로 변환
      String temp = String(temperature);
      // LDC에 출력
      lcd.print("TEMP : " + temp);
      lcd.print(" C");
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
      Serial.println(" %");
      lcd.setCursor(0, 1);
      String hum = String(humidity);
      lcd.print("HUM : " + hum);
      lcd.print(" %");
  } else {
      Serial.println(DHT11::getErrorString(result));
  }
  delay(3000);
}
