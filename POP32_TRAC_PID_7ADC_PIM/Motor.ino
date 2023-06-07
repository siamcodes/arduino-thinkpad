void MotorStop() { //มอเตอร์หยุด
  ao();  //มอเตอร์หยุดทั้งหมด
  delay(10); //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time) { //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  // delay(100);
  delay(6000 / TurnSpeed);
  sl(TurnSpeed / 2);
  ConvertADC();
  while (L2 == 1) { //ถ้่าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  //delay(100);    //ปรับค่าให้เลี้ยวตรงเส้น
  delay(6000  / TurnSpeed);
  sr(TurnSpeed / 2);
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnRight() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  //delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  delay(18000 / TurnSpeed);
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnLeft() { //ขวา
  MotorStop();
  sl(TurnSpeed); //หมุนขวา
  //delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  delay(18000 / TurnSpeed);
  ConvertADC();
  while (L2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}



void Left(int Speed , int Time) {
  sl(Speed);
  delay(Time);
  ao();
}

void Right(int Speed , int Time) {
  sr(Speed);
  delay(Time);
  ao();
}

void TurnLeftDelay(int Speed , int Time) {
  tl(Speed);
  delay(Time);
}

void TurnRightDelay(int Speed , int Time) {
  tr(Speed);
  delay(Time);
}


void CurveRight(int MotorSpeed, int Time) //โค้างทางขวาอ้อมสิ่งกีดขวาง
{
  MotorStop();
  Right(MotorSpeed, 125);
  fd2(37, MotorSpeed);
  delay(300);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnRight();
}

void CurveLeft(int MotorSpeed, int Time) //โค้างทางขวาอ้อมสิ่งกีดขวาง
{
  MotorStop();
  delay(100);
  Left(MotorSpeed, 125);
  fd2(MotorSpeed, 37);
  delay(100);
  ConvertADC();
  while (L1 == 1) {
    ConvertADC();
  }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnLeft();
}

void CheckObstacle() {  //ฟังก์ชั่นเช็คสิ่งกีดขวาง
  ConvertADC();
  if (Dist <= 20) {
    ao();
    beep();
    delay(500);
    sr(45);     //หมุนขวา
    delay(200);
    fd2(25, 65);
    delay(1200);
    // sl(20);
    // delay(150);
    // fd(30);
    while (L2 == 1) {
      ConvertADC();
    };
  }
}
