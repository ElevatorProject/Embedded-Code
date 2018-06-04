#include "FloorControl.h"

#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>

#define GPIO_A 0b11111111 // all output
#define GPIO_B 0b11111000 // B0 is input rest are output

#define BTN_1 0b00000001
#define BTN_2 0b00000010
#define BTN_3 0b00000100

#define LED_FLOOR1 0b11111110 // active low led floor 1 on
#define LED_FLOOR2 0b11111101 // active low led floor 2 on
#define LED_FLOOR3 0b11111011 // active low led floor 3 on

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
        default:
            previous_state = NOT_HELD; 
            return NO_BTN;
        break;
    }   
}