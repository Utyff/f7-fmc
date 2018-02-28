#include <my_main.h>
#include <stdlib.h>
#include <delay.h>
#include <draw.h>
#include <keys.h>
#include <DataBuffer.h>


void myMainInitialize() {
    DWT_Init();
    LCD_Init();
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)buf, BUF_SIZE);
//  HAL_TIM_Base_Start(&htim1);

/* CLK  216 mHz
 * PRE        21600 => 10 kHz
 * COUNT PER  10 000 => 1Hz
 * PRE        215 => 1000 kHz
 * COUNT PER  99 => 10 kHz
 */
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
}

void myMainCycle() {
    drawScreen();
    KEYS_scan();

    if((random() & 7) < 3)  HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
    if((random() & 7) < 3)  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    if((random() & 7) < 3)  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin); //*/

    LCD_ShowxNum(30, 214, (u32) button1Count, 5, 12, 0x0);

    delay_ms(50);

}