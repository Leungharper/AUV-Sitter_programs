// 2019.5.10 ————遥控（输入引脚高低电平）控制单个无刷电机————
// 成功  【舵机45～135，对应1～2ms(50Hz)，对应 反转～正转最高速】
#include<Servo.h>
Servo servo1;
#define PinFront 4
#define PinBack 5

int in_front = 2;   int in_back = 2;

void setup() {
  //Serial.begin(9600);
	servo1.attach(9);
	delay(100);
	servo1.write(90); // 启动信号：中位
	delay(100);
  //Serial.println("Initialized!");
  pinMode(PinFront, INPUT);
}

void MoveFront(){
  servo1.write(135);
}
void MoveBack(){
  servo1.write(45);
}

void loop() {
  in_front = digitalRead(PinFront);
  in_back  = digitalRead(PinBack );
  if ( in_front==0 & in_back==0 ) {
    servo1.write(90);
  }
  if ( in_front==1 ) {
    MoveFront();
  }
  if ( in_back==1 ) {
    MoveBack();
  }
}

