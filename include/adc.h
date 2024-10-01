
#ifndef ADC_H
#define ADC_H

#include "stm32f4xx.h"

// Function to initialize the ADC
void ADC1_Init(void);

// Function to read data from ADC
uint32_t ADC1_Read(void);

#endif // ADC_H
