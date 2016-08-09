#pragma once
#include "Read.h"
#include "elapsedMillis.h"
#include <Arduino.h>



void checkCups(int player)
{
	if (player == 2)
	{
		Serial.println(readMux(player, 2 + 1) - ((readMux(player, 0) + readMux(player, 1)) / 2));
	}
		for (int i = 0; i < 10; i++)
		{
			switch (i)
			{
			case 0:
				addRemoveCup(1, i, -82);
				addRemoveCup(2, i, -110);
				break;
			case 1:
				break;
			case 2:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8: 
				break;
			case 9:
				break;
			case 10:
				break;
			}
			/*if ((readMux(player, i + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2)) <= -20| (readMux(player, i + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2)) >= 200)
			{
				addCup(player, i);
			}
			else
			{
				removeCup(player, i);
			}*/
			drawLedCups(player);
		}
}

void addRemoveCup(int player, int cup, int value)
{
	if ((readMux(player, cup + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2)) <= value | (readMux(player, cup + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2)) >= 200)
	{
		addCup(player, cup);
	}
	else
	{
		removeCup(player, cup);
	}
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