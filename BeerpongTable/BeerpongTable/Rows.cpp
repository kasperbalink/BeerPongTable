#pragma once
#include "Rows.h"
#include "RowData.h"

void row(int player, int row)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftUp(getRowArray(), i, row);
	}
	drawTable(player, animation);
}
void row(int player, int row, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftUp(getRowArray(), i, row);
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void rowBig(int player, int startRow, int endRow)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int r = startRow; r < endRow; r++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getRowArray(), i, -r);
		}
	}
	drawTable(player, animation);
}
void rowBig(int player, int startRow, int endRow, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int r = startRow; r < endRow; r++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getRowArray(), i, -r);
		}
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void rowInside(int player, int row)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftUp(getInsideRowArray(), i, row);
	}
	drawTable(player, animation);
}
void rowInside(int player, int _row, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftUp(getInsideRowArray(), i, _row);
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void rowBigInside(int player, int startRow, int endRow)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int r = startRow; r < endRow; r++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getInsideRowArray(), i, -r);
		}
	}
	drawTable(player, animation);

}
void rowBigInside(int player, int startRow, int endRow, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int r = startRow; r < endRow; r++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getInsideRowArray(), i, -r);
		}
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void randomRows(int player, int count, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int c = 0; c < count; c++)
		{
			int x = random(0, 12);
			animation[x] |= 0b0111111111111111110;
		}

		elapsedMillis timer1 = 0;
		while (timer1 < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
	}
}


long* getInsideRowArray()
{
	return insideRow;
}
long* getRowArray()
{
	return topRow;
}