// 2019.5.10 ————自己写，用舵机库函数控制无刷电机————
// 成功  【舵机45～135，对应1～2ms(50Hz)，对应 反转～正转最高速】
#include<Servo.h>
Servo servo1;
int i = 0;
int time = 100;

void setup() {
	servo1.attach(9);
	delay(100);
	servo1.write(90); // 启动信号：中位
	delay(100);
}

void loop() {
  servo1.write(90);
  delay(2000);
  servo1.write(45);
  delay(4000);
  servo1.write(90);
  delay(2000);
  servo1.write(135);
  delay(4000);

  
  /* ————后面有点问题————
	//delay(2000);
	for(i=90; i<180; i++) {
		servo1.write(i);
		delay(time);
	}
	for(i=180; i>0; i--) {
		servo1.write(i);
		delay(time);
	}
	for(i=0; i<=90; i++) {
		servo1.write(i);
		delay(time);
	}
	delay(2000);
  */
}
