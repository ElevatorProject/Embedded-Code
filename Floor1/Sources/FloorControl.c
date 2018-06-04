#include "FloorControl.h"

#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>

#define GPIO_A 0b11111111 // all output
#define GPIO_B 0b11111110 // B0 is input rest are output

#define HELD 1
#define NOT_HELD 0

void init_gpio()
{
    DDRA = GPIO_A;
    PORTA = LED_OFF;
    DDRB = GPIO_B;
}

unsigned int check_btn_state()
{
    static unsigned char previous_state = NOT_HELD;
    if (PORTB == BTN_UP) {
        if (!previous_state) {
            previous_state = HELD;
            return BTN_UP;
        }
        return NO_BTN;
    }
    previous_state = NOT_HELD;
    return NO_BTN;    
}