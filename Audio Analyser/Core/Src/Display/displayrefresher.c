#include "displayrefresher.h"

int counter = 0;

bool Display_Refresh()
{
	if(++counter > 10000)
	{
		counter = 0;
		return true;
	}

	return false;
}
