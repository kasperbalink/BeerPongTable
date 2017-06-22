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


void logo2(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getLogo2()[i];
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

void heart(int player, int size, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getHeart(size)[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void heartFilled(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int h = 1; h < 5; h++)
	{
		for (int i = 0; i < 13; i++)
		{
			animation[i] += getHeart(h)[i];
		}
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void heartInToOut(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		for (int h = 4; h > 0; h--)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			elapsedMillis timer2 = 0;
			while (timer2 < timeBetweenSteps && timer1 < totalTime)
			{
				for (int i = 0; i < 13; i++)
				{
					animation[i] |= getHeart(h)[i];
				}
				drawTable(player, animation);
			}
		}
	}
}
void heartOutToIn(int player, int timeBetweenSteps, int totalTime)
{
	elapsedMillis timer1;
	while (timer1 < totalTime)
	{
		for (int h = 1; h < 4; h++)
		{
			long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
			elapsedMillis timer2 = 0;
			while (timer2 < timeBetweenSteps && timer1 < totalTime)
			{
				for (int i = 0; i < 13; i++)
				{
					animation[i] |= getHeart(h)[i];
				}
				drawTable(player, animation);
			}
		}
	}
}

void labelALogo(int player, int totalTime)
{
  long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
  for (int i = 0; i < 13; i++)
  {
    animation[i] |= getLabelALogo()[i];
  }
  elapsedMillis tempTimer;
  while (tempTimer < totalTime)
  {
    drawTable(player, animation);
  }
}

long* getHeart(int size)
{
	switch (size)
	{
	case 1:
		return heartArray1; //groot
		break;
	case 2:
		return heartArray2;
		break;
	case 3:
		return heartArray3;
		break;
	case 4:
		return heartArray4; //klein
		break;
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

long * getLogo2()
{
	return logo2Array;
}

long * getLabelALogo() 
{
  return labelALogoArray;
}

