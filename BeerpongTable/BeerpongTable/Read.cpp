#pragma once
#include "Read.h"
#include <Arduino.h>

int areaP1 = 0;
int areaP2 = 0;

int cupP1[22]; //Cup 0 & 1 is area
int cupP2[22];

int currentCup = 0;
int currentPlayer = 1;

void readCups()
{
	if (currentCup == 0 || currentCup == 1 || areaP1 == 0 || areaP2 == 0) //calculating area.
	{
		calculateArea(currentPlayer);
	}
	if (currentCup > 1)
	{
		isCup(currentPlayer, currentCup);
		drawLedCups(currentPlayer);
	}

	currentCup++;
	if (currentCup > 12)
	{
		currentCup = 0;
		currentPlayer++;
		if (currentPlayer > 2)
		{
			currentPlayer = 1;
		}
	}
	//yield();
}

bool isCup(int player, int cup)
{
	if (cup == 0 || cup == 1) //0 & 1 is omgeving
	{
		return false;
	}
	int tempCupData = readCup(player, cup);
	if (player == 1)
	{
		Serial.println(areaP1 - tempCupData);
		if (areaP1 - tempCupData > 30)
		{
			setCup(1, cup - 2);
			return true;
		}
		else
		{
			disableCup(1, cup - 2);
			return false;
		}
	}
	else if (player == 2)
	{
		if (areaP2 - tempCupData > 50)
		{
			setCup(2, cup - 2);
			return true;
		}
		else
		{
			disableCup(2, cup - 2);
			return false;
		}
	}
	return false;
}

void calculateArea(int player)
{
	int area0 = readCup(player, 0);
	int area1 = readCup(player, 1);
	int area = (area0 + area1) / 2;
	if (player == 1)
	{
	//	Serial.print("Area: ");
	//	Serial.println(area);
		areaP1 = area;
	}
	else if (player == 2)
	{
		areaP2 = area;
	}

}

int readCup(int player, int cup)
{
	if (cup < 0 || cup > 112 || player < 1 || player > 2) //cup 0 & 1 is omgeving
	{
		return 0;
	}
	if (player == 1)
	{
		cupP1[cup] = 0;
	}
	else if (player == 2)
	{
		cupP2[cup] = 0;
	}

	int controlPin[] = { s0, s1, s2, s3 };

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

	//loop through the 4 sig
	for (int i = 0; i < 4; i++)
	{
		digitalWrite(controlPin[i], muxChannel[cup][i]);
	}

	if (player == 1)
	{
		//read the values 4 times
		for (int i = 0; i < 15; i++)
		{
			cupP1[cup] += analogRead(readPinP1);
			Serial.println(analogRead(readPinP1));
		}
		cupP1[cup] = cupP1[cup] / 15;  //avarage
		Serial.println(cupP1[cup]);
		return cupP1[cup];
	}
	else if (player == 2)
	{
		// read the values 4 times
		for (int i = 0; i < 15; i++)
		{
			cupP2[cup] += analogRead(readPinP2);
		}
		cupP2[cup] = cupP2[cup] / 15; //avarage
		return cupP2[cup];
	}
	return 0;

}
