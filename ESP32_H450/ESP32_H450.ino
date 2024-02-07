int MA1 = 22;
int MA2 = 23;
void setup() {


}

void loop() {
  for (int i = 0; i <= 255 ; i++) {
    analogWrite(MA1, i);
    analogWrite(MA2, 0);
    delay(20);
  }

}
