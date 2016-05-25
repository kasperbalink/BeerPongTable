#pragma once
#include "Shapes.h"

int square_(int player, int size, int interval)
{
	if (size > MIN / 2)
	{
		return -1;
	}

	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		square_(player, size);
	}
}

int square_(int player, int size)
{

	if (size > MIN / 2)
	{
		return -1;
	}
	clearData(player);
	for (int i = 0 + size; i <= PLUS - size; i++)
	{
		setRowData(player, i);
	}
	drawRow(player, 0 + size);
	drawRow(player, MIN - size);
	clearData(player);
	setRowData(player, size);
	setRowData(player, PLUS - size);
	for (int i = 0 + size; i <= MIN - size; i++)
	{
		drawRow(player, i);
	}
	return 0;
}

void bracket(int player, int direction, int _column, int _row)
{

}

void arrow(int player, int direction, int _column, int _row, int interval) //arrow method with interval
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		arrow(player, direction, _column, _row);
	}
}


//_column = verplaatsing links/rechts
//_row = verplaatsing boven/benden
//_column & _row == 0: pijl aan spelers kant
//direction: 0-to center, 1-to player, 2-left, 3-right (from player view)
void arrow(int player, int direction, int _column, int _row)
{
	switch (direction)
	{
	case 0: //to center
		clearData(player);
		for (int i = 0; i < 8; i++)
		{
			setRowData(player, i + _column);
		}
		drawRow(player, 5 + _row); drawRow(player, 7 + _row);
		setRowData(player, 9 + _column);
		drawRow(player, 6 + _row);
		clearData(player);
		setRowData(player, 5 + _column);
		drawRow(player, 2 + _row); drawRow(player, 10 + _row);
		setRowData(player, 6 + _column);
		drawRow(player, 3 + _row); drawRow(player, 9 + _row);
		setRowData(player, 7 + _column);
		drawRow(player, 4 + _row); drawRow(player, 8 + _row);
		break;

	case 1: //to player
		clearData(player);
		for (int i = 1; i < 9; i++)
		{
			setRowData(player, i + _column);
		}
		drawRow(player, 5 + _row); drawRow(player, 7 + _row);
		setRowData(player, 0 + _column);
		drawRow(player, 6 + _row);
		clearData(player);
		setRowData(player, 4 + _column);
		drawRow(player, 2 + _row); drawRow(player, 10 + _row);
		setRowData(player, 3 + _column);
		drawRow(player, 3 + _row); drawRow(player, 9 + _row);
		setRowData(player, 2 + _column);
		drawRow(player, 4 + _row); drawRow(player, 8 + _row);
		break;

	case 2: //to left from player view
		clearData(player);
		setRowData(player, 4 + _column);
		drawRow(player, 0 + _row);
		setRowData(player, 3 + _column); setRowData(player, 5 + _column);
		drawRow(player, 1 + _row); drawRow(player, 5 + _row); drawRow(player, 6 + _row);
		drawRow(player, 7 + _row); drawRow(player, 8 + _row);
		setRowData(player, 2 + _column); setRowData(player, 6 + _column);
		drawRow(player, 2 + _row);
		setRowData(player, 1 + _column); setRowData(player, 7 + _column);
		drawRow(player, 3 + _row);
		setRowData(player, 0 + _column); setRowData(player, 8 + _column);
		drawRow(player, 4 + _row);
		break;

	case 3: //to right from player view
		clearData(player);
		setRowData(player, 4 + _column);
		drawRow(player, 8 + _row);
		setRowData(player, 3 + _column); setRowData(player, 5 + _column);
		drawRow(player, 7 + _row); drawRow(player, 3 + _row); drawRow(player, 2 + _row);
		drawRow(player, 1 + _row); drawRow(player, 0 + _row);
		setRowData(player, 2 + _column); setRowData(player, 6 + _column);
		drawRow(player, 6 + _row);
		setRowData(player, 1 + _column); setRowData(player, 7 + _column);
		drawRow(player, 5 + _row);
		setRowData(player, 0 + _column); setRowData(player, 8 + _column);
		drawRow(player, 4 + _row);
		break;
	}

}