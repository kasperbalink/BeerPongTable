#pragma once
#include "Scores.h"

void scoreSquare(int player)
{
	clearData(player);
	for (int i = 2; i < PLUS - 1; i++)
	{
		setRowData(player, i);
	}
	drawRow(player, 1);
	drawRow(player, 11);

	clearData(player);

	setRowData(player, 2);
	setRowData(player, 16);
	for (int x = 2; x < MIN - 1; x++)
	{
		drawRow(player, x);
	}
}
//number between 0 - 99 with square around it
void showScore(int player, int _number)
{
	//scoreSquare(player);
	//number(player, _number);
}

void showScore(int player, int _number, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		showScore(player, _number);
	}
}