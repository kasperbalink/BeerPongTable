#pragma once
#include "Animations.h"



void testAnimation()
{
	int animation[13];
	//char charArray[3] = { 'h', 'o', 'i' };
	for (int i = 0; i < 13; i++)
	{
		animation[i] = getSquareArray(5)[i];
		//setRawRowData(1, getSquareArray(5)[i]);
		//drawRow(1, i);
		//delay(1000);
	}

	//while loop of in apart thread
	while (true)
	{
		drawTable(1, animation);
	}
}

void ballAnimation()
{
	int animation[13];
	int vertical = 0; //huidige y positie; -0 <= -7
	int vShift = 0; //0 = omhoog, 1 = omlaag
	int horizontal = 0; //huidige x positie 0 <= 13
	int hShift = 0;//0 rechts, 1 links
	
	if (vShift == 0) //omhoog
	{
		vertical++;
	}
	else if (vShift == 1) //omlaag
	{
		vertical--;
	}
	if (hShift == 0) //recht
	{
		horizontal++;
	}
	else if (hShift == 1) //links
	{
		horizontal--;
	}
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getBallArray(1)[i], 4);
		animation[i] |= shiftRight(getBallArray(1)[i], 6);
		//animation[i] = &shiftRight(&getBallArray(1)[i], 4);
	}
	drawTable(1, animation);

}

void clearArray(int inputArray[13])
{
	for (int i = 0; i < 13; i++)
	{
		inputArray[i] = 0;
	}
}

int shiftRight(int input, int bits)
{	/*
	Use like this:
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= shiftRight(getBallArray()[i], 10);
		animation[i] |= 1;
	}
	*/
	return input >> bits;
}

void shiftUp(int input[13], int bits)
{
	/*
	Use after shifRight
	Like this: shiftUp(animation, 2);
	*/
	int tmp[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		tmp[i] = input[i];
	}
	for (int i = 0; i < 13; i++)
	{
		int y = i + bits;
		if (y <= 0)
			input[i] = 0;
		else if (y >= 13)
			input[i] = 0;
		else
			input[i] = tmp[y];
	}
}

//size is thickness of line, size 0 = 1 line thick

void upToDown(int player, int size, int timeBetweenSteps)
{;
	for (int i = 0; i <= MIN; i++)
	{
		for (int x = 0; x < size; x++)
		{
			row(player, i - x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void downToUp(int player, int size, int timeBetweenSteps)
{
	for (int i = MIN; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			row(player, i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void leftToRight(int player, int size, int timeBetweenSteps)
{
	for (int i = 0; i <= PLUS; i++)
	{
		for (int x = 0; x < size; x++)
		{
			column(player, i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void rightToLeft(int player, int size, int timeBetweenSteps)
{
	for (int i = PLUS; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			column(player, i - x, timeBetweenSteps);
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

//timeBetweenSteps is time between simleys
void smileyBoosToBlij(int player, int timeBetweenSteps)
{
	smileyBoos(player, timeBetweenSteps);
	smileyNeutraal(player, timeBetweenSteps);
	smileyBlij(player, timeBetweenSteps);
}
