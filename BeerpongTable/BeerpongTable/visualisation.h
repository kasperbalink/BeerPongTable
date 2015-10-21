#pragma once

#include "elapsedMillis.h"

#define  latchPin 12 //A0
#define  clockPin 11 //A1
#define  dataPin  8// A2

#define MIN 12  //0 t/m 8 (13 rijen)
#define PLUS 18 // 0 t/m 18 (19 kolommen)


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
	void allOn();
	void outsideOn(int interval);
	void outsideOn();
	void insideOn(int interval);

	int drawLed(int _plus, int _min);

	void setLedsInRow(int _column);
	void drawRow(int _row);

	int rowData = 0;
	byte data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

private:

};