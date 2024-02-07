#define LED_PIN PC13
#define AIN_PIN PA0
#define PWM_PIN PA5

// LDR (high-side, 3.3V) + resistor (low-side, GND)
// low light intensity -> lower PWM duty cycle, lower analog input voltage

//#define ADC_RESOLUTION  (10)
//#define PWM_RESOLUTION  (8)
//#define PWM_FREQ        (1000)

#define ADC_RESOLUTION (12)
#define PWM_RESOLUTION (10)
#define PWM_FREQ (10000)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
  Serial.println("STM32duino PWM output demo...");
  // Set ADC resolution (default: 10 bits)
  analogReadResolution(ADC_RESOLUTION);
  // Set PWM resolution (default: 8 bits)
  analogWriteResolution(PWM_RESOLUTION);
  // Set PWM frequency  (default: 1kHz)
  analogWriteFrequency(PWM_FREQ);
  // Write PWM value (zero)
  analogWrite(PWM_PIN, 0);
}

void loop() {
  // Read analog value.
  int adc_value = analogRead(AIN_PIN);
  // Write PWM value.
  int pwm_value = 0;
  int diff = (ADC_RESOLUTION - PWM_RESOLUTION);
  if (diff >= 0) {
    pwm_value = adc_value >> diff;
  } else {
    pwm_value = adc_value << (-diff);
  }
  analogWrite(PWM_PIN, pwm_value);
  // Send a text to the Serial output.
  Serial.printf("ADC: %lu, PWM: %lu\n", adc_value, pwm_value);
  // Wait for some delay before re-entering the loop.
  delay(200);
}
