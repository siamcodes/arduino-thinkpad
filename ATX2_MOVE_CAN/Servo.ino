void ServoGrip() {  //กำหนดองศาการคีบ
  for (int pos = 80; pos >= 20; pos -= 1) { //90-20องษา
    servo(1, pos); //1=Servo1, 70=องศาServo
    delay(1);
  }
}

void ServoPut() {   //กำหนดองศาการปล่อย  90 องศา
  for (int pos = 20; pos <= 80; pos += 1) { //20-90องษา
    servo(1, pos);
    delay(2);
  }
}

void ServoGripDown() { //กำหนดองศาการยกลง
  for (int pos = 97; pos <= 100; pos += 1) {
    servo(2, pos);
    delay(3);
  }
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น ถ้า0ยกเติมที่
  servo(2, 97);  //45
}

void Grip() { //คีบหน่วงเวลา
  ao();
  ServoGrip();
  delay(200);
}

void Put() { //ปล่อยหน่วงเวลา
  ao();
  ServoPut();
  delay(200);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUp();
  delay(200);
}

void GripDown() { //ยกแขนลงหน่วงเวลา
  ao();
  ServoGripDown();
  delay(200);
}

void GripCan() {
  GripDown();     //ยกแขนลง
  Grip();         //คีบ
  GripUp();       //ยกแขนขึ้น
}

void PutCan() {
  GripDown();     //ยกแขนลง
  Put();          //ปล่อย
  GripUp();       //ยกแขนขึ้น
}
