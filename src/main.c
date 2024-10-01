#include "stm32f4xx.h"
#include "adc.h"
#include "fft.h"

// Define FFT size (must be a power of 2)
#define N 16 

Complex X[N]; // Input buffer for FFT

void perform_fft(void) {
    // Sample motor data and populate the FFT input array
    for (int i = 0; i < N; i++) {
        uint32_t adc_value = ADC1_Read(); // Read ADC data
        X[i].real = (float)adc_value;     // Store real part
        X[i].imag = 0.0f;                 // Imaginary part is 0
    }

    // Perform FFT
    FFT(X, N);

    // Process the FFT results (Do whatever is needed with the results)
    for (int i = 0; i < N; i++) {
        // You can process FFT results here, e.g., check specific frequencies.
    }
}

int main(void) {
    // Initialize the ADC
    ADC1_Init();

    // Infinite loop
    while (1) {
        perform_fft(); // Perform FFT and analyze motor signals
    }

    return 0;
}
