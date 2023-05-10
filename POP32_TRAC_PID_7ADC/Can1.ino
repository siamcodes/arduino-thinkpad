void MRC() {  // 1-16สมบูรณ์ ยกเว้น 12 กับตั้งแต่17
  Forward(Speed, 100);

  TracJC(SlowSpeed, 40);
  TurnRight();        //1

  TracJC(20, 40);
  TurnLeft();         //2
  //
  //  TracJC(Speed, 40);
  //  TurnLeft();         //3
  //
  //  TracJC(Speed, 40);
  //  TurnLeft();         //4
  //
  //  TracJC(Speed, 25);
  //  TurnLeft();         //5
  //
  //  TracJC(Speed, 20);
  //  TurnRight();        //6
  //
  //  TracJC(Speed, 30);
  //  TurnRight();        //7
  //
  //  TracJC(Speed, 40);
  //
  //  TracJC(Speed, 20);
  //  TurnRight();        //8
  //
  //  TracJC(Speed, 30);
  //  TurnRight();        //9
  //
  //  TracJC(Speed, 20);
  //  TurnRight();        //10
  //
  //  TracJC(Speed, 30);
  //  TurnRight();        //11
  //
  //  TracJC(Speed, 50);
  //  TurnLeft();         // 12
  //
  //  TracJC(Speed, 50);
  //  TurnLeft();         //13
  //
  //  TracJC(Speed, 25);
  //  TurnRight();        //14
  //
  //  TracJC(Speed, 40);
  //  TurnRight();        //15
  //
  //  TracJC(Speed, 30);
  //  TurnLeft();         //16
  //
  //  TracJC(Speed, 40);
  //  TurnLeft();         //17
  //
  //  TracJC(SlowSpeed, 40);
  //  TurnLeft();         //18
  //
  //  TracJC(Speed, 40);
  //  TurnRight();        //19
  //
  //  TracJC(Speed, 40);
  //  TurnRight();        //20
  //
  //  TracJC(Speed, 40);
  //  TurnRight();        //21
  //
  //  TracJC(Speed, 40);
  //  TurnRight();        //22
}
