#include "keys.h"


#define DEBOUNCING_CNT 0

uint8_t button1Count = 0;
uint8_t button2Count = 0;
uint8_t button3Count = 0;
uint16_t btns_state = 0;
uint16_t enc_state = 0;
static uint16_t debounceCnt = 0;


void KEYS_init() {
}

/*  encoder states transitions
new  old  action
00   00    skip
00   01    +1
00   10    -1
00   11    error

01   00    -1
01   01    skip
01   10    error
01   11    +1

10   00    +1
10   01    error
10   10    skip
10   11    -1

11   00    error
11   01    -1
11   10    +1
11   11    skip
*/

int16_t ENC_Scan() {
    // if encoder change state
    uint16_t new_enc_state = (uint16_t) (ENC1_GPIO_Port->IDR) & (uint16_t) (ENC1_Pin | ENC2_Pin);
    if (new_enc_state != enc_state) {
        uint16_t transition = enc_state | (new_enc_state << 2);
        enc_state = new_enc_state;
        switch (transition) {
            case 0b0001:
            case 0x0111:
            case 0x1000:
            case 0x1110:
                return +1;
            case 0x0010:
            case 0x0100:
            case 0x1011:
            case 0x1101:
                return -1;
            default:
                Error_Handler();
        }
    }
    return 0;
}

/**
 * Check buttons and run actions
 */
void KEYS_scan() {
    if (debounceCnt > 0) {
        debounceCnt--;
        return;
    }

    // if button1 change state
    if ((BTN1_GPIO_Port->IDR & BTN1_Pin) != (btns_state & BUTTON1)) {
        debounceCnt = DEBOUNCING_CNT;
        btns_state ^= BUTTON1;
        if ((btns_state & BUTTON1) != 0) {
            button1Count++;
        }
    }

    // if encoder has step - do it
/*    int16_t step = ENC_Scan();
    if (step == 0) return; //*/

    // choose type of encoder action
    int8_t action = button1Count % (int8_t) 3;
/*    if (action == 0) {
        ADC_step(step);
    } else if (action == 1) {
        DAC_step(step);
    } else {
        DAC_NextGeneratorSignal();
    }  */
}
