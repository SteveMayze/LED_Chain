#include <Arduino.h>

#define PWM_PIN 3
#define STANDBY 4
#define INPUT_1 5
#define INPUT_2 6

#define PWM_MAXVALUE 100


#define EFFECT_LIST 9
#define MAX_TIME 20
#define MIN_TIME 10

#define BREATHE_OFF 0
#define BREATHE_ALL 1
#define BREATHE_ALT 2
#define BREATHE_ALL_CORR 3
#define BREATHE_ALT_CORR 4

uint8_t pwm_gamma[] = {0, 0, 0, 2, 3, 5, 8, 11, 15, 19, 23, 28, 33, 38, 44, 50, 56, 63, 70, 77, 84, 92, 99, 107, 115, 123, 131, 
                   138, 146, 154, 162, 169, 176, 184, 191, 197, 204, 210, 216, 221, 226, 231, 236, 240, 243, 246, 249, 251, 
                   253, 254, 255, 255, 255, 254, 253, 251, 249, 246, 243, 240, 236, 231, 226, 221, 216, 210, 204, 197, 191, 
                   184, 176, 169, 162, 154, 146, 138, 131, 123, 115, 107, 99, 92, 84, 77, 70, 63, 56, 50, 44, 38, 33, 28, 
                   23, 19, 15, 11, 8, 5, 3, 2, 0, 0};
uint8_t pwm_idx;
#define PWM_GAMMA_SIZE 102
uint8_t gamma_pause;
#define MAX_GAMMA_PAUSE 10
uint8_t max_gamma;

IntervalTimer pulse_timer;
IntervalTimer delay_timer;

uint8_t pwm_value;
boolean pwm_direction;
boolean toggle = false;

int pwm_delay_count;
int pwm_delay;

volatile uint8_t effect_idx = 0;
volatile bool pulse_tick = false;
volatile uint8_t duration = MAX_TIME;
volatile bool blink_flag = false;
volatile uint8_t breathe_flag = 0;
uint8_t breath_count = 0;
volatile bool delay_tick = false;


void pulse_handler() {
  pulse_tick = true;
}

void delay_handler() {
  delay_tick = true;
}

void set_pulse_rate(unsigned int frequency) {
    pulse_timer.update(1000000/frequency);
}


uint8_t next_random(uint8_t min, uint8_t max, uint8_t last_value){
    uint8_t result = last_value;
    while( result == last_value ) {
        result = random(min, max);
    }
    return result;
}

void bank_one() {
  digitalWrite(INPUT_1, HIGH);
  digitalWrite(INPUT_2, LOW);
  digitalWrite(STANDBY, HIGH);
  analogWrite(PWM_PIN, pwm_value);
}

void bank_two() {
  digitalWrite(INPUT_1, LOW);
  digitalWrite(INPUT_2, HIGH);
  digitalWrite(STANDBY, HIGH);
  analogWrite(PWM_PIN, pwm_value);
}


void all_off() {
  digitalWrite(INPUT_1, LOW);
  digitalWrite(INPUT_2, LOW);
  digitalWrite(STANDBY, LOW);
}



void tock(void) {
    delay_tick = false;
    duration--;
    if ( duration == 0 ) {
        effect_idx = next_random(0, EFFECT_LIST, effect_idx);
        duration = next_random(MIN_TIME, MAX_TIME, duration);
        if (blink_flag) {
          pulse_timer.begin(pulse_handler, 10000); // 100Hz
        }
        blink_flag = false;
        breathe_flag = BREATHE_OFF;
        breath_count = 0;
        pwm_value = PWM_MAXVALUE-1;
        switch(effect_idx) {
            case 0 :
                set_pulse_rate(1); // 1 Hz
                break;
            case 1:
                set_pulse_rate(5); // 5 Hz
                break;
            case 2:
                set_pulse_rate(10); // 10 Hz
                break;
            case 3:
                set_pulse_rate(100); // All on
                break;
            case 4:
                set_pulse_rate(100); // Unison blink
                blink_flag = true;
                break;
            case 5:
                set_pulse_rate(100); // All breathe
                pwm_value = 0;
                breathe_flag = BREATHE_ALL;
                pwm_direction = true;
                pwm_idx = 0;
                break;
            case 6:
                set_pulse_rate(100); // Alt breathe
                pwm_value = 0;
                breathe_flag = BREATHE_ALT;
                pwm_direction = true;
                breath_count = 0;
                break;
            case 7:
                set_pulse_rate(100); // All breathe corrected
                pwm_value = 0;
                breathe_flag = BREATHE_ALL_CORR;
                pwm_direction = true;
                pwm_idx = 0;
                gamma_pause = 0;
                max_gamma = next_random(0, MAX_GAMMA_PAUSE, max_gamma);
                break;
            case 8:
                set_pulse_rate(100); // Alt breathe corrected
                pwm_value = 0;
                breathe_flag = BREATHE_ALT_CORR;
                pwm_direction = true;
                breath_count = 0;
                pwm_idx = 0;
                gamma_pause = 0;
                max_gamma = next_random(0, MAX_GAMMA_PAUSE, max_gamma);
                break;
              
            default:
                all_off();
                pulse_timer.end();
                break;
        }            
    }
    if( blink_flag ){
        if(( duration % 2) == 0) {
            pulse_timer.begin(pulse_handler, 10000); // 100Hz
            set_pulse_rate(100);
        } else {
            all_off();
            pulse_timer.end();
            pulse_tick = false;
        }
    } else if ( breathe_flag) {

    }
}

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

  // Quick check
  bank_one();
  delay(1000);
  bank_two();
  delay(1000);
  all_off();
  delay(1000);
  bank_one();
  delay(1000);
  bank_two();
  delay(1000);

  pulse_timer.begin(pulse_handler, 10000); // 100Hz
  delay_timer.begin(delay_handler, 1000000); // 1Hz

  set_pulse_rate(5); // Start off with 5Hz

  pwm_idx = 0;

}


void loop() {
  if ( delay_tick) {
    tock();
  }

  if ( pulse_tick ) {
    
    pulse_tick = false;

    switch (breathe_flag){
      case BREATHE_ALT:
        if ( pwm_direction) {
          if (pwm_value < 200) {
            pwm_value += 2;
          } else {
            breath_count++;
            pwm_direction = false;
          }
        } else {
          if ( pwm_value > 4) {
          pwm_value -= 2;
          } else {
            breath_count++;
            pwm_direction = true;
            if ( breath_count > 2) {
              breath_count = 0;
            }
          }
        }
        if ( breath_count < 2 ){
         bank_one();
        } else {
          bank_two();
        }
        break;
      case BREATHE_ALT_CORR:
        gamma_pause++;
        if( gamma_pause > max_gamma ){
          gamma_pause = 0;
          if ( pwm_idx > PWM_GAMMA_SIZE-1 ) {
            pwm_idx = 0;
            breath_count++;
            if ( breath_count > 1 ) {
              breath_count = 0;
            }
          }
          pwm_value = pwm_gamma[pwm_idx];
          pwm_idx++;
        }
        if ( breath_count < 1 ){
         bank_one();
        } else {
          bank_two();
        }
        break;
      case BREATHE_ALL:
        if ( pwm_direction) {
          if (pwm_value < 200) {
            pwm_value += 2;
          } else {
            pwm_direction = false;
          }
        } else {
          if ( pwm_value > 4) {
          pwm_value -= 2;
          } else {
            pwm_direction = true;
          }
        }
        if ( toggle ) {
          bank_one();
        } else {
          bank_two();
        }
        toggle ^= 1;
        break;
      case BREATHE_ALL_CORR:
        gamma_pause++;
        if( gamma_pause > max_gamma ){
          gamma_pause = 0;
          pwm_value = pwm_gamma[pwm_idx];
          pwm_idx++;
          if ( pwm_idx >= PWM_GAMMA_SIZE ) {
            pwm_idx = 0;
          }
        }
      default:
        if ( toggle ) {
          bank_one();
        } else {
          bank_two();
        }
        toggle ^= 1;
    }
  }

}

