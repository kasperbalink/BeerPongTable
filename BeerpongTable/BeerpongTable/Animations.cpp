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