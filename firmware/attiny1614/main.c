/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "util/delay.h"


/**
 * Internal delay that can take a parameter. AVR does not allow variables
 * as it sets up the timer at compile time.
 * @param n
 */
void delay_s(int n) {
    while(n--) {
        _delay_ms(1000);
    }
}

void delay_ms(int n) {
    while(n--) {
        _delay_ms(1);
    }
}

uint16_t calculate_period(uint16_t frequency, uint8_t new_div) {
    //    uint8_t div_reg = (TCA0.SINGLE.CTRLA & 0x0F) >> 1;

    uint16_t prescale[] = {1, 2, 4, 8, 16, 64, 256, 1024};
    volatile uint16_t div = prescale[new_div];

    volatile uint16_t period = F_CPU / ( div * frequency );
    return period;
}

void clk_change(uint16_t period, uint16_t duty, uint8_t div)
{
    TCA0.SINGLE.CTRLA = 0x00;

    // Duty
    TCA0.SINGLE.CMP0BUF = duty;

    //Period
    TCA0.SINGLE.PERBUF = period;
    // Div 16
    TCA0.SINGLE.CTRLA = (div << 1 )| 0x01;

}

#define _GINGERBREAD_HOUSE

#ifdef _GINGERBREAD_HOUSE


void set_pluse_rate(int frequency, uint8_t duty_div, uint8_t clk_div) {
    // All ON
    // 100 Hz
    uint16_t period = calculate_period(frequency, clk_div);
    uint16_t duty = period/duty_div;
    clk_change(period, duty, clk_div);
    FF_RESET_SetLow();
    FF_SET_SetLow();
    FF_J_SetHigh();
    FF_K_SetHigh();    
}

void side_to_side_blink(int iterations, int duty) {
    // Side to side blink
    for( uint8_t i = 0; i<iterations; i++ ) {
        FF_J_SetLow();
        FF_K_SetHigh();

        delay_ms(duty);

        FF_J_SetHigh();
        FF_K_SetLow();

        delay_ms(duty);
    }
}

void unison_blink(int iterations, int duty){       
    // All blink in unison
    for( uint8_t i = 0; i<iterations; i++ ) {
        FF_RESET_SetHigh();
        FF_SET_SetHigh();

        _delay_ms(1000);

        FF_RESET_SetLow();
        FF_SET_SetLow();
        _delay_ms(1000);
    }

}
void all_off() {
    // All OFF
    FF_RESET_SetHigh();
    FF_SET_SetHigh();
}


void blink_led(uint8_t times) {
    USER_LED0_SetHigh();
    for( uint8_t cnt = 0; cnt < times; cnt++){
        USER_LED0_SetLow();
        _delay_ms(100);
        USER_LED0_SetHigh();    
        _delay_ms(250);
    }    
    USER_LED0_SetHigh();
}
/*
    Main application
*/
#define EFFECT_LIST 5
#define MAX_TIME 25
#define MIN_TIME 10

volatile uint8_t effect_idx = 0;
volatile bool tick = false;
volatile uint8_t duration = MAX_TIME;
volatile bool blink_flag = false;


uint8_t next_random(uint8_t max, uint8_t last_value){
    uint8_t result = last_value;
    while( result == last_value){
        result = rand() % max;
    }
    return result;
}


void rtc_isr_hanlder(void) {
    tick = true;
}

void tock(void) {
    tick = false;
    USER_LED0_Toggle();
    duration--;
    if ( duration == 0 ) {
        effect_idx = next_random(EFFECT_LIST, effect_idx);
        duration = next_random(MAX_TIME, duration);
        duration = duration + MIN_TIME;
        blink_flag = false;
        switch(effect_idx) {
            case 0 :
                set_pluse_rate(1, 2, 5);
                break;
            case 1:
                set_pluse_rate(5, 2, 5);
                break;
            case 2:
                set_pluse_rate(10, 2, 5);
                break;
            case 3:
                set_pluse_rate(100, 2, 5);
                break;
            case 4:
                set_pluse_rate(100, 2, 5);
                blink_flag = true;
                break;
            default:
                // blink_led(3);
                all_off();
                break;
        }            
    }
    if( blink_flag ){
        set_pluse_rate(100, 2, 5);
        if(( duration % 2) == 0) {
            set_pluse_rate(100, 2, 5);
        } else {
            all_off();
        }
    }
}

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    RTC_SetOVFIsrCallback(&rtc_isr_hanlder);
    // RTC_SetPITIsrCallback(&rtc_isr_hanlder);

    /* Replace with your application code */
    USER_LED0_SetHigh();
    // set_pluse_rate(10, 2, 5);
    while (1){
        if ( tick  ) {
            tock();
        }
    }        
}
#endif


#ifdef _TEST_ANIM
void run_anim(){
        // All ON (toggle))
        FF_RESET_SetLow();
        FF_SET_SetLow();
        FF_J_SetHigh();
        FF_K_SetHigh();
        
        _delay_ms(15000);

        // Side to side blink
        for( uint8_t i = 0; i<20; i++ ) {
            FF_J_SetLow();
            FF_K_SetHigh();

            _delay_ms(500);

            FF_J_SetHigh();
            FF_K_SetLow();

            _delay_ms(500);
        }
        
        // All OFF
        FF_RESET_SetHigh();
        FF_SET_SetHigh();
        FF_J_SetHigh();
        FF_K_SetHigh();
        _delay_ms(2500);

        // All blink in unison
        for( uint8_t i = 0; i<20; i++ ) {

            FF_RESET_SetHigh();
            FF_SET_SetHigh();

            _delay_ms(1000);

            FF_RESET_SetLow();
            FF_SET_SetLow();
            _delay_ms(1000);
        }
        // All OFF
        FF_RESET_SetHigh();
        FF_SET_SetHigh();
        
        _delay_ms(1000);
}


void blink_led(uint8_t times) {
    USER_LED0_SetHigh();
    for( uint8_t cnt = 0; cnt < times; cnt++){
        USER_LED0_SetLow();
        _delay_ms(500);
        USER_LED0_SetHigh();    
        _delay_ms(500);
    }    
    USER_LED0_SetHigh();
}
/*
    Main application
*/
int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();

    /* Replace with your application code */
    USER_LED0_SetHigh();
    while (1){
        
        // 100 Hz
        blink_led(1);
        run_anim();       

        // 5 Hz
        blink_led(2);
        uint16_t period = calculate_period(5, 5);
        uint16_t duty = period/2;
        clk_change(period, duty, 5);
        run_anim();        

        // 10 Hz
        blink_led(3);
        period = calculate_period(10, 5);
        duty = period/2;
        clk_change(period, duty, 5);

        run_anim();        

        // Toggle 100Hz
        // This was an attempt to alter the duty cycle to see what effect
        // this has. It is a rather disturbing flicker.
//        period = calculate_period(100, 5);
//        duty = period/2;
//        clk_change(period, duty, 5);
//        
//        FF_RESET_SetLow();
//        FF_SET_SetLow();
//        FF_J_SetHigh();
//        FF_K_SetHigh();
//        
//        for (int16_t i=0; i < period; i+=10 ){
//            clk_change(period, i, 5);
//            _delay_ms(500);
//        }
//
//        for (int16_t i=period; i > 0; i-=10 ){
//            clk_change(period, i, 5);
//            _delay_ms(500);
//        }

        
        TCA0_Initialize();
    }
}
#endif
    
/**
    End of File
*/