void Can1() {  //สนาม WRG
  Forward(Speed, 30);
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 1
  TracJC(SlowSpeed, 20);      //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 2
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 3
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 4
  TracJC(Speed, 30);       //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 5
  TracJC(Speed, 50);      //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 6
  TracJC(Speed, 50);      //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 7
  TracJC(Speed, 50);  //เดินข้ามแยก8
  TracJC(SlowSpeed, 20);      //เตรียมเลี้ยว
  TurnRight();            //เลี้ยวขวา 9
  TracJC(SlowSpeed, 50);      //เตรียมเลี้ยว
  TracJC(Speed, 50);  //เดินข้ามแยก10
  TracJC(SlowSpeed, 20);      //เตรียมเลี้ยว
  TracJC(SlowSpeed, 50); //เดินข้ามแยก11
  TracJC(SlowSpeed, 30);      //เตรียมเลี้ยว
  TurnLeft();             //เลี้ยวซ้าย 12
  TracJC(ACCSpeed, 200);  //เดินข้ามแยก13
  TracJC(ACCSpeed, 200);  //เดินข้ามแยก14
}

void  Can2() {
  Forward(Speed, 30);
  for (int i = 1; i <= 7; i++) {
    TracNormalJC(Speed, 50);     // เตรียมเลี้ยว
    TurnLeft();                  //เลี้ยวซ้าย 1
  }
  TracNormalJC(Speed, 50);     // เตรียมเลี้ยว
  UTurn();                  //เลี้ยวซ้าย 1
  for (int i = 1; i <= 7; i++) {
    TracNormalJC(Speed, 50);     // เตรียมเลี้ยว
    TurnRight();                  //เลี้ยวซ้าย 1
  }

  TracNormalTime(ACCSpeed, 500); //แทรกหน่วงเวลา 15
}

void Can3() {
  Forward(Speed, 30);
  TracNormalJC(Speed, 50);  //เดินข้ามแยก14
  TracNormalJC(SlowSpeed, 50);      //เตรียมเลี้ยว
  TurnLeft();
  TracNormalJC(SlowSpeed, 50);  //เดินข้ามแยก14
  TracNormalJC(SlowSpeed, 50);      //เตรียมเลี้ยว
  TurnLeft();
  TracNormalJC(SlowSpeed, 50);      //เตรียมเลี้ยว
  TurnRight();
  TracNormalJC(SlowSpeed, 50);      //เตรียมเลี้ยว
  TurnRight();
  TracNormalTime(Speed, 500); //แทรกหน่วงเวลา 15
  }
