#pragma once
#include "Columns.h"
#include "ColumnData.h"


void column(int player, int column)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getColumnArray()[i], column);
	}
	drawTable(player, animation);
}
void column(int player, int column, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getColumnArray()[i], column);
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void columnBig(int player, int startColumn, int endColumn)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int c = startColumn; c < endColumn; c++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getColumnArray()[i], c);
		}
	}
	drawTable(player, animation);
}
void columnBig(int player, int startColumn, int endColumn, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int c = startColumn; c < endColumn; c++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getColumnArray()[i], c);
		}
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void columnInside(int player, int column)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getInsideColumnArray()[i], column);
	}
	drawTable(player, animation);
}
void columnInside(int player, int column, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getInsideColumnArray()[i], column);
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void columnBigInside(int player, int startColumn, int endColumn)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int c = startColumn; c < endColumn; c++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getInsideColumnArray()[i], c);

		}
	}
	drawTable(player, animation);
}
void columnBigInside(int player, int startColumn, int endColumn, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int c = startColumn; c < endColumn; c++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getInsideColumnArray()[i], c);

		}
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

long* getColumnArray()
{
	return leftColumn;
}
long* getInsideColumnArray()
{
	return insideColumn;
}
