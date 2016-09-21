#pragma once
#include "Fields.h"
#include "Rows.h"
#include "Columns.h"


void outsideOn(int player)
{
	long animation[13] = { 
		0b1111111111111111111,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1111111111111111111 };
	drawTable(player, animation);
}
void outsideOn(int player, int totalTime)
{
	long animation[13] = {
		0b1111111111111111111,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1000000000000000001,
		0b1111111111111111111 };
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void insideOn(int player)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 1; i < 12; i++)
	{
		animation[i] |= getInsideRowArray()[1];
	}
	drawTable(player, animation);
}
void insideOn(int player, int totalTime)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 1; i < 12; i++)
	{
		animation[i] |= getInsideRowArray()[1];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
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
void allOff(int player, int totalTime)
{
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		allOff(player);
	}
}

void allOn(int player, int totalTime)
{
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		insideOn(player);
		outsideOn(player);
	}
}
void allOn(int player)
{
	insideOn(player);
	outsideOn(player);
}

void randomLeds(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 1; i < 12; i++)
		{
			long tmp = random(0b000000000000000000, 0b0111111111111111110);
			if (tmp % 2 != 0)
			{
				tmp = tmp - 1;
			}
			animation[i] |= tmp;
		}
		elapsedMillis timer2 = 0;
		while (timer2 < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
	}
}