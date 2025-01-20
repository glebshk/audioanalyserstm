#ifndef INC_FFT_FFT_TEST_H_
#define INC_FFT_FFT_TEST_H_

#include "fft.h"
#include <stdlib.h>
#include <math.h>

/*
 * The T_XX emphasises that this enums signals the status for the test
 * functions, not the FFT functions in fft.h
 */
typedef enum FFTTEST_STATUS
{
	T_OK = 0, T_NULLPOINTER = 1, T_UNPREPARED_BUFFER = 2,
	T_BUFFER_ALREADY_PREPARED = 3, T_UNKNOWN_POINTAMOUNT = 4,
	T_NEGATIVE_DURATION = 5, T_NEGATIVE_FREQUENCY = 6,
	T_NEGATIVE_SAMPLERATE = 7, T_NEGATIVE_AMPLITUDE = 8,
	T_MEMORY_ALLOCATION_ERROR = 0
} FFTTEST_STATUS;

typedef enum SIGNAL_TYPE
{
	T_SINE = 0, T_COSINE = 1
} SIGNAL_TYPE;


/*
 * For the signal generation, you need:
 * Formula sin(2*pi*f*k*T_s) / cos(2*pi*f*k*T_s)
 * 1. The frequency (f)
 * 2. The sample rate
 * 3. the point amount
 *
 * The remaining members are
 * 1. accounting information (e. g. for the programmer)
 * 2. information about the data handling (who allocates the buffer, what is the buffer)
 * IMPORTANT: DO NOT ALLOCATE the data yourself. The functions do it themselves!
 */
// TODO: Implement the use case for the duration!
typedef struct SignalParams
{
	float fFrequency; // in Hertz
	float fDuration; // in milliseconds
	float fSampleRate; // in per second
	float fAmplitude; // the amplitude of the signal!

	unsigned int iPointAmount; // in n

// This if for radix-4 where I only need 4 byte alignment
//	float pRawData[FFT_SIZE] __attribute__((aligned(4))); // the actual generated signal data
//	q31_t pFFTReadyData[FFT_SIZE] __attribute__((aligned(4))); // the converted signal data, ready for the FFT

	// Because I chose radix-4, I need 8-byte alignment:
	__ALIGNED(8) float pRawData[FFT_SIZE]; // the actual generated signal data
	__ALIGNED(8) q31_t pFFTReadyData[FFT_SIZE + 8]; // the converted signal data, ready for the FFT


} SignalParameters;


FFTTEST_STATUS generateSignal(SIGNAL_TYPE eSignalType, SignalParameters* pParams);

/*
 * Signal: 2.3 sin(2 * PI * 10 Hz * (1 / 100 Hz))
 * Sampling-Rate: 100 Hz
 * FFT calculated by MATLAB
 */
/*
const float fFFT1[] =
{
    7.0788,    7.0895,    7.1216,    7.1758,    7.2532,    7.3551,    7.4838,    7.6418,    7.8328,    8.0613,    8.3332,    8.6563,    9.0405,    9.4994,
   10.0510,   10.7206,   11.5439,   12.5733,   13.8892,   15.6205,   17.9883,   21.4065,   26.7487,   36.2326,   57.6208,  150.4297,  220.9552,   61.8454,
   35.3518,   24.4597,   18.5312,   14.8080,   12.2561,   10.4002,    8.9915,    7.8869,    6.9987,    6.2696,    5.6609,    5.1457,    4.7043,    4.3223,
    3.9886,    3.6949,    3.4346,    3.2024,    2.9942,    2.8066,    2.6366,    2.4822,    2.3412,    2.2120,    2.0933,    1.9840,    1.8829,    1.7892,
    1.7023,    1.6213,    1.5457,    1.4751,    1.4089,    1.3468,    1.2884,    1.2335,    1.1816,    1.1327,    1.0864,    1.0425,    1.0010,    0.9615,
    0.9239,    0.8882,    0.8541,    0.8217,    0.7906,    0.7610,    0.7326,    0.7054,    0.6793,    0.6543,    0.6303,    0.6072,    0.5849,    0.5635,
    0.5428,    0.5229,    0.5036,    0.4850,    0.4670,    0.4496,    0.4327,    0.4163,    0.4005,    0.3850,    0.3700,    0.3554,    0.3412,    0.3274,
    0.3139,    0.3007,    0.2879,    0.2753,    0.2630,    0.2510,    0.2392,    0.2277,    0.2163,    0.2052,    0.1943,    0.1835,    0.1729,    0.1625,
    0.1522,    0.1421,    0.1320,    0.1221,    0.1123,    0.1026,    0.0930,    0.0835,    0.0740,    0.0646,    0.0553,    0.0460,    0.0368,    0.0275,
    0.0184,    0.0092,    0.0002,    0.0092,    0.0184,    0.0275,    0.0368,    0.0460,    0.0553,    0.0646,    0.0740,    0.0835,    0.0930,    0.1026,
    0.1123,    0.1221,    0.1320,    0.1421,    0.1522,    0.1625,    0.1729,    0.1835,    0.1943,    0.2052,    0.2163,    0.2277,    0.2392,    0.2510,
    0.2630,    0.2753,    0.2879,    0.3007,    0.3139,    0.3274,    0.3412,    0.3554,    0.3700,    0.3850,    0.4005,    0.4163,    0.4327,    0.4496,
    0.4670,    0.4850,    0.5036,    0.5229,    0.5428,    0.5635,    0.5849,    0.6072,    0.6303,    0.6543,    0.6793,    0.7054,    0.7326,    0.7610,
    0.7906,    0.8217,    0.8541,    0.8882,    0.9239,    0.9615,    1.0010,    1.0425,    1.0864,    1.1327,    1.1816,    1.2335,    1.2884,    1.3468,
    1.4089,    1.4751,    1.5457,    1.6213,    1.7023,    1.7892,    1.8829,    1.9840,    2.0933,    2.2120,    2.3412,    2.4822,    2.6366,    2.8066,
    2.9942,    3.2024,    3.4346,    3.6949,    3.9886,    4.3223,    4.7043,    5.1457,    5.6609,    6.2696,    6.9987,    7.8869,    8.9915,   10.4002,
   12.2561,   14.8080,   18.5312,   24.4597,   35.3518,   61.8454,  220.9552,  150.4297,   57.6208,   36.2326,   26.7487,   21.4065,   17.9883,   15.6205,
   13.8892,   12.5733,   11.5439,   10.7206,   10.0510,    9.4994,    9.0405,    8.6563,    8.3332,    8.0613,    7.8328,    7.6418,    7.4838,    7.3551,
    7.2532,    7.1758,    7.1216,    7.0895
};
*/
#endif /* INC_FFT_FFT_TEST_H_ */
