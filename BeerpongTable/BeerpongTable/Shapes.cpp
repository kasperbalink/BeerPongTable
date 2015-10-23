#pragma once
#include "Shapes.h"

int square_(int size, int interval)
{
	if (size > MIN / 2)
	{
		return -1;
	}

	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		square(size);
	}
}

int square_(int size)
{

	if (size > MIN / 2)
	{
		return -1;
	}
	clearData();
	for (int i = 0 + size; i <= PLUS - size; i++)
	{
		setRowData(i);
	}
	drawRow(0 + size);
	drawRow(MIN - size);
	clearData();
	setRowData(size);
	setRowData(PLUS - size);
	for (int i = 0 + size; i <= MIN - size; i++)
	{
		drawRow(i);
	}
	return 0;
}

void bracket(int direction, int _column, int _row)
{

}

void arrow(int direction, int _column, int _row, int interval) //arrow method with interval
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		arrow(direction, _column, _row);
	}
}

//_column = verplaatsing links/rechts
//_row = verplaatsing boven/benden
//_column & _row == 0: pijl aan spelers kant
void arrow(int direction, int _column, int _row)
{

	switch (direction)
	{
	case 0: //to center
		break;

	case 1: //to player
		break;

	case 2: //to left from player view
		break;

	case 3: //to right from player view
		break;
	}

}