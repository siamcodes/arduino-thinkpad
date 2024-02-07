//#include <SPI.h>
#include <POP32.h>
#define NUM_SENSORS 4
uint8_t F_PIN[NUM_SENSORS] = { 3, 2, 1, 0 }; //ซ้าย->ขวา  สีเขียวค่าน้อย สีขาวค่ามาก
int F[NUM_SENSORS];
int REFmin[NUM_SENSORS], REFmax[NUM_SENSORS];
int  last_value = 0, LastError , SumError;

///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {214,161,618,185};
int MaxValue[NUM_SENSORS] = {969,967,980,964};
int REF[NUM_SENSORS] = {591,564,799,574};

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
  stdPID(20, 0.03, 0.03, 100, -10); //ใส่ baseSpeed เป็น 0 ก่อนเพื่อเทสหุ่นต้องนิ่งเกาะเส้น ถ้าไม่เกาะเส้นให้ไปแก้ที่ฟังก์ชัน readCalibrate()
  //m1();
  //Motor(20,20);delay(1000);

  //while (1) {MotorStop(); } //เมื่อใช้งาน m1 ให้เอาคอมเมนต์ออกออก

}
