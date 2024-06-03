#define TRIG 9 // Trig Pin 설정
#define ECHO 8 // Echo Pin 설정

void setup() {
  // Serial Monitor 사용, 9600 Rate
  Serial.begin(9600);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 물체에 반사되어 돌아온 초음파의 시간을 변수에 저장
  duration = pulseIn(ECHO, HIGH);

  /* 원래 사용되는 수식은 다음과 같습니다.
     34000 * (초음파가 물체로부터 반사되어 돌아오는 시간) / 1000000 / 2
     2를 나누는 이유는 황목값이 아니라 편도 값을 계산해야하기 때문입니다.
     아래 식은 위 식을 단순화 하여 cm로 환산하고 있습니다.
  */
  distance = duration * 17 /1000;

  Serial.println(duration );
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" Cm");

  delay(1000);
}
