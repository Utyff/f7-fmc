#ifndef KEYS_H
#define KEYS_H

#include "stm32f7xx_hal.h"


#define BUTTON1 0x01
#define BUTTON2 0x02
#define BUTTON3 0x04
#define BUTTON4 0x08

extern uint8_t button1Count;
extern uint8_t button2Count;
extern uint8_t button3Count;
extern uint16_t btns_state;

void KEYS_init();
void KEYS_scan();

#endif //KEYS_H
