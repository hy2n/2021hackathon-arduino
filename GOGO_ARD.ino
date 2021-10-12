//Arduino Uno//
//2021 HackerTone //

//!! === DO NOT TOUCH PORT THAT HAS CONNECTED === !!//
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>


float Hc_sensor_01 = 0;
float Hc_sensor_02 = 0;
float pass_event = 0;

//=========================================
//Port infomation
//
//Bluetooth 11/12 Rx/Tx
//Sonic 초음파센서 (4,5/10,9)
//RGB PWM (보행자 초록 10번, 빨강 3번) 
//RGB PWM (차량용 초록 11번, 빨강 9번, 노랑 6/5 동시출력)
//
//=========================================

//TR_Car_Mode(Mode)
//Mode 1 = 초록
//Mode 2 = 노랑
//Mode 3 = 빨강
//Mode 미지정 = 전체꺼짐
SoftwareSerial Bluetooth(12,11);

int TR_Car_Mode(int Mode_type) {
  if (Mode_type == 1) {
    //Mode 1 = 초록
    analogWrite(11,255);
    analogWrite(9,0);
    analogWrite(6,0);
    analogWrite(5,0);
  }
  else if (Mode_type == 2) {
    //Mode 2 = 노랭
    analogWrite(11,0);
    analogWrite(9,0);
    analogWrite(6,255);
    analogWrite(5,255);
  }
  else if (Mode_type == 3) {
    //Mode 3 = 빨강
    analogWrite(11,0);
    analogWrite(9,255);
    analogWrite(6,0);
    analogWrite(5,0);
  }
  else {
    //Mode 미지정시 전체 꺼짐
    analogWrite(11,0);
    analogWrite(9,0);
    analogWrite(6,0);
    analogWrite(5,0);
  }
}

float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void TR_Green_On() {
  analogWrite(10,255);
}

void TR_Green_Off() {
  analogWrite(10,0);
}

void TR_Red_On() {
  analogWrite(3,255);
}

int TR_Red_Off() {
  analogWrite(3,0);
}

void TR_Car_Red_Off() {
  analogWrite(5,0);
}




int Bluetooth_send_Go(int RemainTime) { // 블루투스 출력
  if (RemainTime == 0) { 
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("0 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Time ended \n================\n");
  }
  else if (RemainTime == 1) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("1 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 2) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("2 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 3) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("3 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 4) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("4 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 5) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("5 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 6) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("6 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 5) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("4 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go faster! \n================\n");
  }
  else if (RemainTime == 6) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("6 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 7) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("7 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 8) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("8 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 9) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("9 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 10) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("10 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 11) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("11 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 12) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("12 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 13) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("13 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 14) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("14 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 15) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("15 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 16) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("16 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else if (RemainTime == 17) {
    Bluetooth.write("================");
    Bluetooth.write("\n");
    Bluetooth.write("\n");
    Bluetooth.write("17 Seconds\n");
    Bluetooth.write("Remaning\n");
    Bluetooth.write("\n");
    Bluetooth.write("Go! \n================\n");
  }
  else {
    return 0;
  }
}

void Bluetooth_send_Stop() { // 블루투스 출력
  Bluetooth.write("================");
  Bluetooth.write("\n");
  Bluetooth.write("\n");
  Bluetooth.write("Red light!\n");
  Bluetooth.write("Remaning\n");
  Bluetooth.write("\n");
  Bluetooth.write("WAIT!! \n================\n");
}

void stanby() {
  int stanby_in = 1; 
  while (stanby_in == 1) {
    if (Bluetooth.available()) { 
      int stanby_in = 0;
    }
  }
}

void Supersonic_Read() {
  Hc_sensor_01 = getDistance(4,5);
  Hc_sensor_02 = getDistance(10,9);
  Serial.println(Hc_sensor_01);
  Serial.println(Hc_sensor_02);
}

int check_distance(int distance) {
  //목표값을 받아서 2개의 센서의 값지값이 목표값을 넘는지 확인 (목표값은 횡단보도 거리의 80%로 설정)
  //즉 목표값을 넘으면 횡단보도의 80% 이상을 건넌것이다
  if ((Hc_sensor_01 < distance) || (Hc_sensor_02 < distance)) { //두 센서중에 하나라도 목표값을 넘지 못했을때
    delay (100);
    if ((Hc_sensor_01 < distance) || (Hc_sensor_02 < distance)) { //센서값에 오차를 없애기 위해 0.1초뒤에 센서를 재측정한다
      //이 함수가 횡단보도 잔여시간 5초일때 실행돼므로
      //보행한 시간은 11초
      //계산
      int Ex_time = 0;
      int _distance;
      if (Hc_sensor_01 > Hc_sensor_02) { //2개의 센서값 중 가장 가까운 값을 반올림하려 변수에 저장
	      int _distance = round(Hc_sensor_02);
      }
      else if ( Hc_sensor_01 < Hc_sensor_02 ) { //2개의 센서값 중 가장 가까운 값을 반올림하려 변수에 저장
	    int _distance = round(Hc_sensor_01);
      }
      int speed = _distance / 11;
      //계산공식 : 거리 / 시간
      //거리는 cm | 시간은 초 이므로, 속력은 speed cm/s
      //계산식을 int(정수)로 선언함
      //여기서 횡단보도의 총 길이를 Y라고 가정했을때
      //잔여 시간은 (Y - 속력x시간)이다
	  
      int Total_distance = 60; //계산을 위한 총 길이 설정
	    
      Ex_time = (Total_distance - (_distance * 11));
      
      if (Ex_time > 10) {
        //만약 추가 시간이 10초보다 많다면
        Ex_time = 10; //최대 추가할 시간이 10초이므로 10초를 넘겼을시 잔여시간을 10초로 지정함
        }
     }
  }
}

void bluetooth_load() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
}

void pin_load() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A6,OUTPUT);
  pinMode(A7,OUTPUT);
}

void setup() {
  bluetooth_load();
  pin_load();
  stanby(); //블루투스 연결 전까지 대기하는 함수 호출
}

void loop() {
  int Ex_time;
  Bluetooth_send_Stop(); //블루투스 출력 : 정지
  TR_Red_On(); //보행자 빨강 신호 활성화
  TR_Green_Off(); //보행자 초록 신호 비활성화
  TR_Car_Mode(1); //차량용 신호 : 초록
  delay(7000); //7초 대기
  TR_Car_Mode(2); //차량용 신호 : 노랑
  delay(1500); //1.5초 대기
  TR_Car_Mode(3);//차량용 신호 : 빨강
  
  TR_Red_Off();
  TR_Green_On();
  
  for (int i = 16; i > 7; i--)    // 16부터 8까지 감소하면서 9번 반복 (즉 9초동안 초록불을 키고 있는다) 
    {
        Bluetooth_send_Go(i);
        delay(1000);
    }
    Bluetooth_send_Go(7);
    TR_Green_Off();
    delay(500);
    TR_Green_On();
    delay(500);
    Bluetooth_send_Go(6);
    TR_Green_Off();
    delay(500);
    TR_Green_On();
    delay(500);
    Bluetooth_send_Go(6);
    TR_Green_Off();
    delay(500);
    TR_Green_On();
    delay(500);
    Bluetooth_send_Go(5);//횡단보도 잔여시간 5초
    Supersonic_Read(); //보행자의 거리 측정을 위하여 초음파 센서 값 로드
    check_distance(60); //총 길이의 80%의 길이인 60cm를 기준값으로 잡고 미리 만들어둔 함수로 거리 측정,계산 등을 진행
    if (Ex_time > 0) { //만약 추가 시간이 필요하다면 (0보다 크면 추가시간 필요)
      //버저 울리는 코드 (미작성)
      for (int i = Ex_time; i > 0; i--) { //추가시간 동안 반복
        TR_Green_Off();
        delay(500);
        TR_Green_On();
        delay(500);
        Bluetooth_send_Go(i);
      }
    }
    //끝 (loop문이므로 위로 올라가서 다시 실행한다)
}


//TR_Red_On();
//Bluetooth_send_Go(4);
//TR_Green_Off();
//delay(1000);
//Bluetooth_send_Go(3);
//delay(1000);
//Bluetooth_send_Go(2);
//delay(1000);
//Bluetooth_send_Go(1);
//delay(1000);
//Bluetooth_send_Go(0);
//TR_Green_On();
//TR_Red_Off();
//delay(5000);
