#pragma once
#include "Animations.h"
#include <Arduino.h>


void testAnimation(int player)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//char charArray[3] = { 'h', 'o', 'i' };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSquareArray(7)[i];
	}
	drawTable(player, animation);

}

void ballAnimation(int player, int timeBetweenSteps, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int vertical = 1;
	int vShift = 0;
	int horizontal = 1;
	int hShift = 0;

	elapsedMillis timer = 0;
	while (timer < totalTime)
	{
		//	testAnimation(player);
		if (animation[10] > 0 && animation[11] > 0)
		{
			vShift = 1;
		}
		else if (animation[1] > 0 && animation[2] > 0)
		{
			vShift = 0;
		}
		for (int i = 0; i < 13; i++)
		{
			if (animation[i] == (long)0b000000000000000110)
			{
				hShift = 0;
			}
			else if (animation[i] > (long)0b0100000000000000000)
			{
				hShift = 1;
			}
		}
		if (vShift == 0) //omlaag
		{
			vertical--;
		}
		else if (vShift == 1) //omhoog
		{
			vertical++;
		}
		if (hShift == 0) //links
		{
			horizontal--;
		}
		if (hShift == 1) //rechts
		{
			horizontal++;
		}
		for (int i = 0; i < 13; i++)
		{
			animation[i] = shiftRight(shiftUp(getBallArray(1), i, vertical), horizontal);
		}
		elapsedMillis timer2 = 0;
		while (timer2 < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
	}

}

void upToDown(int player, int size, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		int shift = 0 - size;
		while (shift < 13 + size)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

			for (int i = 0; i < 13; i++)
			{
				for (int x = 0; x < size; x++)
				{
					if (i + x + shift >= 0 && i + x + shift < 13)
					{
						animation[i + x + shift] |= getRowArray()[i];
					}
				}
			}
			shift++;
			elapsedMillis timer1 = 0;
			while (timer1 < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
		}
	}
	yield();
}

//size is thickness of line, size 0 = 1 line thick
void downToUp(int player, int size, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		int shift = 13 + size;
		while (shift > 0 - size)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

			for (int i = 0; i < 13; i++)
			{
				for (int x = 0; x < size; x++)
				{
					if (i + x + shift >= 0 && i + x + shift < 13)
					{
						animation[i + x + shift] |= getRowArray()[i];
					}
				}
			}
			shift--;
			elapsedMillis timer1;
			while (timer1 < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
		}
	}
	yield();
}

//size is thickness of line, size 0 = 1 line thick
void leftToRight(int player, int size, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer0;
	while (timer0 < totalTime)
	{
		int shift = 0;
		while (shift < 18 + size)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				for (int x = 0; x < size; x++)
				{
					animation[i] |= shiftRight(getColumnArray()[i], x + shift);
				}

			}
			elapsedMillis timer;
			while (timer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift++;
		}
	}

}

//size is thickness of line, size 0 = 1 line thick
void rightToLeft(int player, int size, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer0;
	while (timer0 < totalTime)
	{
		int shift = 18;
		while (shift > 0 - size)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				for (int x = 0; x < size; x++)
				{
					animation[i] |= shiftRight(getColumnArray()[i], x + shift);
				}

			}
			elapsedMillis timer;
			while (timer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift--;
		}
	}
}

//timeBetweenSteps is time between simleys
void smileyBlijToBoos(int player, int timeBetweenSteps)
{
	smileyBlij(player, timeBetweenSteps);
	smileyNeutraal(player, timeBetweenSteps);
	smileyBoos(player, timeBetweenSteps);
}

void smileyBlijToBoos(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		smileyBlij(player, timeBetweenSteps);
		smileyNeutraal(player, timeBetweenSteps);
		smileyBoos(player, timeBetweenSteps);
	}
}

//timeBetweenSteps is time between simleys
void smileyBoosToBlij(int player, int timeBetweenSteps)
{
	smileyBoos(player, timeBetweenSteps);
	smileyNeutraal(player, timeBetweenSteps);
	smileyBlij(player, timeBetweenSteps);
}

void smileyBoosToBlij(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		smileyBoos(player, timeBetweenSteps);
		smileyNeutraal(player, timeBetweenSteps);
		smileyBlij(player, timeBetweenSteps);
	}
}

void christmasTreeLeftRight(int player, int timeBetweenSteps, int totalTime) {
	elapsedMillis timer0;
	while (timer0 < totalTime)
	{
		int shift = -15;
		while (shift < 15)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getChristmasTree()[i], shift - 20);
				animation[i] |= shiftRight(getChristmasTree()[i], shift - 10);
				animation[i] |= shiftRight(getChristmasTree()[i], shift);
				animation[i] |= shiftRight(getChristmasTree()[i], shift + 10);
				animation[i] |= shiftRight(getChristmasTree()[i], shift + 20);
			}
			elapsedMillis timer;
			while (timer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift++;
		}
	}
}

void christmasTreeRightLeft(int player, int timeBetweenSteps, int totalTime) {
	elapsedMillis timer0;
	while (timer0 < totalTime)
	{
		int shift = 15;
		while (shift > -15)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getChristmasTree()[i], shift - 20);
				animation[i] |= shiftRight(getChristmasTree()[i], shift - 10);
				animation[i] |= shiftRight(getChristmasTree()[i], shift);
				animation[i] |= shiftRight(getChristmasTree()[i], shift + 10);
				animation[i] |= shiftRight(getChristmasTree()[i], shift + 20);
			}
			elapsedMillis timer;
			while (timer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift--;
		}
	}
}
