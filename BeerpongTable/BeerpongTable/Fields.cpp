#pragma once
#include "Fields.h"
#include "Rows.h"
#include "Columns.h"
//FIELDS: INSIDE, OUTSIDE, BOTH, NOTHING
void outsideOn(int player)
{
	row(player, 0);
	row(player, MIN);
	column(player, 0);
	column(player, PLUS);
}
void outsideOn(int player, int interval)
{
	allOff(player);
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		outsideOn(player);
	}
}

void insideOn(int player, int interval)
{
	allOff(player);
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 1; i < MIN; i++)
		{
			rowInside(player, i);
		}
	}
}

void allOff(int player, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		allOff(player);
	}
}

void allOff(int player)
{
	if (player == 1)
	{
		digitalWrite(latchPin_P1, LOW);
		//minnen uit
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~0);
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~0);

		//plussen uit
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, 0);
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, 0);
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, 0);
		digitalWrite(latchPin_P1, HIGH);
	}
	else if (player == 2)
	{
		digitalWrite(latchPin_P2, LOW);
		//minnen uit
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~0);
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~0);

		//plussen uit
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, 0);
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, 0);
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, 0);
		digitalWrite(latchPin_P2, HIGH);
	}
	yield();
}

void allOn(int player, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		allOn(player);
	}
}

void allOn(int player)
{
	for (int p = 0; p <= MIN; p++)
	{
		row(player, p);
	}
}