#pragma once
#include "Shapes.h"
#include "ShapeData.h"

void square_(int player, int size, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSquareArray(size)[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void arrowLeft(int player, int timeBetweenSteps)
{
	int shift = 18;
	while (shift > -10)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getArrowLeft()[i], shift);
		}
		elapsedMillis tempTimer;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
		shift--;
	}
}
void arrowRight(int player, int timeBetweenSteps)
{
	int shift = -10;
	while (shift < 18)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftRight(getArrowRight()[i], shift);
		}
		elapsedMillis tempTimer;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
		shift++;
	}
}

void arrowUp(int player, int timeBetweenSteps)
{
	int shift = -12;
	while (shift < 9)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getArrowUp(), i, shift);
		}
		elapsedMillis tempTimer;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
		shift++;
	}
}
void arrowDown(int player, int timeBetweenSteps)
{
	int shift = 9;
	while (shift < -12)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 13; i++)
		{
			animation[i] |= shiftUp(getArrowDown(), i, shift);
		}
		elapsedMillis tempTimer;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
		shift--;
	}
}

long* getSquareArray(int size)
{
	switch (size)
	{
	case 1:
		return square1;
		break;
	case 2:
		return square2;
		break;
	case 3:
		return square3;
		break;
	case 4:
		return square4;
		break;
	case 5:
		return square5;
		break;
	case 6:
		return square6;
		break;
	case 7:
		return square7;
		break;
	default:
		break;
	}
}
long* getBallArray(int size)
{
	switch (size)
	{
	case 1:
		return ball1;
		break;
	case 2:
		return ball2;
		break;
	default:
		break;
	}
	return ball1;
}
long* getBracketLeft()
{
	return leftAngleBracketArray;
}
long* getBracketRight()
{
	return rightAngleBracketArray;
}
long* getArrowUp()
{
	return arrowUpArray;
}
long* getArrowDown()
{
	return arrowDownArray;
}
long* getArrowLeft()
{
	return arrowLeftArray;
}
long* getArrowRight()
{
	return arrowRightArray;
}