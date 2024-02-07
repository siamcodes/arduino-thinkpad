void MotorStop(){
  //MotorStop
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);
  delay(200);
}

void Forward(int Speed, int dl){
  //Forward
  analogWrite(AIN1, Speed);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, Speed);
  analogWrite(BIN2, 0);
  delay(dl);
}

void Backward(int Speed, int dl){
  //Backward
  analogWrite(AIN1, 0);
  analogWrite(AIN2, Speed);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, Speed);
  delay(dl);
}

void TurnLeft(){
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 150);
  analogWrite(BIN1, 150);
  analogWrite(BIN2, 0);
  delay(450);
  MotorStop();
}

void TurnRight(){
  analogWrite(AIN1, 150);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 150);
  delay(450);
  MotorStop();
}
