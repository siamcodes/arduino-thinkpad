void CN1()     //สนามที่บ้าน
{
  Forward(SlowSpeed, 50);       //เดินจากจุดเริ่มต้น 200
  TracNormalJC(Speed, 50);      //ข้ามแยก
  TracNormalJC(SlowSpeed, 30);
  TurnRight();                   //เลี้ยว
  TracNormalJC(Speed, 50);      //ข้ามแยก
  TracNormalJC(SlowSpeed, 30);      //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalJC(Speed, 50);      //ข้ามแยก
  TracNormalJC(SlowSpeed, 30);      //เตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracNormalJC(SlowSpeed, 30);      //เตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  for (int i = 1; i <= 2; i++) {
    TracNormalJC(Speed, 50);      //แทรกเดินตรง1-2
  }
  TracNormalTime(Speed, 500); //แทรกหน่วงเวลา
}

void Can1() {  //สนามที่บ้าน
  Forward(Speed, 50);           //เดินจากจุดเริ่มต้น 200
  TracJC(Speed, 50);            //ข้ามแยก
  TracJC(Speed, 50);
  TurnRight();                  //เลี้ยว
  TracJC(Speed, 50);            //ข้ามแยก
  TracJC(Speed, 50);        //แทรกเดินเตรีียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracJC(Speed, 50);            //ข้ามแยก
  TracJC(Speed, 50);        //เตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  TracJC(Speed, 50);        //เตรียมเลี้ยว
  TurnLeft();                   //เลี้ยว
  for (int i = 1; i <= 2; i++) {
    TracJC(Speed, 50);          //แทรกเดินตรง1-2
  }
  TracTime(Speed, 500);         //แทรกหน่วงเวลา
}

void CN2()  //สนาม WRG
{
  Forward(Speed, 100);          //เดินจากจุดเริ่มต้น 200
  for (int i = 1; i <= 5; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 1-5
    TurnLeft();                   //เลี้ยวซ้าย
  }

  for (int i = 1; i <= 2; i++) {
    TracNormalJC(Speed, 20);      //แทรกเดินเตรีียมเลี้ยว 6-7
    TurnRight();                   //เลี้ยวขวา
  }
  TracNormalJC(ACCSpeed, 30);      //แทรกเดินตรง 8
  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 9
  TurnRight();                  //เลี้ยว

  for (int i = 1; i <= 3; i++) {
    TracNormalJC(Speed, 30);      //แทรกเดินตรง 10-12
  }

  TracNormalJC(Speed, 30);      //แทรกเดินเตรีียมเลี้ยว 13
  TurnLeft();                  //เลี้ยว
  TracNormalJC(ACCSpeed, 50);      //แทรกเดินตรง 14
  TracNormalTime(ACCSpeed, 3000); //แทรกหน่วงเวลา 15
}

void Can2() {               //สนาม WRG
  Forward(Speed, 30);
  TracJC(Speed, 30);        //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 1
  TracJC(SlowSpeed, 20);    //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 2
  TracJC(Speed, 30);        //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 3
  TracJC(Speed, 30);        //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 4
  TracJC(Speed, 30);        //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 5
  TracJC(Speed, 50);        //เตรียมเลี้ยว
  TurnRight();              //เลี้ยวขวา 6
  TracJC(Speed, 50);        //เตรียมเลี้ยว
  TurnRight();              //เลี้ยวขวา 7
  TracJC(Speed, 50);        //เดินข้ามแยก8
  TracJC(SlowSpeed, 20);    //เตรียมเลี้ยว
  TurnRight();              //เลี้ยวขวา 9
  TracJC(SlowSpeed, 50);    //เตรียมเลี้ยว
  TracJC(Speed, 50);        //เดินข้ามแยก10
  TracJC(SlowSpeed, 20);    //เตรียมเลี้ยว
  TracJC(SlowSpeed, 50);    //เดินข้ามแยก11
  TracJC(SlowSpeed, 30);    //เตรียมเลี้ยว
  TurnLeft();               //เลี้ยวซ้าย 12
  TracJC(ACCSpeed, 200);    //เดินข้ามแยก13
  TracJC(ACCSpeed, 200);    //เดินข้ามแยก14
}

void  Can22() {
  Forward(Speed, 30);
  for (int i = 1; i <= 7; i++) {
    TracNormalJC(Speed, 50);     // เตรียมเลี้ยว
    TurnLeft();                  // เลี้ยวซ้าย 1
  }
  TracNormalJC(Speed, 50);       // เตรียมเลี้ยว
  UTurn();                       // เลี้ยวซ้าย 1
  for (int i = 1; i <= 7; i++) {
    TracNormalJC(Speed, 50);    // เตรียมเลี้ยว
    TurnRight();                // เลี้ยวซ้าย 1
  }
  TracNormalTime(ACCSpeed, 500); //แทรกหน่วงเวลา 15
}



void MoveCan() {
  Forward(Speed, 50);           //เดินจากจุดเริ่มต้น 200
  for (int i = 1; i <= 5; i++) {
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(SlowSpeed, 20);            //ข้ามแยก

    GripDown();     //ยกแขนลง
    Grip();         //คีบ
    GripUp();       //ยกแขนขึ้น
    UTurn();
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(SlowSpeed, 20);            //ข้ามแยก
    GripDown();     //ยกแขนลง
    Put();          //ปล่อย
    UTurn();
  }
}

void MoveCan2() {
  Forward(Speed, 50);           //เดินจากจุดเริ่มต้น 200
  TracJC(Speed, 50);            //ข้ามแยก
  TracJC(Speed, 50);            //ข้ามแยก
  for (int i = 1; i <= 3; i++) {
    TracJC(SlowSpeed, 30);            //ข้ามแยก
    GripDown();     //ยกแขนลง
    Grip();         //คีบ
    GripUp();       //ยกแขนขึ้น
    UTurn();
    TracJC(SlowSpeed, 50);        //แทรกเดินเตรีียมเลี้ยว
    TurnLeft();
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(SlowSpeed, 30);            //ข้ามแยก
    GripDown();     //ยกแขนลง
    Put();          //ปล่อย
    Grip();         //คีบ
    GripUp();       //ยกแขนขึ้น
    UTurn();
    TracJC(Speed, 50);            //ข้ามแยก
    TracJC(SlowSpeed, 50);        //แทรกเดินเตรีียมเลี้ยว
    TurnRight();
  }
  UTurn();
  TracJC(Speed, 50);            //ข้ามแยก
  TracJC(Speed, 50);            //ข้ามแยก
  TracTime(Speed, 500);         //แทรกหน่วงเวลา
  UTurn();
}

void TestServo() {
  GripDown();     //ยกแขนลง
  Grip();         //คีบ
  GripUp();       //ยกแขนขึ้น
  Put();          //ปล่อย
  delay(500);   //หน่วงเวลา
}
