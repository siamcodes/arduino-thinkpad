void KickFront()  //ปล่อยลูกบาศก์ด้านหน้า
{
  MotorStop();
  servo(1,80);
  delay(300);
  servo(1,140);
}
void KickBack()  //ปล่อยลูกบาศก์ด้านหลัง
{
  MotorStop();
  servo(2,80);
  delay(300);
  servo(2,140);
}
