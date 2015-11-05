#pragma once
#include "Rows.h"




void row(int row)
{
	if (row == 0 || row == 18)
	{
		clearData();
		for (int i = 0; i < PLUS; i++)
		{
			setRowData(i);
		}
		drawRow(row);
	}
	else
	{
		clearData();
		for (int i = 1; i < PLUS; i++)
		{
			setRowData(i);
		}
		drawRow(row);
		clearData();
		setRowData(0);
		setRowData(18);
		drawRow(row);
	}
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
	for (int i = startRow; i < endRow; i++)
	{
		row(i);
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
	for (int i = 1; i < PLUS -1; i++)
	{
		setRowData(i);
	}
	drawRow(row);
}