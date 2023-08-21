/*#include <Servo.h>

Servo myservo;  // 서보모터 객체 생성
int switchPin = 2;  // 스위치 핀 설정
int pos = 0;  // 서보모터 각도 변수
int switchState = 0;  // 스위치 상태 변수
int lastSwitchState = 0;  // 이전 스위치 상태 변수

void setup() {
  myservo.attach(9);  // 서보모터를 9번 핀에 연결
  pinMode(switchPin, INPUT);  // 스위치 핀을 입력으로 설정
}

void loop() {
  switchState = digitalRead(switchPin);  // 스위치 상태 읽기

  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      pos = 30;  // 스위치가 눌렸을 때 서보모터 각도를 30도로 설정
    } else {
      pos = 0;  // 스위치가 해제되면 서보모터 각도를 0도로 설정
    }
    myservo.write(pos);  // 서보모터를 지정한 각도로 회전
    delay(15);  // 서보모터가 움직이는 동안 잠시 기다림
  }

  lastSwitchState = switchState;  // 이전 스위치 상태 업데이트
}

#include <Servo.h>

Servo myservo;
int switchPin = 2;  // 스위치 연결 핀
int pos = 0;        // 서보모터의 현재 위치
int targetPos = 30; // 목표 회전 각도

void setup() {
  myservo.attach(9); // 서보모터 핀을 9번에 연결
  pinMode(switchPin, INPUT_PULLUP); // 내부 풀업 저항 사용하여 스위치 연결
}

void loop() {
  int switchState = digitalRead(switchPin); // 스위치 상태 읽기

  if (switchState == LOW) { // 스위치가 눌렸을 때
    for (pos = 0; pos <= targetPos; pos += 1) { // 서보모터 회전
      myservo.write(pos);
      delay(15);
    }
    delay(500); // 0.5초 딜레이
    for (pos = targetPos; pos >= 0; pos -= 1) { // 서보모터 원위치로 회전
      myservo.write(pos);
      delay(15);
    }
  }
}


#include <Servo.h>

Servo myservo;
int pos = 70;        // 서보모터의 현재 위치
int targetPos = 140; // 목표 회전 각도

void setup() {
  myservo.attach(9); // 서보모터 핀을 9번에 연결
}

void loop() {
  myservo.write(targetPos); // 30도 회전
  delay(1000);               // 0.5초 딜레이
  myservo.write(70);         // 원위치로 회전
  delay(3000);         // 0.5초 딜레이
  
}

const int switchPin = 2;  // 스위치 핀
const int ledPin = 13;    // LED 핀

void setup() {
  pinMode(switchPin, INPUT);  // 스위치 핀을 입력 모드로 설정
  pinMode(ledPin, OUTPUT);    // LED 핀을 출력 모드로 설정
}

void loop() {
  int switchState = digitalRead(switchPin);  // 스위치 상태 읽기

  if (switchState == HIGH) {
    digitalWrite(ledPin, HIGH);  // 스위치가 눌려지면 LED 켜기
  } else {
    digitalWrite(ledPin, LOW);   // 스위치가 눌려지지 않으면 LED 끄기
  }
}*/


#include <Servo.h>

Servo myservo;  // 서보모터 객체 생성
int switchPin = 2;  // 스위치 핀 설정
int pos = 0;  // 서보모터 각도 변수
int switchState = 0;  // 스위치 상태 변수
int lastSwitchState = LOW;  // 이전 스위치 상태 변수

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // 서보모터를 9번 핀에 연결
  pinMode(switchPin, INPUT);  // 스위치 핀을 입력으로 설정
}

void loop() {
  switchState = digitalRead(switchPin);  // 스위치 상태 읽기
  //Serial.println(switchState);


  delay(100);   
  if(switchState != lastSwitchState){
      Serial.println("change");

      if(switchState){
        myservo.write(180);
        delay(1000);               // 0.5초 딜레이
        myservo.write(0);  
      }
      else{
        myservo.write(180);
        delay(1000);               // 0.5초 딜레이
        myservo.write(0);  
      }
      lastSwitchState = switchState;
  }

}


