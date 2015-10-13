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
	//characters
	void letter(char _letter, int _column, int _row, int interval);
	void letter(char _letter, int _column, int _row);
	void number(int _number, int interval);
	void number(int _number);
	

	void bracket(int direction, int x, int y);
	
	void showScore(int _number, int interval);
	void showScore(int _number);
	void scoreSquare();

	//rows and columns
	void row(int row, int interval);
	void row(int row);
	void rowInside(int row);
	void column(int column, int interval);
	void column(int column);
	void columnInside(int column);

	//animations
	void upToDown(int timeBetweenSteps);
	void downToUp(int timeBetweenSteps);
	void leftToRight(int timeBetweenSteps);
	void rightToLeft(int timeBetweenSteps);
	void arrow(int direction, int _column, int _row, int interval);
	void arrow(int direction, int _column, int _row);

	//fields
	void allOff(int interval);
	void allOff();
	void allOn(int interval);
	void outsideOn(int interval);
	void insideOn(int interval);

	int drawLed(int _plus, int _min);
	byte data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

private:

};