void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (C == 1) Forward(MotorSpeed, 1);
  else if (L2 == 0) TL(70);
  else if (L1 == 0) TL(50);
  else if (R2 == 0) TR(70);
  else if (R1 == 0) TR(50);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while (L2 == 1 || R2 == 1) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //ถอยหลังอีกนิดตาม Time
  
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
