#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "FloorControl.h"

void main(void) {
  
    unsigned char errorflag = CAN_NO_ERROR;
    unsigned char txbuff[] = {0xFF,0xA4,0x11};
    unsigned char floor_msg = 0;
    unsigned char btn_state = 0;
    CANInit();
    init_gpio();
    while (!(CANCTL0 & CAN_SYNC));       // Wait for MSCAN to synchronize with the CAN bus
  
    CANRFLG = 0xC3;                      // Enable CAN Rx interrupts
    CANRIER = 0x01;                      // Clear CAN Rx flag
    EnableInterrupts;
  
    for(;;) {
        msDelay(50);
        btn_state = check_btn_state();
        switch (btn_state) {    
        case 1:
            floor_msg = MSG_F1;
        break;
        case 2:
            floor_msg = MSG_F2;
        break;
        case 3:
            floor_msg = MSG_F3;
        break;
        case 4:
            floor_msg = MSG_OPEN;
        break;
        default:
            continue;            
        break;
        }
        errorflag = CANTx(MSG_ID_CAR, 0x00, sizeof(unsigned char), &floor_msg);
  
        _FEED_COP(); /* feeds the dog */
    } /* loop forever */
    /* please make sure that you never leave main */
}
