void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  oled.clear();
  oled.text(1, 0, "L2 = %d", L2);
  oled.text(2, 0, "L1 = %d", L1);
  oled.text(3, 0, "C = %d", C);
  oled.text(4, 0, "R1 = %d", R1);
  oled.text(5, 0, "R2 = %d", R2);
  oled.text(6, 0, "BL = %d", BL);
  oled.text(7, 0, "BC = %d", BC);
  oled.text(8, 0, "BR = %d", BR);
  oled.show();
}
