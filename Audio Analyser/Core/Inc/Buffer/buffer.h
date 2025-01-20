/*
 * buffer.h
 *
 *  Created on: Jan 12, 2025
 *      Author: Fabrice Jandt
 */

#ifndef INC_BUFFER_BUFFER_H_
#define INC_BUFFER_BUFFER_H_

#include "fft.h"

#define AUDIO_BUFFER_SIZE 2 * FFT_SIZE

// TODO: "Test changing the settings!"

typedef struct Buffer
{
	uint16_t aMicSamples[AUDIO_BUFFER_SIZE];

	float32_t aFFTBuffer[FFT_SIZE * 2];
	float32_t aMagnitude[FFT_SIZE];
} Buffer;

extern Buffer aGlobalBuffer;

void Buffer_clearAll(Buffer* pBuffer);
void Buffer_clearMicSamples(q31_t* pMicSamples);
void Buffer_clearFFT(q31_t* pFFTBuffer);
void Buffer_clearMagnitude(q31_t* pMagnitude);

// Separate buffer in order to display it correctly

void Buffer_replaceMagnitude(Buffer* pBuffer);
q31_t* Buffer_getMagnitudeBuffer();

#endif /* INC_BUFFER_BUFFER_H_ */
