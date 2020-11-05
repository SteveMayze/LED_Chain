/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set FF_K aliases
#define FF_K_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define FF_K_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define FF_K_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define FF_K_GetValue() (VPORTA.IN & (0x1 << 2))
#define FF_K_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define FF_K_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define FF_K_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define FF_K_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define FF_K_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define FF_K_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define FF_K_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define FF_K_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define FF_K_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define FF_K_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define FF_K_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define FF_K_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set FF_J aliases
#define FF_J_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define FF_J_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define FF_J_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define FF_J_GetValue() (VPORTA.IN & (0x1 << 1))
#define FF_J_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define FF_J_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define FF_J_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define FF_J_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define FF_J_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define FF_J_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define FF_J_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define FF_J_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define FF_J_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define FF_J_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define FF_J_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define FF_J_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set FF_RESET aliases
#define FF_RESET_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define FF_RESET_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define FF_RESET_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define FF_RESET_GetValue() (VPORTA.IN & (0x1 << 4))
#define FF_RESET_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define FF_RESET_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define FF_RESET_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define FF_RESET_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define FF_RESET_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define FF_RESET_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define FF_RESET_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define FF_RESET_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define FF_RESET_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define FF_RESET_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define FF_RESET_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define FF_RESET_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set FF_SET aliases
#define FF_SET_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define FF_SET_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define FF_SET_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define FF_SET_GetValue() (VPORTA.IN & (0x1 << 3))
#define FF_SET_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define FF_SET_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define FF_SET_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define FF_SET_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define FF_SET_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define FF_SET_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define FF_SET_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define FF_SET_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define FF_SET_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define FF_SET_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define FF_SET_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define FF_SET_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set USER_LED0 aliases
#define USER_LED0_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define USER_LED0_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define USER_LED0_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define USER_LED0_GetValue() (VPORTA.IN & (0x1 << 5))
#define USER_LED0_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define USER_LED0_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define USER_LED0_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define USER_LED0_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define USER_LED0_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define USER_LED0_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define USER_LED0_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define USER_LED0_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define USER_LED0_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define USER_LED0_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define USER_LED0_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define USER_LED0_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PB0 aliases
#define PB0_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define PB0_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define PB0_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define PB0_GetValue() (VPORTB.IN & (0x1 << 0))
#define PB0_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define PB0_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define PB0_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PB0_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PB0_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PB0_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PB0_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PB0_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PB0_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PB0_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PB0_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PB0_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTA_FF_K_DefaultInterruptHandler(void);
void PORTA_FF_K_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_FF_J_DefaultInterruptHandler(void);
void PORTA_FF_J_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_FF_RESET_DefaultInterruptHandler(void);
void PORTA_FF_RESET_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_FF_SET_DefaultInterruptHandler(void);
void PORTA_FF_SET_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_USER_LED0_DefaultInterruptHandler(void);
void PORTA_USER_LED0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_PB0_DefaultInterruptHandler(void);
void PORTB_PB0_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
