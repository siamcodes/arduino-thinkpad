//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 8
uint8_t F_PIN[NUM_SENSORS] = { 7, 6, 5, 4, 3, 2, 1, 0 }; //ซ้าย->ขวา  สีเขียวค่าน้อย สีขาวค่ามาก
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {53,31,59,46,45,34,174};
int MaxValue[NUM_SENSORS] = {834,389,820,774,772,457,868};
int REF[NUM_SENSORS] = {443,210,439,410,408,245,521};

///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  //AutoRef();

  GripCan();
  PutCan();
  
  beep();
  sw_OK_press(); // Wait For Press SW
  delay(500);

 //ShowCalibrate(); //Calibrate Light of Sensor
  //SerialF(); //Serial Sensor
  //Program1();

}

void loop() {
  //stdPID(50, 0.01, 0.00, 100, -10); //ใส่ baseSpeed เป็น 0 ก่อนเพื่อเทสหุ่นต้องนิ่งเกาะเส้น ถ้าไม่เกาะเส้นให้ไปแก้ที่ฟังก์ชัน readCalibrate()
  //m1();
  //Motor(20,20);delay(1000);

  //while (1) {MotorStop(); } //เมื่อใช้งานให้เอาออก

}
