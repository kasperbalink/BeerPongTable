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
//direction: 0-to center, 1-to player, 2-left, 3-right (from player view)
void arrow(int direction, int _column, int _row)
{
	switch (direction)
	{
	case 0: //to center
		clearData();
		for (int i = 0; i < 8; i++)
		{
			setRowData(i + _column);
		}
		drawRow(5 + _row); drawRow(7 + _row);
		setRowData(9 + _column);
		drawRow(6 + _row);
		clearData();
		setRowData(5 + _column);
		drawRow(2 + _row); drawRow(10 + _row);
		setRowData(6 + _column);
		drawRow(3 + _row); drawRow(9 + _row);
		setRowData(7 + _column);
		drawRow(4 + _row); drawRow(8 + _row);
		break;

	case 1: //to player
		clearData();
		for (int i = 1; i < 9; i++)
		{
			setRowData(i + _column);
		}
		drawRow(5 + _row); drawRow(7 + _row);
		setRowData(0 + _column);
		drawRow(6 + _row);
		clearData();
		setRowData(4 + _column);
		drawRow(2 + _row); drawRow(10 + _row);
		setRowData(3 + _column);
		drawRow(3 + _row); drawRow(9 + _row);
		setRowData(2 + _column);
		drawRow(4 + _row); drawRow(8 + _row);
		break;

	case 2: //to left from player view
		clearData();
		setRowData(4 + _column);
		drawRow(0 + _row);
		setRowData(3 + _column); setRowData(5 + _column);
		drawRow(1 + _row); drawRow(5 + _row); drawRow(6 + _row); 
		drawRow(7 + _row); drawRow(8 + _row);
		setRowData(2 + _column); setRowData(6 + _column);
		drawRow(2 + _row);
		setRowData(1 + _column); setRowData(7 + _column);
		drawRow(3 + _row);
		setRowData(0 + _column); setRowData(8 + _column);
		drawRow(4 + _row);
		break;

	case 3: //to right from player view
		clearData();
		setRowData(4 + _column);
		drawRow(8 + _row);
		setRowData(3 + _column); setRowData(5 + _column);
		drawRow(7 + _row); drawRow(3 + _row); drawRow(2 + _row); 
		drawRow(1 + _row); drawRow(0 + _row);
		setRowData(2 + _column); setRowData(6 + _column);
		drawRow(6 + _row);
		setRowData(1 + _column); setRowData(7 + _column);
		drawRow(5 + _row);
		setRowData(0 + _column); setRowData(8 + _column);
		drawRow(4 + _row);
		break;
	}

}