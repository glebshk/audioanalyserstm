#include "fft_test.h"

int checkStructure(SignalParameters* pParams)
{
	FFTTEST_STATUS eReturnValue = T_OK;

	// The parameter is a nullptr!
	if(pParams == (SignalParameters*)0)
	{
		eReturnValue = T_NULLPOINTER;
	}

//	// The buffer has not been prepared!
//	else  if(pParams->pData == (q15_t*)0)
//	{
//		eReturnValue = T_UNPREPARED_BUFFER;
//	}

	// The buffer is non-zero. Therefore, it's already prepared. However, the user
	// wants the function to allocate the buffer.
	// Result: Potential memory leak
//	else if(pParams->pData != (q15_t*)0 && pParams->bAllocatePointAmount == true)
//	{
//		eReturnValue = T_BUFFER_ALREADY_PREPARED;
//	}

	// The function does not the boundaries of the (existing) buffer
	// nor the amount of elements to allocate
	else if(pParams->iPointAmount == 0)
	{
		eReturnValue = T_UNKNOWN_POINTAMOUNT;
	}

	// A negative duration does not make sense
//	else if(pParams->fDuration <= 0)
//	{
//		eReturnValue = T_NEGATIVE_DURATION;
//	}

	// A negative frequency is not allowed
	else if(pParams->fFrequency <= 0)
	{
		eReturnValue = T_NEGATIVE_FREQUENCY;
	}

	// A negative sample rate does not make sense
	else if (pParams->fSampleRate <= 0)
	{
		eReturnValue = T_NEGATIVE_SAMPLERATE;
	}

	// A negative amplitude does not make sense
	else if(pParams->fAmplitude <= 0)
	{
		eReturnValue = T_NEGATIVE_AMPLITUDE;
	}

	return eReturnValue;
}

void cosineSignal(SignalParameters* pParams)
{
	// Calculate the signal
	const float fConstant = 2 * PI * pParams->fFrequency * (1 / pParams->fSampleRate);

	for(int i = 0; i < pParams->iPointAmount; ++i)
	{
		pParams->pRawData[i] = pParams->fAmplitude * cos(fConstant * i);
	}
}


void sineSignal(SignalParameters* pParams)
{
	// Calculate the signal
	const float fConstant = 2 * PI * pParams->fFrequency * (1 / pParams->fSampleRate);

	for(int i = 0; i < pParams->iPointAmount; ++i)
	{
		pParams->pRawData[i] = pParams->fAmplitude * arm_sin_f32(fConstant * i);
	}
}

// rect function
void rectSignal(SignalParameters* pParams, int n)
{
	// Calculate the signal
}

// si-function ( sin(pi*x)/(pi*x) )
void siSignal(SignalParameters* pParam, int n)
{
	// Calculate the signal
}

// triangle signal
void triSignal(SignalParameters* pParams, int n)
{

}

// Saw tooth (Sägezahn) signal
void sawToothSignal(SignalParameters* pParams, int n)
{
	// 1/(pi*k) Koeffizient
}

// TODO: Error check realloc's
FFTTEST_STATUS generateSignal(SIGNAL_TYPE eSignalType, SignalParameters* pParams)
{
	// Check if the given structure is valid
	FFTTEST_STATUS eReturnValue = checkStructure(pParams);
	if(eReturnValue != T_OK) return eReturnValue;

/*
 * Only for the heap approach - now stack approach:
	pParams->pRawData = realloc(pParams->pRawData, sizeof(float) * pParams->iPointAmount);
	if(pParams->pRawData == (float*) 0)
		return T_MEMORY_ALLOCATION_ERROR;
*/

	// I do not need to multiply by FFT_SIZE because it's an array and sizeof already calculates that!
	memset(pParams->pRawData, 0, sizeof(__typeof(pParams->pRawData)));

	// Generate according signal
	switch(eSignalType)
	{
	default:
	case T_SINE:
		sineSignal(pParams);
		break;
	case T_COSINE:
		cosineSignal(pParams);
		break;
	}

/*
 * Only for the heap approach - now stack approach:
	pParams->pFFTReadyData = realloc(pParams->pFFTReadyData, sizeof(q15_t) * pParams->iPointAmount);
    if(pParams->pFFTReadyData == (q15_t*) 0)
    	return T_MEMORY_ALLOCATION_ERROR;

*/
	memset(pParams->pFFTReadyData, 0, sizeof(__typeof(pParams->pFFTReadyData)));
	floatToQ31(pParams->pRawData, pParams->pFFTReadyData);


	return eReturnValue;
}

/*
unsigned int calculatePointAmountFromDuration(SignalParameters* pParams)
{
	return 0;
}

float calculateDurationFromPointAmount(SignalParameters* pParams)
{
	return 0.f;
}

*/
