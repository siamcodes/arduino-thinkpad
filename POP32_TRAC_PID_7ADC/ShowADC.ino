void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  oled.clear();
  oled.text(0, 0, "L3 = %d", L3);
  oled.text(1, 0, "L2 = %d", L2);
  oled.text(2, 0, "L1 = %d", L1);
  oled.text(3, 0, "C = %d", C);
  oled.text(4, 0, "R1 = %d", R1);
  oled.text(5, 0, "R2 = %d", R2);
  oled.text(6, 0, "R3 = %d", R3);
  oled.show();
}
