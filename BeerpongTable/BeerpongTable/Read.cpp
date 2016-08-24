#pragma once
#include "Read.h"
#include "elapsedMillis.h"
#include <Arduino.h>

int cupsOnP1[10] = { 0,0,0,0,0,0,0,0,0,0 };
int cupsOnP2[10] = { 0,0,0,0,0,0,0,0,0,0 };
void checkCups(int player)
{
	if (player == 1)
	{

	}
	else if (player == 2)
	{
		addRemoveCup(player, 0, -74);
		addRemoveCup(player, 1, -59);
		addRemoveCup(player, 2, -68);
		addRemoveCup(player, 3, -62);
		addRemoveCup(player, 4, -66);
		addRemoveCup(player, 5, -54);
		addRemoveCup(player, 6, -42);
		addRemoveCup(player, 7, -47);
		addRemoveCup(player, 8, -53);
		addRemoveCup(player, 9, -50);
	}
	yield();
}
void addRemoveCup(int player, int cup, int value)
{
	int avg = 0;
	for (int i = 0; i < 4; i++)
	{
		avg += readMux(player, cup + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2);
	}
	if (avg / 4 <= value)// | (readMux(player, cup + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2)) >= 200)
	{
		cupsOnP2[cup] = 1;
	}
	else
	{
		cupsOnP2[cup] = 0;
	}
	yield();

}

void drawLedScore(int player, int totalTime)
{
	elapsedMillis timer;
	while (timer < totalTime)
	{
		checkCups(player);
		for (int i = 0; i < 10; i++)
		{
			if (player == 1)
			{

			}
			else if (player == 2)
			{
				if (cupsOnP2[i] == 1)
				{
					addCup(player, i);
				}
				else
				{
					removeCup(player, i);
				}
			}
		}
		drawLedCups(player);
	}
}

//nodig om score op led paneel te weergeven
int getScore(int player)
{
	checkCups(player);
	int score = 0;
	int scoreCount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (player == 1)
		{
			scoreCount += cupsOnP2[i];
		}
		else if (player == 2)
		{
			scoreCount += cupsOnP2[i];
		}
	}
	return scoreCount;
}

/* verplaatst naar CupAnimations.cpp
void randomLedCups(int player, int count, int interval, int timer)
{
	elapsedMillis tempTimer;
	while (tempTimer < timer)
	{
		for (int i = 0; i < count; i++)
		{
			addCup(player, (int)random(0, 10));
		}
		drawLedCups(player);
		delay(interval);
		for (int i = 0; i <= 9; i++)
		{
			removeCup(player, i);
		}
	}
}
*/

int muxChannel[16][4] = {
	{ 0, 0, 0, 0 }, //channel 0
	{ 1, 0, 0, 0 }, //channel 1
	{ 0, 1, 0, 0 }, //channel 2
	{ 1, 1, 0, 0 }, //channel 3
	{ 0, 0, 1, 0 }, //channel 4
	{ 1, 0, 1, 0 }, //channel 5
	{ 0, 1, 1, 0 }, //channel 6
	{ 1, 1, 1, 0 }, //channel 7
	{ 0, 0, 0, 1 }, //channel 8
	{ 1, 0, 0, 1 }, //channel 9
	{ 0, 1, 0, 1 }, //channel 10
	{ 1, 1, 0, 1 }, //channel 11
	{ 0, 0, 1, 1 }, //channel 12
	{ 1, 0, 1, 1 }, //channel 13
	{ 0, 1, 1, 1 }, //channel 14
	{ 1, 1, 1, 1 } //channel 15
};
int controlPin[] = { s0,s1,s2,s3 };

int readMux(int player, int channel) {

	//loop through the 4 sig
	for (int i = 0; i < 4; i++) {
		digitalWrite(controlPin[i], muxChannel[channel][i]);
	}
	int temp = 0;
	int avg = 5;
	if (player == 1)
	{
		for (int i = 0; i < avg; i++)
		{
			temp += analogRead(SIG_pin_1);
		}
		return (temp / avg);
	}
	else
	{
		for (int i = 0; i < avg; i++)
		{
			temp += analogRead(SIG_pin_2);
		}
		return (temp / avg);
	}
	yield();
}