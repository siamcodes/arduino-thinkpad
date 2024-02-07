#define LED_PIN PC13
//#define AIN_PIN PA0

#define AIN1 PB15   //Motor 1 +
#define AIN2 PA8    //Motor 1 -
#define BIN1 PA15   //Motor 2 + 
#define BIN2 PB3    //Motor 2 -

//#define ADC_RESOLUTION (12)
#define PWM_RESOLUTION (10)
#define PWM_FREQ (10000)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(115200);
  //while (!Serial);
  //Set PWM frequency  (default: 1kHz)
  analogWriteFrequency(PWM_FREQ);
  //Forward(250, 2000);
  //MotorStop();
}

void loop() {
   Forward(250, 2000);
   MotorStop();
   Backward(250, 2000);
   //TurnLeft();
   //TurnRight();
   delay(2000);
  
}
