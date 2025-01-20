/*
 * cursor.c
 *
 *  Created on: Jan 12, 2025
 *      Author: Fabrice Jandt
 */
#include "cursor.h"

CursorMode eCurrentMode = OFF;
uint16_t cursorX = 0;
uint16_t cursorY = 0;

const unsigned int iCursorStep = 1;


void changeCursorMode(CursorMode csrMode)
{
	eCurrentMode = csrMode;
}

void moveCursor(CursorDirection csrDirection)
{
	int iCursorDirection = (int)(csrDirection);

	bool bTemp;

	// Shall move up?
	bTemp = iCursorDirection & UP;
	if(bTemp)
	{
		cursorY -= iCursorStep;
	}

	// Shall move down?
	bTemp = iCursorDirection & DOWN;
	if(bTemp)
	{
		cursorY += iCursorStep;
	}

	// Shall move right?
	bTemp = iCursorDirection & RIGHT;
	if(bTemp)
	{
		cursorX += iCursorStep;
	}

	// Shall move left
	bTemp = iCursorDirection & LEFT;
	if(bTemp)
	{
		cursorX -= iCursorStep;
	}

	// Boundary check at the end
	if(cursorY < 0)
		cursorY = 0;

	if(cursorX < 0)
		cursorX = 0;

	// Not really needed, as vertical scrolling is probably redundant
	if(cursorY > ST7735_HEIGHT)
		cursorY = ST7735_HEIGHT;

	// TODO: Maybe adjust?
	if(cursorX > ST7735_WIDTH)
		cursorX = ST7735_WIDTH;
}


uint16_t getScrolledX()
{
	return cursorX;
}

uint16_t getScrolledY()
{
	return cursorY;
}
