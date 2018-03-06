#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f7xx_hal.h"

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern SRAM_HandleTypeDef hsram1;
extern UART_HandleTypeDef huart1;

void mainInitialize();
void mainCycle();

#endif //__MAIN_H
