#pragma once
#include "Read.h"
#include <Arduino.h>

void checkCups()
{
	int p = 2;
	{
		for (int i = 0; i < 10; i++)
		{
			Serial.println(readMux(p, 2) - ((readMux(p, 0) + readMux(p, 1)) / 2));
			if ((readMux(p, i + 2) - ((readMux(p, 0) + readMux(p, 1)) / 2)) < -90)
			{
				addCup(p, i);
			}
			else
			{
				removeCup(p, i);
			}
			drawLedCups(2);
		}
	}
}

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
	if (player == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			temp += analogRead(SIG_pin_1);
		}
		return (temp / 5);
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			temp += analogRead(SIG_pin_2);
		}
		return (temp / 5);
	}
	yield();
}