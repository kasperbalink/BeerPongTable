#pragma once
#include "Rows.h"




void row(int row)
{
	clearData();
	for (int i = 0; i <= PLUS; i++)
	{
		setRowData(i);
	}
	drawRow(row);
}

void row(int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		row(_row);
	}
}

void rowBig(int startRow, int endRow)
{
	clearData();
	for (int i = 1; i < PLUS; i++)
	{
		setRowData(i);
	}
	for (int i = startRow; i < endRow; i++)
	{
		drawRow(i);
	}
}

void rowBig(int startRow, int endRow, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		rowBig(startRow, endRow);
	}
}

void rowInside(int row)
{
	clearData();
	for (int i = 1; i < PLUS; i++)
	{
		setRowData(i);
	}
	drawRow(row);
}