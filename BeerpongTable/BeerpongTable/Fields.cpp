#pragma once
#include "Fields.h"
#include "Rows.h"
#include "Columns.h"
//FIELDS: INSIDE, OUTSIDE, BOTH, NOTHING
void outsideOn()
{
	row(0);
	row(MIN);
	column(0);
	column(PLUS);
}
void outsideOn(int interval)
{
	allOff();
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		outsideOn();
	}
}

void insideOn(int interval)
{
	allOff();
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 1; i < MIN; i++)
		{
			rowInside(i);
		}
	}
}

void allOff(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		allOff();
	}
}

void allOff()
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

void allOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		allOn();
	}
}

void allOn()
{
	for (int p = 0; p < MIN; p++)
	{
		row(p);
	}
}