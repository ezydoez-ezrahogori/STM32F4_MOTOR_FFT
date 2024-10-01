
#ifndef FFT_H
#define FFT_H

#include <math.h> // For sine, cosine

// Define complex data type
typedef struct {
    float real;
    float imag;
} Complex;

// Function to perform FFT on complex input array
void FFT(Complex *X, unsigned int N);

#endif // FFT_H
