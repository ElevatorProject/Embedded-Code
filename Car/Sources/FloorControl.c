#include "FloorControl.h"

#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>

#define GPIO_A 0b11111111 // all output
#define GPIO_B 0b11110000 // B0 is input rest are output

#define BTN_1    0b00000001
#define BTN_2    0b00000010
#define BTN_3    0b00000100
#define BTN_OPEN 0b00001000

#define HELD 1
#define NOT_HELD 0

void init_gpio()
{
    DDRA = GPIO_A;
    DDRB = GPIO_B;
}

unsigned char check_btn_state()
{
    static unsigned char previous_state = NOT_HELD;
    switch (PORTB) {
        case BTN_1:
        if (!previous_state) {
            previous_state = HELD;
            return 1;
        }
        return NO_BTN;
        break;
        case BTN_2:
        if (!previous_state) {
            previous_state = HELD;
            return 2;
        }
        return NO_BTN;
        break;
        case BTN_3:
        if (!previous_state) {
            previous_state = HELD;
            return 3;
        }
        return NO_BTN;
        break;
        case BTN_OPEN:
        if (!previous_state) {
            previous_state = HELD;
            return 4;
        }
        return NO_BTN;
        break;
        default:
            previous_state = NOT_HELD; 
            return NO_BTN;
        break;
    }   
}