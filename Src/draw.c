#include "draw.h"
#include "DataBuffer.h"
#include "lcd.h"


void drawFrame() {
    u16 x, y, step = 32;

    LCD_Clear(BLACK);
    POINT_COLOR = GRAY;  // Drawing pen color
    BACK_COLOR = BLACK;

    for (y = step; y < MAX_Y; y += step) {
        if (y == 128) POINT_COLOR = GRAY;  // Drawing pen color
        else POINT_COLOR = DARKGRAY;
        LCD_DrawLine(0, y, MAX_X, y);
    }

    for (x = step; x < MAX_X; x += step) {
        if (x == 160) POINT_COLOR = GRAY;  // Drawing pen color
        else POINT_COLOR = DARKGRAY;
        LCD_DrawLine(x, 0, x, MAX_Y);
    }
}

void drawGraph() {
    POINT_COLOR = CYAN;
    for (u16 i = 0; i < MAX_X; i++) {
        //LCD_DrawPoint(i, buf[i]);
        LCD_Fast_DrawPoint(i, buf[i], CYAN);
        //LCD_DrawLine(i - (u16) 1, buf[i - 1], i, buf[i]);
    }
}

void drawScreen() {
    drawFrame();
    drawGraph();
}
