void MotorStop(){ //มอเตอร์หยุด
   ao();  //มอเตอร์หยุดทั้งหมด
   delay(10); //หน่วงเวลา 10 ms
}

void Forward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  fd2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void Backward(int MotorSpeed, int Time){  //เดินหน้าหน่วงเวลา
  InitialSpeed(MotorSpeed);  //กำหนดความเร็วมอเตอร์
  bk2(LeftSpeed, RightSpeed);  //เดินไปข้างหน้า
  delay(Time);
}

void TurnLeft() { //เลี้ยวซ้าย
  MotorStop();
  sl(TurnSpeed); //หมุนซ้าย
  delay(100);
  ConvertADC();
  while (L2 == 1) { //ถ้่าเจอขาวอยู่ วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void TurnRight() { //เลี้ยวขวา
  MotorStop();
  sr(TurnSpeed); //หมุนซ้าย
  delay(100);    //ปรับค่าให้เลี้ยวตรงเส้น
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnRight() { //ขวา
  MotorStop();
  sr(TurnSpeed); //หมุนขวา
  delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (R2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
}

void UTurnLeft() { //ขวา
  MotorStop();
  sl(TurnSpeed); //หมุนขวา
  delay(200);    //ปรับค่าให้เเเลยแยกตัด เพื่อหมุนกลับ
  ConvertADC();
  while (L2 == 1) { //ถ้่าเจอขาวอยู่วนอ่านค่าสีไปเรื่อยๆ จนเจอดำ
    ConvertADC();
  }
  MotorStop();
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
