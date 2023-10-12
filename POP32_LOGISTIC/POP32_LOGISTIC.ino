#include <POP32.h>
int L2, L1, C, R1, R2, BL, BC, BR; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL, RefBC, RefBR; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID
int Sonar;

void setup() {
  Speed = 60;  //ความเร็วปกติ 50
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 80
  SlowSpeed = 50; //ความเร็วตอนช้า 50
  TurnSpeed = 65;  //ความเร็วตอนเลี้ยว 60
  beep(1);        //เสียงบัซเซอร์ 0-3

  //GripDown();     //ยกแขนลง
  Put();          //ปล่อย
  Grip();         //คีบ
  //GripUp();       //ยกแขนขึ้น
  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิดเครื่อง
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3
  // Forward(Speed, 1000); //เดินหน้าหน่วงเวลา
  // Backward(Speed,1000);
  //TurnLeft();
  // TurnRight();
   //UTurn();
  // TracNormalJC(Speed,50);
  // TracNormalBW(Speed,80);
   //MotorStop();
  ResetTimer1();  //เปิดใช้งานคู่กับ Finish()
}

void loop() {
  // TracNormalJC(Speed,1);
  // TracJC(Speed,0);
  logistic();
  Finish();
}
