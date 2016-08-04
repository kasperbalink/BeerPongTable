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

void arrowLeft(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		int shift = 18;
		while (shift > -10 && timer1 < totalTime)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getArrowLeft()[i], shift);
			}
			elapsedMillis tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift--;
		}
	}

}
void arrowRight(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		int shift = -10;
		while (shift < 18 && timer1 < totalTime)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getArrowRight()[i], shift);
			}
			elapsedMillis  tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift++;
		}
	}

}
void arrowDown(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		while (timer1 < totalTime)
		{
			int shift = -12;
			while (shift < 9 && timer1 < totalTime)
			{
				long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
				for (int i = 0; i < 13; i++)
				{
					animation[i] |= shiftRight(shiftUp(getArrowUp(), i, shift), 10);
					animation[i] |= shiftUp(getArrowUp(), i, shift);
				}
				elapsedMillis  tempTimer = 0;
				while (tempTimer < timeBetweenSteps)
				{
					drawTable(player, animation);
				}
				shift++;
			}
		}
	}
}
void arrowUp(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		int shift = 9;
		while (shift > -12 && timer1 < totalTime)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(shiftUp(getArrowDown(), i, shift), 10);
				animation[i] |= shiftUp(getArrowDown(), i, shift);
			}
			elapsedMillis  tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift--;
		}
	}

}

void bracketLeft(int player, int count, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		int shift = 6;
		while (shift >= -(count * 18) && timer1 < totalTime)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				for (int c = 0; c < count; c++)
				{
					animation[i] |= shiftRight(getBracketLeft()[i], shift + (c * 6));
				}
			}
			elapsedMillis  tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift--;
		}
	}

}

void bracketRight(int player, int count, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		int shift = -6;
		while (shift <= (count * 18) && timer1 < totalTime)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				for (int c = 0; c < count; c++)
				{
					animation[i] |= shiftRight(getBracketRight()[i], shift + (c * -6));
				}
			}
			elapsedMillis tempTimer = 0;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, animation);
			}
			shift++;
		}
	}
}

void circleOutIn(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		for (int c = 1; c <= 7; c++)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			elapsedMillis timer2 = 0;
			while (timer2 < timeBetweenSteps && timer1 < totalTime)
			{
				for (int i = 0; i < 13; i++)
				{
					animation[i] |= getCircle(c)[i];
				}
				drawTable(player, animation);
			}
		}
	}
}

void circleInOut(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		for (int c = 7; c >= 1; c--)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			elapsedMillis timer2 = 0;
			while (timer2 < timeBetweenSteps)
			{
				for (int i = 0; i < 13; i++)
				{
					animation[i] |= getCircle(c)[i];
				}
				drawTable(player, animation);
			}
		}
	}
}

void diagonalLeftUpRight(int player, int size, int count, int timeBetweenSteps, int totalTime)
{

	int vertical = -12;

	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

		for (int s = 0; s < size; s++)
		{
			for (int i = 0; i < 13; i++)
			{
				for (int c = 0; c < count; c++)
				{
					animation[i] |= shiftRight(getDiagonalLeftUp()[i], (vertical + s) + (c*(-size*2)));
				}
			}
		}


		elapsedMillis timer2 = 0;
		while (timer2 < timeBetweenSteps)
		{
			drawTable(player, animation);
		}
		vertical++;
		if (vertical > 18*count)
		{
			vertical = -12;
		}
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
long* getCircle(int size) {
	switch (size)
	{
	case 1:
		return circle1;
		break;
	case 2:
		return circle2;
		break;
	case 3:
		return circle3;
		break;
	case 4:
		return circle4;
		break;
	case 5:
		return circle5;
		break;
	case 6:
		return circle6;
		break;
	case 7:
		return circle7;
		break;
	default:
		break;
	}
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
long* getDiagonalRighUp()
{
	return diagonalRightUp;
}
long* getDiagonalLeftUp()
{
	return diagonalLeftUp;
}