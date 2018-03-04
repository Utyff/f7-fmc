#include <_main.h>
#include <stdlib.h>
#include <delay.h>
#include <draw.h>
#include <keys.h>
#include <DataBuffer.h>


void mainInitialize() {
    DWT_Init();
    LCD_Init();
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) buf, BUF_SIZE);

    /*for (u8 i = 0; i < 240; i++) {
        buf[i] = i;
        buf[479 - i] = i;
    } //*/

/* CLK  216 mHz
 * PRE        21600 => 10 kHz
 * COUNT PER  10 000 => 1Hz
 * PRE        215 => 1000 kHz
 * COUNT PER  99 => 10 kHz
 */
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_1);
    KEYS_init();

    char *msg = "Hello Nucleo Fun!\n\r";
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, 10, 0xFFFF);
}

void mainCycle() {
    drawScreen();
    KEYS_scan();

    if ((random() & 7) < 3) HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
    if ((random() & 7) < 3) HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    if ((random() & 7) < 3) HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

    LCD_ShowxNum(0, 214, TIM8->CNT, 5, 12, 0x0);
    LCD_ShowxNum(30, 214, (u32) button1Count, 5, 12, 0x0);

    delay_ms(50);
}
