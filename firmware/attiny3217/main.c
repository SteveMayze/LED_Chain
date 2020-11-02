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

void run_anim(){
        // All ON
        FF_RESET_SetLow();
        FF_SET_SetLow();
        FF_J_SetHigh();
        FF_K_SetHigh();
        
        _delay_ms(10000);

        // Side to side blink
        for( uint8_t i = 0; i<10; i++ ) {
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
        _delay_ms(5000);

        // All blink in unison
        for( uint8_t i = 0; i<10; i++ ) {

            FF_RESET_SetHigh();
            FF_SET_SetHigh();

            _delay_ms(500);

            FF_RESET_SetLow();
            FF_SET_SetLow();
            _delay_ms(500);
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
        
        blink_led(1);
        run_anim();       

        blink_led(2);
        uint16_t period = calculate_period(5, 5);
        uint16_t duty = period/2;
        clk_change(period, duty, 5);
        run_anim();        

        blink_led(3);
        period = calculate_period(10, 5);
        duty = period/2;
        clk_change(period, duty, 5);

        run_anim();        

        TCA0_Initialize();
    }
}
/**
    End of File
*/