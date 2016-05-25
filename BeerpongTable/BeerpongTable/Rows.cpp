#pragma once
#include "Rows.h"




void row(int player, int row)
{
		clearData(player);
		for (int i = 1; i < PLUS; i++)
		{
			setRowData(player, i);
		}
		drawRow(player,row);
		clearData(player);
		setRowData(player, 0);
		setRowData(player, 18);
		drawRow(player,row);
	
}

void row(int player, int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		row(player, _row);

	}
}

void rowBig(int player, int startRow, int endRow)
{
	clearData(player);
	for (int i = startRow; i < endRow; i++)
	{
		row(player, i);
	}
}

void rowBig(int player, int startRow, int endRow, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		rowBig(player, startRow, endRow);
	}
}

void rowInside(int player, int row)
{
	clearData(player);
	for (int i = 1; i < PLUS -1; i++)
	{
		setRowData(player, i);
	}
	drawRow(player,row);
}