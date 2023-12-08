void TracPID()  //แทรกเส้นนแบบ PID 5 เซนนเซอร์
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(Error) <= 3) KpTemp = 0; else KpTemp = Kp;

  Output = (KpTemp * Error) + (Ki * Integral) + Kd * (Error - PreError);  //สมการ PID
  LeftOutput = LeftSpeed + Output;      //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeed) LeftOutput = MaxSpeed;
  if (RightOutput > MaxSpeed) RightOutput = MaxSpeed;
  if (LeftOutput < 0) LeftOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0; //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  fd2(LeftOutput, RightOutput);  //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreError = Error; //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  Integral += Error;  //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracJC(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeed(MotorSpeed);
  CalError();
  while (Error < 100) {  //ยังไม่เจอแยก ให้ทำการ TracPID
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

void TracPIDback()  //แทรกเส้นนแบบ PID 5 เซนนเซอร์
{
  int Output, LeftOutput, RightOutput, KpTemp;

  if (abs(ErrorB) <= 2) KpTemp = 0; else KpTemp = KpB;

  Output = (KpTemp * ErrorB) + (KiB * IntegralB) + KdB * (ErrorB - PreErrorB);  //สมการ PID
  LeftOutput = LeftSpeed + Output;      //ความเร็วมอเตอร์ด้านซ้าย +
  RightOutput = RightSpeed - Output;      //ความเร็วมอเตอร์ด้านขวา -

  if (LeftOutput > MaxSpeedB) LeftOutput = MaxSpeedB;
  if (RightOutput > MaxSpeedB) RightOutput = MaxSpeedB;
  if (LeftOutput < 0) LeftOutput = 0;   //ถ้าน้อยกว่า 0 ให้มอเตอรซ้ายหยุด
  if (RightOutput < 0) RightOutput = 0; //ถ้าน้อยกว่า 0 ให้มอเตอรขวาหยุด

  bk2(LeftOutput, RightOutput);  //ส่งให้มอเตอร์เคลื่อนที่ตามมอเตอร์ซ้าย/ มอเตอร์ขวา
  PreErrorB = ErrorB; //กำหนด Error ปัจจุบันให้เเท่ากับ Error ก่อนหน้านี้
  IntegralB += ErrorB;  //บวกผลรวมของ Error ไปเรื่อยๆ
}

void TracBW(int MotorSpeed, int Time) {  //แทรกเส้นแบบ PID
  InitialSpeedB(MotorSpeed);
  CalErrorBack();
  while (ErrorB < 100) {  //ยังไม่เจอแยก ให้ทำการ TracPID
    TracPIDback();
    CalErrorBack();
  }
  Backward(MotorSpeed, Time);
}
