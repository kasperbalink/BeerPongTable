#pragma once

#include "elapsedMillis.h"

#define latchPin A1
#define clockPin A0
#define dataPin A2

#define rows 8
#define columns 8

//storage for led states, 4 bytes

class visualisation
{


public:
	void drawLetter(char letter, int x, int y, int interval);
	void drawArrow(int direction, int x, int y, int interval);



private:
	int drawLed(int column, int row);
	byte r[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	byte c[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	byte c2[8] = { 128, 64, 32, 16, 8, 4, 2, 1 }; //inverted
};