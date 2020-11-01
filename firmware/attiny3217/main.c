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


void clk_change(uint16_t period, uint16_t duty)
{
     TCA0.SINGLE.CTRLA = 0x00;

    //Compare 0
    TCA0.SINGLE.CMP0BUF = duty;

    //Period
    TCA0.SINGLE.PERBUF = period;
    TCA0.SINGLE.CTRLA = 0x09;

}

void run_anim(){
        FF_RESET_SetLow();
        FF_SET_SetLow();
        
        FF_J_SetHigh();
        FF_K_SetHigh();
        
        _delay_ms(5000);

        for( uint8_t i = 0; i<10; i++ ) {
            FF_J_SetLow();
            FF_K_SetHigh();

            _delay_ms(500);

            FF_J_SetHigh();
            FF_K_SetLow();

            _delay_ms(500);
        }
        
        _delay_ms(5000);

        FF_J_SetHigh();
        FF_K_SetHigh();

        for( uint8_t i = 0; i<10; i++ ) {

            FF_RESET_SetHigh();
            FF_SET_SetHigh();

            _delay_ms(500);

            FF_RESET_SetLow();
            FF_SET_SetLow();
            _delay_ms(500);
        }
        FF_RESET_SetHigh();
        FF_SET_SetHigh();
        
        _delay_ms(10000);
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
        
        run_anim();        
        
        clk_change(0x5161, 0x28b0);

        run_anim();        

        TCA0_Initialize();
        
        USER_LED0_Toggle();
    }
}
/**
    End of File
*/