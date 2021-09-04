#include <Arduino.h>

#define PWM_PIN 3
#define STANDBY 4
#define INPUT_1 5
#define INPUT_2 6

#define PWM_MAXVALUE 10

uint8_t pwm_value;
boolean pwm_direction;
boolean toggle = false;

int pwm_delay_count;
int pwm_delay;

void setup() {
  pinMode(STANDBY, OUTPUT);
  pinMode(INPUT_1, OUTPUT);
  pinMode(INPUT_2, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  toggle = true;
  pwm_value = PWM_MAXVALUE-1;
  pwm_delay = 2;
  pwm_delay_count = 0;
  digitalWrite(INPUT_1, LOW);
  digitalWrite(INPUT_2, LOW);
  digitalWrite(STANDBY, LOW);
}

void loop() {
  
  digitalWrite(STANDBY, LOW);
  digitalWrite(INPUT_1, LOW);
  digitalWrite(INPUT_2, LOW);

  if ( toggle ) {
    digitalWrite(INPUT_1, HIGH);
    digitalWrite(INPUT_2, LOW);
  } else {
    digitalWrite(INPUT_1, LOW);
    digitalWrite(INPUT_2, HIGH);
  }
  analogWrite(PWM_PIN, pwm_value);
  digitalWrite(STANDBY, HIGH);
  toggle ^= 1;
  delay(100);
  pwm_delay_count++;
  if (pwm_delay_count > pwm_delay){
    if ( pwm_direction)  {
      pwm_value++;
      if(pwm_value == PWM_MAXVALUE){
        pwm_direction = false;
      }
    } else {
      pwm_value--;
      if(pwm_value == 0){
        pwm_direction = true;
      }
    }
    pwm_delay_count = 0;
  }

}