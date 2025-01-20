#include "fft.h"

arm_rfft_fast_instance_f32 pRFFTInstance;
bool bInitialized = false;
uint32_t uGlobalFFTSize = 0;

FFT_STATUS FFT_init(uint32_t uFFTSize)
{
	FFT_STATUS eReturnValue = OK;

//		if(arm_rfft_init_f32(&pRFFTInstance, uFFTSize, 0, 1) != ARM_MATH_SUCCESS)
//	{
//		eReturnValue = INIT_FAILED;
//		return eReturnValue;
//	}

	if(arm_rfft_fast_init_f32(&pRFFTInstance, uFFTSize) != ARM_MATH_SUCCESS)
	{
		eReturnValue = INIT_FAILED;
		return eReturnValue;
	}

	uGlobalFFTSize = uFFTSize;
	bInitialized = true;
	return eReturnValue;
}

FFT_STATUS floatToQ31(const float* pSource, q31_t* pDestination)
{
	if(bInitialized == false) return NOT_INITIALIZED;
	if(pSource == (float*) 0) return SOURCE_NULLPTR;
	if(pDestination == (q31_t*) 0) return DESTINATION_NULLPTR;

	arm_float_to_q31(pSource, pDestination, uGlobalFFTSize);
	return OK;
}

FFT_STATUS fastFourierTransform(float32_t* pSource, float32_t* pDestination)
{
//	if(bInitialized == false) return NOT_INITIALIZED;
	if(pSource == (float32_t*) 0) return SOURCE_NULLPTR;
	if(pDestination == (float32_t*) 0) return DESTINATION_NULLPTR;

	arm_rfft_fast_f32(&pRFFTInstance, pSource, pDestination, 0);
	return OK;
}

FFT_STATUS fft_magnitude_f32(float32_t* pSource, float32_t* pDestination)
{
//	if(bInitialized == false) return NOT_INITIALIZED;
	if(pSource == (float32_t*) 0) return SOURCE_NULLPTR;
	if(pDestination == (float32_t*) 0) return DESTINATION_NULLPTR;

	arm_cmplx_mag_f32(pSource, pDestination, FFT_SIZE);
	return OK;
}
