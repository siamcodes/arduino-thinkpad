void ServoGrip() { //กำหนดองศาการคีบ
  for (int pos = 0; pos <= 10; pos += 1) {
    servo(2, pos);
    delay(pos);
  }
}

void ServoPut() { //กำหนดองศาการปล่อย
  servo(2, 120);
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น
  servo(1, 0);
}

void ServoGripDown() { //กำหนดองศาการยกลง
  servo(1, 90);
}


void Grip() { //คีบหน่วงเวลา
  AO();
  ServoGrip();
  delay(400);
}

void Put() { //ปล่อยหน่วงเวลา
  AO();
  ServoPut();
  delay(200);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  AO();
  ServoGripUp();
  delay(500);
}


void GripDown() { //ยกแขนลงหน่วงเวลา
  AO();
  ServoGripDown();
  delay(500);
}
