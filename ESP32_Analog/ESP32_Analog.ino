int B = 12;
int R = 22;
int G = 23;
void setup() {


}

void loop() {
  for (int i = 0; i <= 255 ; i++) {
    analogWrite(B, i);
    delay(10);
  }
  delay(1000);
  for (int i = 255; i >= 0 ; i--) {
    analogWrite(B, i);
    delay(10);
  }
  delay(1000);
  for (int i = 0; i <= 255 ; i++) {
    analogWrite(R, i);
    delay(10);
  }
  delay(1000);
  for (int i = 255; i >= 0 ; i--) {
    analogWrite(R, i);
    delay(10);
  }
  delay(1000);
  for (int i = 0; i <= 255 ; i++) {
    analogWrite(G, i);
    delay(10);
  }
  delay(1000);
  for (int i = 255; i >= 0 ; i--) {
    analogWrite(G, i);
    delay(10);
  }
  delay(1000);
}
