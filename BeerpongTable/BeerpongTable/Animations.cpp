#pragma once
#include "Animations.h"


//size is thickness of line, size 0 = 1 line thick
void upToDown(int size, int timeBetweenSteps)
{
	for (int i = 0; i <= MIN; i++)
	{
		for (int x = 0; x < size; x++)
		{
			row(i - x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void downToUp(int size, int timeBetweenSteps)
{
	for (int i = MIN; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			row(i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void leftToRight(int size, int timeBetweenSteps)
{
	for (int i = 0; i <= PLUS; i++)
	{
		for (int x = 0; x < size; x++)
		{
			column(i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void rightToLeft(int size, int timeBetweenSteps)
{
	for (int i = PLUS; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			column(i - x, timeBetweenSteps);
		}
	}
}

//timeBetweenSteps is time between simleys
void smileyBlijToBoos(int timeBetweenSteps)
{
	smileyBlij(timeBetweenSteps);
	smileyNeutraal(timeBetweenSteps);
	smileyBoos(timeBetweenSteps);
}

//timeBetweenSteps is time between simleys
void smileyBoosToBlij(int timeBetweenSteps)
{
	smileyBoos(timeBetweenSteps);
	smileyNeutraal(timeBetweenSteps);
	smileyBlij(timeBetweenSteps);	
}


/// <param name="direction"> Direction of the arrow. </param>
/// <param name="_column">  Column offset.</param>
/// <param name="_row">  Row offset.</param>
/// <param name="timeBetweenSteps">  Time between moving</param>


void movingArrow(int direction, int _column, int _row, int timeBetweenSteps)
{
	elapsedMillis tempTimer;

	if (direction == 0)
	{
		
		for (int i = -9; i < PLUS; i++)
		{
			tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				arrow(direction, _column + i, _row);
			}
		}
	}
	else if (direction == 1)
	{

		for (int i = PLUS + 9; i >= 0; i--)
		{
			tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				arrow(direction, _column + i, _row);
			}
		}
	}
	else if (direction == 2)
	{

		for (int i = -9; i < MIN; i++)
		{
			tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				arrow(direction, _column, _row + i);
			}
		}
	}
	else if (direction == 3)
	{

		for (int i = MIN + 9; i >= 0; i--)
		{
			tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				arrow(direction, _column, _row + i);
			}
		}
	}
}