#ifndef FFT_H
#define FFT_H

#include "arm_math.h"
#include <stdbool.h>

//#define PI 3.14159265358979

// IMPORTANT: Falls man die FFT_SIZE aktualiseren will, muss man alles andere auch
// aktualisieren!
#define FFT_SIZE 1024
#define HFFT_SIZE 512
#define QFFT_SIZE 256
#define EFFT_SIZE 128

typedef enum FFT_STATUS
{
	// General
	OK = 0, NOT_INITIALIZED,
	SOURCE_NULLPTR, DESTINATION_NULLPTR,

	// Initialization errors:
	INIT_FAILED

	// Other
} FFT_STATUS;

FFT_STATUS FFT_init(uint32_t uFFTSize);

FFT_STATUS floatToQ31(const float* pSource, q31_t* pDestination);

FFT_STATUS Q31toFloat(const q31_t* pSource, float32_t* pDestination);

FFT_STATUS fft_magnitude_f32(float32_t* pSource, float32_t* pDestination);

FFT_STATUS fastFourierTransform(float32_t* pSource, float32_t* pDestination);

#endif // FFT_H
