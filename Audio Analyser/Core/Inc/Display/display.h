#ifndef INC_DISPLAY_DISPLAY_H_
#define INC_DISPLAY_DISPLAY_H_

#include "stm32f4xx.h"

#include "st7735.h"
#include "displayrefresher.h"
#include "coordinatesystem.h"
#include "utils.h"
#include "Buffer/buffer.h"

#include <stdbool.h>
#include <string.h> // memset
#include <stdio.h> // sprintf

// TODO: Umbennen entsprechend der Konstantennorm in C (Alles Caps)
//#define startX 35
//#define startY 20
//#define middleX ST7735_WIDTH
//#define bottomY 140

#define COORD_START_X 35
#define	COORD_START_Y 20
#define COORD_END_X ST7735_WIDTH
#define COORD_END_Y 140



#define DISPLAY_BACKGROUND_COLOUR ST7735_WHITE
#define DISPLAY_COORDSYS_COLOUR ST7735_BLACK
#define DISPLAY_COORDSYS_FONT_COLOUR ST7735_RED

// TODO: Change in F_IN_KHZ
#define FINKHZ false

void drawInit();
void draw();

#endif /* INC_DISPLAY_DISPLAY_H_ */
