#pragma once
#include "Read.h"
#include "elapsedMillis.h"
#include <Arduino.h>

int cupsOnP1[10] = { 0,0,0,0,0,0,0,0,0,0 };
int cupsOnP2[10] = { 0,0,0,0,0,0,0,0,0,0 };

int sensorValueP1[10] = { -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000 };
int sensorValueP2[10] = { -1000 ,-1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000 };

int sensorTimersOnP1[10] = { 0,0,0,0,0,0,0,0,0,0 };
int sensorTimersOffP1[10] = { 0,0,0,0,0,0,0,0,0,0 };

int sensorTimersOnP2[10] = { 0,0,0,0,0,0,0,0,0,0 };
int sensorTimersOffP2[10] = { 0,0,0,0,0,0,0,0,0,0 };

bool isCalibrated_ = false;

int oldCountP1 = 0;
int oldCountP2 = 0;

bool scoredP1 = false;
bool scoredP2 = false;


/*Deze methode berekent de infrarood waarde van alle sensoren zonder beker.*/
void calibrateSensors()
{
	for (int i = 0; i < 10; i++)
	{
		int avg = 150;
		int valueP1 = 0;
		int valueP2 = 0;
		for (int count = 0; count < avg; count++)
		{
			valueP1 += (readMux(1, i + 2) - ((readMux(1, 0) + readMux(1, 1)) / 2));
			valueP2 += (readMux(2, i + 2) - ((readMux(2, 0) + readMux(2, 1)) / 2));
		}

		sensorValueP1[i] = valueP1 / avg;
		sensorValueP2[i] = valueP2 / avg;
		valueP1 = 0;
		valueP2 = 0;
	}
	isCalibrated_ = true;
}

bool isCalibrated()
{
	return isCalibrated_;
}

/*Deze methode berekent of er een beker op staat. Voor speler 1 of speler 2: Standaard waarde - 4.*/
void checkCups(int player)
{
	if (player == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			addRemoveCup(player, i, sensorValueP1[i] - 3);
		}
	}
	else if (player == 2)
	{
		for (int i = 0; i < 10; i++)
		{
			addRemoveCup(player, i, sensorValueP2[i] - 3); //4 is verschil
		}
	}
	yield();
}

/*Deze methode zet in een array of de beker aan of uit staat
int value = verschil in standaard waarde*/
void addRemoveCup(int player, int cup, int value)
{
	int avg = 0;
	int count = 5;
	for (int i = 0; i < count; i++)
	{
		avg += readMux(player, cup + 2) - ((readMux(player, 0) + readMux(player, 1)) / 2);
	}
	if (avg / count <= value)
	{
		if (player == 1)
		{
			if (cup == 8)
			{
				Serial.println(avg / count);
			}
			sensorTimersOnP1[cup] += 1;
			if (sensorTimersOnP1[cup] > 70) //50
			{
				cupsOnP1[cup] = 1;
				sensorTimersOffP1[cup] = 0;
			}
		}
		else
		{

			sensorTimersOnP2[cup] += 1;
			if (sensorTimersOnP2[cup] > 70)
			{
				cupsOnP2[cup] = 1;
				sensorTimersOffP2[cup] = 0;
			}
		}
	}
	else
	{
		if (player == 1)
		{
			if (cup == 8)
			{
				Serial.println(avg / count);
			}
			sensorTimersOffP1[cup] += 1;
			if (sensorTimersOffP1[cup] > 15)
			{
				cupsOnP1[cup] = 0;
				sensorTimersOnP1[cup] = 0;
			}
		}
		else
		{
			sensorTimersOffP2[cup] += 1;
			if (sensorTimersOffP2[cup] > 15)
			{
				cupsOnP2[cup] = 0;
				sensorTimersOnP2[cup] = 0;
			}
		}
	}
	yield();

}

/*Deze methode zet de leds aan als er een beker staat*/
void showStandingCups(int player, int totalTime)
{
	checkCups(player);
	elapsedMillis timer;
	while (timer < totalTime)
	{
		checkCups(player);
		for (int i = 0; i < 10; i++)
		{
			if (player == 1)
			{
				if (cupsOnP1[i] == 1)
				{
					addCup(player, i);
				}
				else
				{
					removeCup(player, i);
				}
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

void blinkStandingCups(int player, int onTime, int offTime, int totalTime)
{
	checkCups(player);
	elapsedMillis timer;
	while (timer < totalTime)
	{
		checkCups(player);
		for (int i = 0; i < 10; i++)
		{
			if (player == 1)
			{
				if (cupsOnP1[i] == 1)
				{
					addCup(player, i);
				}
				else
				{
					removeCup(player, i);
				}
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
		elapsedMillis onTimer = 0;
		while (onTimer < onTime) {
			drawLedCups(player);
		}
		elapsedMillis offTimer = 0;
		while (offTimer < offTime) {
			allCupsOff(player);
		}

	}
}


/*returnt de aantal cups van gegeven speler.*/
int getCups(int player)
{
	checkCups(player);
	int score = 0;
	int scoreCount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (player == 1)
		{
			scoreCount += cupsOnP1[i];
		}
		else if (player == 2)
		{
			scoreCount += cupsOnP2[i];
		}
	}
	if (player == 1)
	{
		if (scoreCount != oldCountP1 && scoreCount < oldCountP1) //added <
		{
			scoredP1 = true;
			oldCountP1 = scoreCount;
		}
	}
	else if (player == 2)
	{
		if (scoreCount != oldCountP2 && scoreCount < oldCountP2) // added <
		{
			scoredP2 = true;
			oldCountP2 = scoreCount;
		}
	}
	return scoreCount;
}

bool isScored()
{
	if (scoredP1 || scoredP2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void setScored()
{
	scoredP1 = false;
	scoredP2 = false;
}


//int* getScoreArray(int player)
//{
//	if (player == 1)
//	{
//		return cupsOnP1;
//	}
//	else if (player == 2)
//	{
//		return cupsOnP2;
//	}
//}

//info voor de multiplexer
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


/*Deze methode wordt gebruikt om de sensoren uit te lezen*/
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


/*Deze methode berekent of er een beker op staat. Voor speler 1 of speler 2: Standaard waarde - 4.*/
void checkCupsNoYield(int player)
{
	if (player == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			addRemoveCupNoYield(player, i, sensorValueP1[i] - 4); //4 is verschil
		}
	}
	else if (player == 2)
	{
		for (int i = 0; i < 10; i++)
		{
			addRemoveCupNoYield(player, i, sensorValueP2[i] - 4); //4 is verschil
		}
	}
}

/*Zet de leds onder de cup aan als er een beker staat voor de gegeven speler*/
void drawLedScoreNoYield(int player)
{
	for (int i = 0; i < 10; i++)
	{
		if (player == 1)
		{
			if (cupsOnP1[i] == 1)
			{
				addCup(player, i);
			}
			else
			{
				removeCup(player, i);
			}
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
		drawLedCupsNoYield(player);
	}
}

/*Deze methode zet in een array of de beker aan of uit staat
int value = verschil in standaard waarde*/
void addRemoveCupNoYield(int player, int cup, int value)
{
	int avg = 0;
	int count = 5;
	for (int i = 0; i < count; i++)
	{
		avg += readMuxNoYield(player, cup + 2) - ((readMuxNoYield(player, 0) + readMuxNoYield(player, 1)) / 2);
	}
	if (avg / count <= value)
	{
		if (player == 1)
		{
			sensorTimersOnP1[cup] += 1;
			if (sensorTimersOnP1[cup] > 20)
			{
				cupsOnP1[cup] = 1;
				sensorTimersOffP1[cup] = 0;
			}
		}
		else
		{
			sensorTimersOnP2[cup] += 1;
			if (sensorTimersOnP2[cup] > 20)
			{
				cupsOnP2[cup] = 1;
				sensorTimersOffP2[cup] = 0;
			}
		}
	}
	else
	{
		if (player == 1)
		{
			sensorTimersOffP1[cup] += 1;
			if (sensorTimersOffP1[cup] > 30)
			{
				cupsOnP1[cup] = 0;
				sensorTimersOnP1[cup] = 0;
			}
		}
		else
		{
			sensorTimersOffP2[cup] += 1;
			if (sensorTimersOffP2[cup] > 30)
			{
				cupsOnP2[cup] = 0;
				sensorTimersOnP2[cup] = 0;
			}
		}
	}
}

/*returnt de score van gegeven speler, ZONDER YIELD().*/
int getCupsNoYield(int player)
{
	int score = 0;
	int scoreCount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (player == 1)
		{
			scoreCount += cupsOnP1[i];
		}
		else if (player == 2)
		{
			scoreCount += cupsOnP2[i];
		}
	}
	return scoreCount;
}

int readMuxNoYield(int player, int channel) {

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
}