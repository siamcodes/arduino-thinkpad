void CN1()     //สนามที่บ้าน
{
  Forward(Speed, 50);       //เดินจากจุดเริ่มต้น 200
//  TracNormalJC(Speed, 100);      //ข้ามแยก
//  TracNormalJC(Speed, 50);   //แทรกเดินเตรีียมเลี้ยว
//  TurnRight();                   //เลี้ยว
//  TracNormalJC(Speed, 100);      //ข้ามแยก
//  TracNormalJC(Speed, 50);
//  TurnLeft();                   //เลี้ยว
//  TracNormalJC(Speed, 100);    //ข้ามแยก
//  TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว
//  TurnLeft();                   //เลี้ยว
//  TracNormalJC(Speed, 50);      //แทรกเดินเตรียมเลี้ยว
//  TurnLeft();                   //เลี้ยว
//  TracNormalJC(Speed, 100);    //ข้ามแยก
//  TracNormalJC(Speed, 100);    //ข้ามแยก
//  TracNormalTime(ACCSpeed, 200); //แทรกหน่วงเวลา

  TracNormalBW(Speed, 100);      //ข้ามแยก
  TracNormalBW(Speed, 50);   //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalBW(Speed, 100);      //ข้ามแยก
  TracNormalBW(Speed, 50);
  TurnLeft();                   //เลี้ยว
  TracNormalBW(Speed, 100);    //ข้ามแยก
  TracNormalBW(Speed, 50);      //แทรกเดินเตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalBW(Speed, 50);      //แทรกเดินเตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalBW(Speed, 100);    //ข้ามแยก
  TracNormalBW(Speed, 100);    //ข้ามแยก
  TracNormalTime(ACCSpeed, 200); //แทรกหน่วงเวลา
  
}


void MoveCan() {
  Forward(SlowSpeed, 50);       //เดินจากจุดเริ่มต้น

  for (int i = 1; i <= 3; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว A
    GripCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว B
    PutCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว C
    GripCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว D
    PutCan();
    TracNormalBW(Speed, 20);
    UTurn();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว B
    GripCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว C
    PutCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว D
    GripCan();
    TracNormalBW(Speed, 20);
    TurnRight();
    TracNormalJC(Speed, 20);      //แทรกเดินเตรียมเลี้ยว A
    PutCan();
    TracNormalBW(Speed, 20);
  }

  TracNormalTime(ACCSpeed, 100); //แทรกหน่วงเวลา
}
