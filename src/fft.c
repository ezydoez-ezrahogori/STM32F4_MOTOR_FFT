#include "fft.h"

void FFT(Complex *X, unsigned int N) {
    unsigned int i, j, k, m, m2;
    float cos_val, sin_val, cos_arg;
    Complex temp, U;

    // Bit-reversal permutation
    j = 0;
    for (i = 1; i < (N - 1); i++) {
        m = N >> 1;
        while (j >= m) {
            j -= m;
            m >>= 1;
        }
        j += m;
        if (i < j) {
            temp = X[i];
            X[i] = X[j];
            X[j] = temp;
        }
    }

    // FFT main loop
    m = 2;
    while (m <= N) {
        m2 = m >> 1;
        for (i = 0; i < m2; i++) {
            cos_arg = (-2.0f * 3.14159f * i) / m;
            cos_val = cos(cos_arg);
            sin_val = sin(cos_arg);
            U.real = cos_val;
            U.imag = sin_val;
            for (j = i; j < N; j += m) {
                k = j + m2;
                temp.real = U.real * X[k].real - U.imag * X[k].imag;
                temp.imag = U.real * X[k].imag + U.imag * X[k].real;
                X[k].real = X[j].real - temp.real;
                X[k].imag = X[j].imag - temp.imag;
                X[j].real += temp.real;
                X[j].imag += temp.imag;
            }
        }
        m <<= 1;
    }
}
