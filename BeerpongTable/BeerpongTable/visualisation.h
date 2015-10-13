#pragma once

#include "elapsedMillis.h"

#define latchPin  A0
#define clockPin A1
#define dataPin  A2

#define min 12  //0 t/m 8 (13 rijen)
#define plus 18 // 0 t/m 18 (19 kolommen)


class visualisation
{


public:
	void letter(char letter, int x, int y, int interval);
	void arrow(int direction, int x, int y, int interval);
	void arrow(int direction, int x, int y);
	void allOff(int interval);
	void allOn(int interval);
	void row(int row, int interval);
	void row(int row);
	void rowInside(int row);
	void column(int column, int interval);
	void column(int column);
	void columnInside(int column);
	void upToDown(int interval);
	void downToUp(int interval);
	void leftToRight(int interval);
	void rightToLeft(int interval);
	void outsideOn(int interval);
	void insideOn(int interval);
	void bracket(int direction, int x, int y);


private:
	int drawLed(int column, int row);
	byte data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
};