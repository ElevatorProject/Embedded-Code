#define NO_BTN 0

#define MSG_ID_CAR 0x40000000 //0x200
#define MSG_ID_F1 0x40200000 //0x201
#define MSG_ID_F2 0x40400000 //0x202
#define MSG_ID_F3 0x40600000 //0x203

#define MSG_F1 0x05 //0x05 goto floor1
#define MSG_F2 0x06 //0x06 goto floor2
#define MSG_F3 0x07 //0x07 goto floor3

#define MSG_GOTO_CURRENT_FLOOR 0x01 // goto the floor specified by msg_id

void init_gpio(void);
unsigned char check_btn_state(void);