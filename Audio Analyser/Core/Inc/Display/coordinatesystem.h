/*
 * coordinatesystem.h
 *
 *  Created on: Jan 12, 2025
 *      Author: Fabrice Jandt
 */

#ifndef INC_DISPLAY_COORDINATESYSTEM_H_
#define INC_DISPLAY_COORDINATESYSTEM_H_

#include "display.h"
#include "cursor.h"

// Starting here: Every getter (attribute) possible needed for the coordinate system

// The current range (which takes scrolling into consideration)
uint16_t getPixelRangeXStart();
uint16_t getPixelRangeXEnd();

// The general range (which does not take scrolling into consideration)
uint16_t getMaxPixelRangeXStart();
uint16_t getMaxPixelRangeXEnd();

// Here scrolling is not possible
uint16_t getPixelRangeYStart();
uint16_t getPixelRangeYEnd();

// The current range (which takes scrolling into consideration)
float getValueRangeXStart();
float getValueRangeXEnd();

bool isInCurrentXRange(uint16_t x);
bool isInCurrentYRange(uint16_t y);

// The general range (which does not take scrolling into consideration)
float getMaxValueRangeXStart();
float getMaxValueRangeXEnd();

// Here scrolling is not possible
float getValueRangeYStart();
float getValueRangeYEnd();

// Are pointing to the functions without 'Max'
uint16_t getMaxPixelRangeYStart();
uint16_t getMaxPixelRangeYEnd();
float getMaxValueRangeYStart();
float getMaxValueRangeYEnd();

// Starting here: Actual scrolling
// Takes data from cursor.h and applies it here
void scroll();

// Starting here: The coordinate transformation between display and coordinate system
uint16_t coordinateToDisplay(uint16_t yPixel);
uint16_t displayToCoordinate(uint16_t yPixel);

// Starting here: The mapping between values and pixels:

float getXFrequency(uint16_t i);

uint16_t getXPixel(float xValue);
uint16_t getYPixel(float yValue);

float getFloat(int32_t q);

uint16_t getXValue(uint16_t xPixel);

/**
 * @brief Calculates the value a specific pixel within
 * the y value range would have.
 */
uint32_t getYValue(uint16_t yPixel);

void setMaximum(float yValue);

#endif /* INC_DISPLAY_COORDINATESYSTEM_H_ */
