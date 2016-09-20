#pragma once
#include "CupAnimations.h"

void triangle(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		allCupsOff(player);
		addCup(player, 0);
		addCup(player, 6);
		addCup(player, 9);
		addCup(player, 4);
		elapsedMillis timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		allCupsOff(player);
		addCup(player, 2);
		addCup(player, 8);
		addCup(player, 3);
		addCup(player, 4);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		allCupsOff(player);
		addCup(player, 5);
		addCup(player, 7);
		addCup(player, 1);
		addCup(player, 4);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
	}
}
void fourToOne(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		allCupsOff(player, timeBetweenSteps);
		addCup(player, 6);
		addCup(player, 7);
		addCup(player, 8);
		addCup(player, 9);
		elapsedMillis timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 3);
		addCup(player, 4);
		addCup(player, 5);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 1);
		addCup(player, 2);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 0);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
	}
}
void oneToFour(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		allCupsOff(player, timeBetweenSteps);
		addCup(player, 0);
		elapsedMillis timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 1);
		addCup(player, 2);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 3);
		addCup(player, 4);
		addCup(player, 5);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
		addCup(player, 6);
		addCup(player, 7);
		addCup(player, 8);
		addCup(player, 9);
		timer = 0;
		while (timer < timeBetweenSteps)
		{
			drawLedCups(player);
		}
	}
}
void randomCups(int player, int count, int timeBetweenSteps, int totalTime)
{
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		for (int i = 0; i < count; i++)
		{
			addCup(player, (int)random(0, 10));
		}
		drawLedCups(player);
		delay(timeBetweenSteps);
		for (int i = 0; i <= 9; i++)
		{
			removeCup(player, i);
		}
	}
}

void allCupsOn(int player, int totalTime)
{
	for (int i = 0; i < 10; i++)
	{
		addCup(player, i);
	}
	elapsedMillis timer;
	while (timer < totalTime)
	{
		drawLedCups(player);
	}
}

void allCupsOff(int player, int totalTime)
{
	for (int i = 0; i < 10; i++)
	{
		removeCup(player, i);
	}
	elapsedMillis timer;
	while (timer < totalTime)
	{
		drawLedCups(player);
	}
}

void allCupsOff(int player)
{
	for (int i = 0; i < 10; i++)
	{
		removeCup(player, i);
	}
	drawLedCups(player);
}



void drawLedCupScore(int player, int cupArray[10], int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		
		for (int i = 0; i < 10; i++)
		{
			if (cupArray[i] == 1)
			{
				addCup(player, i);
			}
			else
			{
				removeCup(player, i);
			}
		}
		drawLedCups(player);
	}
	yield();
}