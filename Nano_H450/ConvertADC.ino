void ConvertADC() //แปลงจาก analog เป็น digital (สีดำ=0 สีขาว=1)
{
  ReadADC();  //อ่านค่าสี
  if (a0 < RefA0) a0  = 0; else a0 = 1;
  if (a1 < RefA1) a1 = 0; else a1 = 1;
  if (a2 < RefA2) a2 = 0; else a2 = 1;
  if (a3 < RefA3) a3 = 0; else a3 = 1;
  if (a4 < RefA4) a4 = 0; else a4 = 1;
  if (a5 < RefA5) a5 = 0; else a5 = 1;
  if (a6 < RefA6) a6 = 0; else a6 = 1;
  if (a7 < RefA7) a7 = 0; else a7 = 1; 
}
