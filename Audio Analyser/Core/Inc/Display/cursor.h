/*
 * cursor.h
 *
 *  Created on: Jan 12, 2025
 *      Author: Fabrice Jandt
 */

#ifndef INC_DISPLAY_CURSOR_H_
#define INC_DISPLAY_CURSOR_H_
#include "display.h"

typedef enum CursorMode
{
	OFF, HORIZONTAL, VERTICAL, POINT
} CursorMode;

typedef enum CursorDirection
{
	UP = 1, DOWN = 2, LEFT = 4, RIGHT = 8
} CursorDirection;


void changeCursorMode(CursorMode csrMode);
void moveCursor(CursorDirection csrDirection);

uint16_t getScrolledX();
uint16_t getScrolledY();

#endif /* INC_DISPLAY_CURSOR_H_ */
