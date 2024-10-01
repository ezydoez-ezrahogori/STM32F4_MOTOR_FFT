
#include "adc.h"

void ADC1_Init(void) {
    // Enable the clock for ADC1 and GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;  // Enable ADC1 clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock

    // Set PA0 to Analog Mode (Assuming PA0 is connected to motor sensor)
    GPIOA->MODER |= GPIO_MODER_MODER0;   // Set PA0 to analog mode

    // Configure ADC1
    ADC1->SQR3 = 0;  // Select channel 0 (PA0)
    ADC1->SMPR2 |= ADC_SMPR2_SMP0; // Set sample time for channel 0

    // Enable ADC1
    ADC1->CR2 |= ADC_CR2_ADON;
}

uint32_t ADC1_Read(void) {
    ADC1->CR2 |= ADC_CR2_SWSTART;    // Start conversion
    while (!(ADC1->SR & ADC_SR_EOC)); // Wait for conversion complete
    return ADC1->DR;                 // Read the ADC value
}
