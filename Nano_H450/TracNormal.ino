void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (a4 == 0 and a3 == 0) Forward(MotorSpeed, 1);
  else if (a7 == 0) tl(150);
  else if (a6 == 0) tl(100);
  else if (a5 == 0) tl(70);
  else if (a4 == 0) tr(50);
  
  else if (a0 == 0) tr(150);
  else if (a1 == 0) tr(100);
  else if (a2 == 0) tr(70);
  else if (a3 == 0) tr(50);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, Time);
  ConvertADC();
  while (a6 == 1  || a1 == 1) { //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}


void TracNormalTime(int MotorSpeed, int Time) { //แทรกเส้นธรรมดา แบบหน่วงเวลา
  ResetTimer0();
  Forward(MotorSpeed, 1);
  while (Timer0 < Time) {
    Trac(MotorSpeed);
    ReadTimer0();
  }
}
