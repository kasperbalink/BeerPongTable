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
	digitalWrite(latchPin, LOW);
	//minnen uit
	shiftOut(dataPin, clockPin, LSBFIRST, ~0);
	shiftOut(dataPin, clockPin, LSBFIRST, ~0);

	//plussen uit
	shiftOut(dataPin, clockPin, LSBFIRST, 0);
	shiftOut(dataPin, clockPin, LSBFIRST, 0);
	shiftOut(dataPin, clockPin, LSBFIRST, 0);
	digitalWrite(latchPin, HIGH);
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
	for (int m = 0; m < MIN; m++)
	{
		for (int i = 0; i < PLUS; i++)
		{
			setRowData(i);
		}
		drawRow(m);
	}
}