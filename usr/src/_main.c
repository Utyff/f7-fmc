#include <_main.h>
#include <stdlib.h>
#include <delay.h>
#include <draw.h>
#include <keys.h>
#include <DataBuffer.h>
#include <string.h>

/* TIM1 Configuration
 * CLK  216 mHz
 * PRE        21600 => 10 kHz
 * COUNT PER  10 000 => 1Hz
 * PRE        215 => 1000 kHz
 * COUNT PER  99 => 10 kHz
 */

void printCPU() {
    char buf[64];
    uint32_t cpuid = SCB->CPUID;
    uint32_t var, pat;

    uint32_t dev_id = DBGMCU->IDCODE & 0xFFF;
    sprintf(buf, "\nCPUID %08X DEVID %03X\n", cpuid, dev_id);
    HAL_UART_Transmit(&huart1, (uint8_t*)buf, (uint16_t)strlen(buf), 0xFFFF);

    pat = (cpuid & 0x0000000F);
    var = (cpuid & 0x00F00000) >> 20;
    uint32_t cortex = (cpuid & 0x0000FFF0) >> 4;
    sprintf(buf, "Cortex M - %X r%dp%d\n", cortex, var, pat);
    HAL_UART_Transmit(&huart1, (uint8_t*)buf, (uint16_t)strlen(buf), 0xFFFF);
}

void mainInitialize() {
    DWT_Init();
    LCD_Init();
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) samplesBuffer, BUF_SIZE);

    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_1);
    KEYS_init();

    printCPU();
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
