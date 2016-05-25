#pragma once
#include "Columns.h"



void column(int player, int column)
{
	clearData(player);
	setRowData(player, column);
	for (int i = 0; i <= MIN; i++)
	{
		drawRow(player, i);
	}
}

void column(int player, int _column, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		column(player, _column);
	}
}

void columnBig(int player, int starColumn, int endColumn)
{
	clearData(player);
	for (int i = starColumn; i < endColumn; i++)
	{
		setRowData(player, i);
	}
	for (int i = 0; i < MIN; i++)
	{
		drawRow(player, i);
	}
}

void columnBig(int player, int startColumn, int endColumn, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		columnBig(player, startColumn, endColumn);
	}
}

void columnInside(int player, int column)
{
	clearData(player);
	setRowData(player, column);
	for (int i = 1; i < MIN; i++)
	{
		drawRow(player, i);
	}
}
