#include <lcd.h>
#include "fmc_dma.h"


#define BYTE_IN_DOT 2
#define SCREEN_DOTS (320*240)
#define SCREEN_BYTES (SCREEN_DOTS*BYTE_IN_DOT)


uint16_t screenBuffer[SCREEN_DOTS] = {0,1,2};

void initScreenBuf() {
    for(int i=0; i<SCREEN_DOTS; i++) {
        screenBuffer[i]=MAGENTA;
    }
}

