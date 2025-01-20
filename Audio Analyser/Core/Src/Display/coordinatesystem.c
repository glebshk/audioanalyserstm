/*
 * coordinatesystem.c
 *
 *  Created on: Jan 12, 2025
 *      Author: Fabrice Jandt
 */
#include "coordinatesystem.h"

const uint16_t xMaxPixelRangeStart = COORD_START_X;
const uint16_t xMaxPixelRangeEnd = 2 * COORD_END_X; // 2 * ST7735_WIDTH

const uint16_t yPixelRangeStart = 0;
const uint16_t yPixelRangeEnd = 120;

const float xMaxValueRangeStart = 0.f;
const float xMaxValueRangeEnd = 16000.f;

const float yValueRangeStart = 0.f;
float yValueRangeEnd = 100.f;

float xValueStart = xMaxValueRangeStart;
float xValueEnd = xMaxValueRangeEnd / 2.f;


uint16_t getMaxPixelRangeXStart()
{
	return xMaxPixelRangeStart;
}

uint16_t getPixelRangeYStart()
{
	return yPixelRangeStart;
}

uint16_t getPixelRangeYEnd()
{
	return yPixelRangeEnd;
}

float getMaxValueRangeXStart()
{
	return xMaxValueRangeStart;
}

float getMaxValueRangeXEnd()
{
	return xMaxValueRangeEnd;
}

float getValueRangeYStart()
{
	return yValueRangeStart;
}

float getValueRangeYEnd()
{
	return yValueRangeEnd;
}

uint16_t getMaxPixelRangeYStart() { return getPixelRangeYStart(); }
uint16_t getMaxPixelRangeYEnd() { return getPixelRangeYEnd(); }
float getMaxValueRangeYStart() { return getValueRangeYStart(); }
float getMaxValueRangeYEnd() { return getValueRangeYEnd();}

float getValueRangeXStart()
{
	return xValueStart;
}

float getValueRangeXEnd()
{
	return xValueEnd;
}

uint16_t coordinateToDisplay(uint16_t yPixel)
{
	return (COORD_END_Y - yPixel) + COORD_START_Y;
}

uint16_t getXValue(uint16_t xPixel)
{
	// Input validation
	if(xPixel < getMaxPixelRangeXStart() || xPixel > getMaxPixelRangeXEnd())
		return -1.f;

	// 32 khZ = 256
	// 32 kHz / 256 = 1

	return xPixel * (getMaxValueRangeXEnd() / getMaxPixelRangeXEnd());
}

uint32_t getYValue(uint16_t yPixel)
{
	// Input validation
	if(yPixel < getMaxPixelRangeYStart() || yPixel > getMaxPixelRangeYEnd())
		return -1.f;

	return (uint32_t)yPixel * (uint32_t)(getMaxValueRangeYEnd() / (float)getMaxPixelRangeYEnd());
}


float getXFrequency(uint16_t i)
{
	 // x Hz = x * (FFT_BUFFER_SIZE/2)/31914
	float f = (2*31914*i)/FFT_SIZE;

	if(f >= getMaxValueRangeXEnd())
		f = -1.f;

	return f;
}

uint16_t getYPixel(float yValue)
{
	// 120 / 1 * yValue
	return (uint16_t)((getMaxPixelRangeYEnd() / getMaxValueRangeYEnd()) * yValue);
}

void setMaximum(float yValue)
{
	if(yValue > getMaxValueRangeYEnd())
	{
		yValueRangeEnd = yValue;
	}
}
