#include <TimerOne.h>

#define PIN_PWM 9
uint8_t fanid=2;

void setup(void)
{
  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  Timer1.initialize(40);  // 40 us = 25 kHz
  delay(10);
  Timer1.pwm(PIN_PWM, 0);
  Serial.begin(115200);
}

void loop(void)
{
  if (Serial.available() > 0) {
    uint8_t input = Serial.read();
    if (input == 255) {
      Serial.write(fanid);
    }
    else {
      Timer1.pwm(PIN_PWM, (float)input / 254.0 * 1023.0); // from 55 to 1023
    }
  }
}