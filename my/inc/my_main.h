#ifndef _MY_MAIN_H
#define _MY_MAIN_H

#include "stm32f7xx_hal.h"

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern SRAM_HandleTypeDef hsram1;

void myMainInitialize();
void myMainCycle();

#endif //_MY_MAIN_H
