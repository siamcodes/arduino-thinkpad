void setup() {
  Serial.begin(9600);
  pinMode(PC13, OUTPUT);
}

void loop() {
  digitalWrite(PC13, HIGH);
  delay(500);
  digitalWrite(PC13, LOW);
  delay(500);
  Serial.println("Hello World");

}
