void ShowADC(){
  ReadADC();
  Serial.println(String(a0)+"\t"+String(a1)+"\t"+String(a2)+"\t"+String(a3)+"\t"+String(a4)+"\t"+String(a5)+"\t"+String(a6)+"\t"+String(a7));
  delay(200);
}
