#include <POP32.h>
int L3, L2, L1, C, R1, R2, R3, Dist; //ตัวแแปรเก็บค่าเซนนเซอร์
int RefL3, RefL2, RefL1, RefC, RefR1, RefR2, RefR3; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID
int Sonar;

void setup() {
  Speed = 50;  //ความเร็วปกติ 70
  ACCSpeed = 100;  //ความเร็วตอนเร่ง 100
  SlowSpeed = 40; //ความเร็วตอนช้า 50
  TurnSpeed = 60;  //ความเร็วตอนเลี้ยว 70

  //ShowLCD();      //แสดงค่าเริ่มต้น LCD ตอนเปิิดเครื่อง
  beep(1);        //เสียงบัซเซอร์ 0-3
  ShowADC();     //แสดงค่าที่อ่านจากเซนเซอร์
  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์สี
  sw_ok_press();  //รอจนกว่าจพกดปุ่ม ok
  beep(1);        //เสียงบัซเซอร์ 0-3

  //Forward(Speed, 100); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็นนเวลา 2 วินาที
  //TracJC(Speed, 0);
  //TurnRight();
  //TracJC(Speed, 40);
  //TurnLeft();
  // UTurn();
  // TracNormalJC(Speed, 50);
  // TracNomalTime(ACCSpeed,1000);
  //MotorStop();
  //ResetTimer1();
  // InitialSpeed(Speed);  //ทดสอบวิ่งที่ 50 เปิดใช้คู่กับ CalError() และ TracPID() ที่อยู่ใน loop()
}

void loop() {
  //Forward(Speed, 100); //เดินหน้าหน่วงเวลา วิ่งที่ 50% เป็นนเวลา 2 วินาที
  //-TracJC(Speed, 0);
  // TracNormalJC(Speed,200);
  //TracJC(Speed, 50);
  //MRC();
  PIM();
  Finish();
}
