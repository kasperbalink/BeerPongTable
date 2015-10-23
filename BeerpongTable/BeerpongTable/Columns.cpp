#pragma once
#include "Columns.h"



void column(int column)
{
	clearData();
	setRowData(column);
	for (int i = 0; i <= MIN; i++)
	{
		drawRow(i);
	}
}

void column(int _column, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		column(_column);
	}
}

void columnBig(int starColumn, int endColumn)
{
	clearData();
	for (int i = starColumn; i < endColumn; i++)
	{
		setRowData(i);
	}
	for (int i = 0; i <= MIN; i++)
	{
		drawRow(i);
	}
}

void columnBig(int startColumn, int endColumn, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		columnBig(startColumn, endColumn);
	}
}

void columnInside(int column)
{
	clearData();
	setRowData(column);
	for (int i = 1; i < MIN; i++)
	{
		drawRow(i);
	}
}
