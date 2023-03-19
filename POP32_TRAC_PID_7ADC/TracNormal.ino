void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (C == 0) Forward(MotorSpeed, 1);
  else if (L3 == 0) sl(70);
  else if (L2 == 0) sl(50);
  else if (L1 == 0) sl(30);
  else if (R3 == 0) sr(70);
  else if (R2 == 0) sr(50);
  else if (R1 == 0) sr(30);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, Time);
  ConvertADC();
  while (L2 == 1  || R2 == 1) { //ยังไม่เจอแยก
  //  CheckObstacle();            //เช็คสิ่งกีดขวาง
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

void TracNormalSonar(int MotorSpeed, int Distance) { //แทรกเส้นธรรมดา นเจอวัตถุให้หยุด
  Forward(MotorSpeed, 1);
  while (Sonar > Distance) {  //sonar() > Distance
    Trac(MotorSpeed);
  }
}

void TracNormalTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Forward(MotorSpeed, 1);
  while (Timer0 < Time) {
    Trac(MotorSpeed);
    ReadTimer0();
  }
}
