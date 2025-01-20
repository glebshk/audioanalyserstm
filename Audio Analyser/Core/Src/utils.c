/*
 * utils.c
 *
 *  Created on: Jan 13, 2025
 *      Author: Fabrice Jandt
 */

#include "utils.h"

float findMaximum(float* pBuffer, uint16_t bufSize)
{
	if(pBuffer == (float*) 0)
		return 0;

	float maximum = 0;

	for(uint16_t i = 0; i < bufSize; ++i)
	{
		if(pBuffer[i] > maximum)
			maximum = pBuffer[i];
	}

	return maximum;
}
