#include <Arduino.h>

#define PWM_PIN 3
#define STANDBY 4
#define INPUT_1 5
#define INPUT_2 6

#define PWM_MAXVALUE 100


#define EFFECT_LIST 6
#define MAX_TIME 20
#define MIN_TIME 10

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

}


void loop() {
    if ( delay_tick) {
        tock();
    }

    if ( pulse_tick ) {
      pulse_tick = false;
    
        if ( toggle ) {
          bank_one();
        } else {
          bank_two();
        }
        toggle ^= 1;
      
    }

  }