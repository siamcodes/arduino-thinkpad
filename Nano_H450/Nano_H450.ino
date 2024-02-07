int MA1 = 5, MA2 = 6 ,MB1 = 9, MB2 = 10;

int a0, a1, a2, a3, a4, a5, a6, a7; //ตัวแแปรเก็บค่าเซนนเซอร์

int RefA0, RefA1, RefA2, RefA3, RefA4, RefA5, RefA6, RefA7; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int SlowSpeed, Speed, ACCSpeed,  TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 200;
  SlowSpeed = 70;
  ACCSpeed = 150;
  TurnSpeed = 100;

  Serial.begin(9600);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);

  
  Forward(Speed, 2000);
  Backward(Speed, 2000);
  //TurnLeft();
  //TurnRight();
  //UTurnRight();
  //UTurnLeft();
  MotorStop();
}

void loop() {
  
  //ShowADC();
  
}
