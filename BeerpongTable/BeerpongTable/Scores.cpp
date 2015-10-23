#pragma once
#include "Scores.h"

void scoreSquare()
{
	clearData();
	for (int i = 2; i < PLUS - 1; i++)
	{
		setRowData(i);
	}
	drawRow(1);
	drawRow(11);

	clearData();

	setRowData(2);
	setRowData(16);
	for (int x = 2; x < MIN - 1; x++)
	{
		drawRow(x);
	}
}
//number between 0 - 99 with square around it
void showScore(int _number)
{
	scoreSquare();
	number(_number);
}

void showScore(int _number, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		showScore(_number);
	}
}