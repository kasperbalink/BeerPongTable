#pragma once
#include "Images.h"
#include "ImagesData.h"

void logo(int player)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getLogo()[i];
	}
	drawTable(player, animation);
}

void logo(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getLogo()[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void pacMan(int player, int timeBetweenSteps, int totalTime)
{
	int stepTime = timeBetweenSteps;
	
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		int shift = -6;
		long dots = 0b100100100100100100;
		while (shift <= 18)
		{	
			if (shift <= -6)
			{
				dots = 0b101010101010101010;
			}
			else if (shift <= -4)
			{
				dots = 0b001010101010101010;
			}
			else if (shift <= -2)
			{
				dots = 0b000010101010101010;
			}
			else if (shift <= 0)
			{
				dots = 0b000000101010101010;
			}
			else if (shift <= 2)
			{
				dots = 0b000000001010101010;
			}
			else if (shift <= 4)
			{
				dots = 0b000000000010101010;
			}
			else if (shift <= 6)
			{
				dots = 0b000000000000101010;
			}
			else if (shift <= 8)
			{
				dots = 0b000000000000001010;
			}
			else if (shift <= 10)
			{
				dots = 0b000000000000000010;
			}
			else if (shift <= 12)
			{
				dots = 0b000000000000000000;
			}
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getPacMan(1)[i], shift);
				animation[6] |= dots;
			}
			elapsedMillis timer = 0;
			while (timer < stepTime)
			{
				drawTable(player, animation);
			}

			for (int i = 0; i < 13; i++)
			{
				animation[i] = 0;
			}
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getPacMan(2)[i], shift);
				animation[6] |= dots;
			}
			timer = 0;
			while (timer < stepTime)
			{
				drawTable(player, animation);
			}
			shift++;
			

			for (int i = 0; i < 13; i++)
			{
				animation[i] = 0;
			}
			
			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getPacMan(3)[i], shift);
				animation[6] |= dots;
			}
			timer = 0;
			while (timer < stepTime)
			{
				drawTable(player, animation);
			}

			for (int i = 0; i < 13; i++)
			{
				animation[i] = 0;
			}

			for (int i = 0; i < 13; i++)
			{
				animation[i] |= shiftRight(getPacMan(4)[i], shift);
				animation[6] |= dots;
			}
			timer = 0;
			while (timer < stepTime)
			{
				drawTable(player, animation);
			}
			shift++;
		}
	}
}

void thumb(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getThumb()[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void thumbDown(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getThumbDown()[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

long* getLogo()
{
	return logoArray;
}

long * getPacMan(int step)
{
	switch (step)
	{
	case 1:
		return pacMan3;
		break;
	case 2:
		return pacMan2;
		break;
	case 3:
		return pacMan1;
		break;
	case 4:
		return pacMan2;
		break;
	}
}

long * getThumb()
{
	return thumbArray;
}

long * getThumbDown()
{
	return thumbDownArray;
}
