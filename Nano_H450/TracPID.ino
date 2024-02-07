void TracPID()  //แทรกเส้นนแบบ PID 7 เซนนเซอร์
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(Error) <= 3) KpTemp = 1; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);    //สมการ PID
  LeftOutput = LeftSpeed + Output;      //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;    //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;     //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด
  fd(LeftOutput, RightOutput);           //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/มอเตอร์ขวา
  PreError = Error;     //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;    //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJC(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeed(MotorSpeed);
  CalError();
  while (Error < 100) {   //ยังไม่เจอแยก ให้ทำการ TracPID
    // CheckObstacle();    //เช็คสิ่งกีดขวาง
    TracPID();
    CalError();
  }
  Forward(MotorSpeed, Time);
}

void TracTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  InitialSpeed(MotorSpeed);
  while (Timer0 < Time) {
    CalError();
    TracPID();
    ReadTimer0();
  }
}


//void CheckObstacle() {  //ฟังก์ชั่นเช็คสิ่งกีดขวาง
//  ConvertADC();
//  if (Dist <= 20) {
//    ao();
//    //beep();
//    delay(500);
//    sr(45);     //หมุนขวา
//    delay(200);
//    fd(25, 65);  //(Left,Right)
//    delay(1200);
//    //sl(20);
//    //delay(150);
//    //fd(30);
//    while (A4 == 1) {
//      ConvertADC();
//    };
//  }
//}
