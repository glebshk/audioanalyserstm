#include "display.h"

// 128 x 160 (if just one display is connected)
// 256 x 160 (if two displays are right next to each other)

void drawText()
{
	ST7735_WriteString(2, 5, "|FFT|", Font_7x10, DISPLAY_COORDSYS_FONT_COLOUR, DISPLAY_BACKGROUND_COLOUR);

	#define bufferSize 16

	char aBuffer[bufferSize] = {};
	const uint8_t lineThicknessCorrection = 1;
	const uint16_t lineLength = 6;

	// y-Achse
	float step = 0.f;
	setMaximum(100.f);

	for(int y = COORD_END_Y; y >= COORD_START_Y; y -= 120 / 4.f)
	{
		ST7735_DrawHorizontalLine(COORD_START_X - lineLength + lineThicknessCorrection, y,
				COORD_START_X + lineLength, DISPLAY_COORDSYS_COLOUR, 2);

		memset(aBuffer, 0, bufferSize);
		sprintf(aBuffer, "%i", (int)step);

		ST7735_WriteString(2, y, aBuffer, Font_7x10, DISPLAY_COORDSYS_FONT_COLOUR, DISPLAY_BACKGROUND_COLOUR);

		step += getValueRangeYEnd() / 4.f;
	}

	#undef bufferSize
}


void drawCoordinateSystem()
{
	ST7735_DrawVerticalLine(COORD_START_X, COORD_START_Y, COORD_END_Y + 5, DISPLAY_COORDSYS_COLOUR, 2);
	ST7735_DrawHorizontalLine(COORD_START_X - 5, COORD_END_Y, COORD_END_X, DISPLAY_COORDSYS_COLOUR, 2);

}

void drawInit()
{
	ST7735_FillScreen(DISPLAY_BACKGROUND_COLOUR);

	drawCoordinateSystem();
	drawText();

}


void drawData()
{
	int mags[] =
		{
		3,  // 200 Hz
		7,  // 440 Hz
		16, // 1 kHz
		32, // 2 kHz
		80, // 5 kHz
		160, // 10 kHz
		241 // 15 kHz
		};


	uint16_t x = COORD_START_X + 5;
	uint16_t y = 0;

	bool bRed = true;
	uint16_t colour = 0;

	const int frequencyAmount = sizeof(mags) / sizeof(int);
	float fThickness = ( (ST7735_WIDTH - x) / frequencyAmount);

	for(int i = 0; i < frequencyAmount; ++i)
	{
		float f = aGlobalBuffer.aMagnitude[mags[i]];

		y = getYPixel(f);
		float coordinateY = coordinateToDisplay(y) - COORD_START_Y;
		if(bRed)
		{
			colour = ST7735_RED;
		}
		else
		{
			colour = ST7735_YELLOW;
		}

		ST7735_FillRectangleFast(x, coordinateY, (int)fThickness, COORD_END_Y - coordinateY, colour);

		x += (int)fThickness;
		bRed = !bRed;
	}
}

void draw()
{
	//drawInit();

	// Clear dirty areas which get updated frequently & ignore coord sys (The two)
	ST7735_FillRectangleFast(COORD_START_X + 2, 0, ST7735_WIDTH - COORD_START_X,
			COORD_END_Y, DISPLAY_BACKGROUND_COLOUR);
	ST7735_FillRectangleFast(COORD_START_X + 2, COORD_END_Y + 2, COORD_END_X - COORD_START_X,
			20, DISPLAY_BACKGROUND_COLOUR);

	drawData();
	HAL_Delay(50);
}
