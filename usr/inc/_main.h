#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f7xx_hal.h"

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern SRAM_HandleTypeDef hsram1;
extern UART_HandleTypeDef huart1;

void mainInitialize();
void mainCycle();

#endif //__MAIN_H
