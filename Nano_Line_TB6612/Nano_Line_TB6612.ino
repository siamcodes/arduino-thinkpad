int PWMA = 11, MA1 = 9, MA2 = 10;
int PWMB = 3 , MB1 = 6, MB2 = 5;
int STBY = 8;

int a0, a1, a2, a3, a4, a5, a6, a7; //ตัวแแปรเก็บค่าเซนนเซอร์

int RefA0, RefA1, RefA2, RefA3, RefA4, RefA5, RefA6, RefA7; //ตัวแปรเก็บค่าเฉลี่ยเซนนเซอร์
int SlowSpeed, Speed, ACCSpeed,  TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
long Timer0, StartTimer0, Timer1, StartTimer1;   //ตัวแปรจับเวลา Timer0=จับเวลาการแทรคเส้น Timer1=ใช้เวลาของภาระกิจ
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Speed = 100;
  SlowSpeed = 70;
  ACCSpeed = 150;
  TurnSpeed = 100;

  Serial.begin(9600);
  pinMode(PWMA, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);  //disable standby
  digitalWrite(PWMA, HIGH);  //Enable PWMA(3)
  digitalWrite(PWMB, HIGH);  //Enable PWMB(11)
  
  //Forward(Speed, 1000);
  //Backward(Speed, 1000);
  //TurnLeft();
  //TurnRight();
  //UTurnRight();
  //UTurnLeft();
  //MotorStop();
}

void loop() {
  
  ShowADC();
  
}
