/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*/

#pragma once
#include "Animations.h"
#include "CupAnimations.h"
#include <Scheduler.h>
#include "Read.h"
#include <stdio.h>
#include <string>


#define blue 1
#define red 2

long rowDataArray[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool firsttime;

int startLedRed;
int startLedBlue;
int startCupRed;
int startCupBlue;


bool showScore;


void setup()
{

	Serial.begin(9600);
	//set pins as output
	pinMode(latchPin_P1, OUTPUT);
	pinMode(clockPin_P1, OUTPUT);
	pinMode(dataPin_P1, OUTPUT);

	pinMode(dataPinCup_P1, OUTPUT);
	pinMode(clockPinCup_P1, OUTPUT);
	pinMode(latchPinCup_P1, OUTPUT);

	pinMode(latchPin_P2, OUTPUT);
	pinMode(clockPin_P2, OUTPUT);
	pinMode(dataPin_P2, OUTPUT);

	pinMode(dataPinCup_P2, OUTPUT);
	pinMode(clockPinCup_P2, OUTPUT);
	pinMode(latchPinCup_P2, OUTPUT);

	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);

	pinMode(A0, INPUT);
	pinMode(A1, INPUT);

	//start threads
	Scheduler.startLoop(drawTablePlayerBlue);
	Scheduler.startLoop(drawTablePlayerRed);
	Scheduler.startLoop(drawLedCupsPlayerBlue);
	Scheduler.startLoop(drawLedCupsPlayerRed);

	firsttime = true;

	startCupBlue = false;
	startCupRed = false;
	startLedBlue = false;
	startLedRed = false;

	showScore = false;

	//logo(red);
	//logo(blue);
	delay(1000);
}
int data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };


/*
PIN CONFIGURATION:
BLUE SIDE:
Data: 22
Clock:24
Latch: 26

Data Cups: 28
Clock Cups: 30
Latch Cups: 32

AnalogRead A0

RED SIDE:
Data: 23
Clock:25
Latch: 27

Data Cups: 29
Clock Cups: 31
Latch Cups: 33

AnalogRead A1

S0: 36
S1: 38
S2: 40
S3: 42

*/
void loop()
{
	if (firsttime)
	{
		calibrateSensors();
		firsttime = false;
	}
	if (isCalibrated())
	{
		if (getCups(blue) == 10)
		{
			startLedBlue = true;
		}
		if (getCups(red) == 10)
		{
			startLedRed = true;
		}
		if (startLedBlue == true && startLedRed == true)
		{
			startCupBlue = true;
			startCupRed = true;
		}
		if (startLedRed && !startCupRed && getCups(red) != 10)
		{
			startLedRed = false;
		}
		if (startLedBlue && !startCupBlue && getCups(blue) != 10)
		{
			startLedBlue = false;
		}
	}

	yield(); //switch to other threads.
}


void drawTablePlayerBlue() { //in loop
	if (startLedBlue && startCupBlue)
	{
			randomAnimations(blue);
	}
	else if (startLedBlue && !startCupBlue)
	{
		text(blue, "go!", 1000);
	}
	else
	{
		startUpText(blue, getCups(blue));
	}
	
}

void drawTablePlayerRed() { //in loop

	if (startLedRed && startCupRed)
	{	
		randomAnimations(red);
	}
	else if (startLedRed && !startCupRed)
	{
		text(red, "go!", 1000);
	}
	else
	{
		startUpText(red, getCups(red));
	}


	//randomLeds(red, 200, 10000);

}

void drawLedCupsPlayerBlue() {//in loop
	if (startCupBlue && startLedBlue)
	{
		triangle(blue, random(100, 300), random(1000, 5000));
		fourToOne(blue, random(100, 300), random(1000, 7000));
		drawLedScore(blue, 5000);
		randomCups(blue, random(1, 5), random(100, 300), random(500, 5000));
		oneToFour(blue, random(100, 300), random(1000, 5000));
	}
	else
	{
		allCupsOn(blue, 1000);
	}
}

void drawLedCupsPlayerRed() { //in loop

	if (startCupRed && startLedRed)
	{
		triangle(red, random(100, 300), random(1000, 5000));
		fourToOne(red, random(100, 300), random(1000, 7000));
		drawLedScore(red, 5000);
		randomCups(red, random(1, 5), random(100, 300), random(500, 5000));
		oneToFour(red, random(100, 300), random(1000, 5000));
	}
	else
	{
		allCupsOn(red, 1000);
	}


}

void randomAnimations(int player)
{
	int numberOfAnimation = random(0, 26);

	switch (numberOfAnimation)
	{
	case 0:
		diagonalRightUpToRight(player, random(1, 4), 25, 75, random(5000, 10000));
		break;
	case 1:
		break;
	case 2:
		diagonalRightUpToLeft(player, random(1, 4), 25, 75, random(5000, 10000));
		break;
	case 3:
		diagonalLeftUpToLeft(player, random(1, 4), 25, 75, random(5000, 10000));
		break;
	case 4:
		ballAnimation(player, random(30, 80), random(5000, 10000));
		break;
	case 5:
		if (player == 1)
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(1, getCups(2), 10);
			}
		
		}
		else
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(2, getCups(1), 10);
			}
		}
		break;
	case 6:
		bracketLeft(player, 19, random(30, 100), random(2000, 10000));
		break;
	case 7:
		bracketRight(player, 19, random(30, 100), random(2000, 10000));
		break;
	case 8:
		arrowDown(player, random(30, 100), random(2000, 10000));
		break;
	case 9:
		arrowUp(player, random(30, 100), random(2000, 10000));
		break;
	case 10:
		arrowLeft(player, random(30, 100), random(2000, 10000));
		break;
	case 11:
		arrowRight(player, random(30, 100), random(2000, 10000));
		break;
	case 12:
		for (int i = 0; i < random(5, 15); i++)
		{
			insideOn(player, 50);
			outsideOn(player, 50);
		}
		break;
	case 13:
		text(player, "beerpong!", 100);
		break;
	case 14:
		circleInOut(player, random(10, 100), random(2000, 10000));
		break;
	case 15:
		circleInOutFilled(player, random(10, 100), random(2000, 10000));
		break;
	case 16:
		circleOutIn(player, random(10, 100), random(2000, 10000));
		break;
	case 17:
		circleOutInFilled(player, random(10, 100), random(2000, 10000));
		break;
	case 18:
		logo(player, random(2000, 7500));
		break;
	case 19:
		pacMan(player, 50, random(2000, 10000));
		break;
	case 20:
		smileyBlijToBoos(player, random(100, 400), random(1000, 5000));
		break;
	case 21:
		smileyBoosToBlij(player, random(100, 400), random(1000, 5000));
		break;
	case 22:
		textByChar(player, "beerpong", 200);
		//leftToRight(player, random(1, 5), random(50, 200));
		break;
	case 23:
		thumb(player, 5000);
		break;
	case 24:
		thumbDown(player, 5000);
		break;
	case 25:
		break;
	case 26:
		break;

	default:
		if (player == 1)
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(1, getCups(2), 10);
			}

		}
		else
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(2, getCups(1), 10);
			}
		}
		break;



	}
}

void test()
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(latchPin_P1, LOW);

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, data[i]); //min 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, data[i]); //min 8 t/m 12

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, data[i]); //plus 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, data[i]); //plus 8 t/m 15
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, data[i]); //plus 16 t/m 18

		digitalWrite(latchPin_P1, HIGH);

		digitalWrite(latchPin_P2, LOW);

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, data[i]); //min 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, data[i]); //min 8 t/m 12

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, data[i]); //plus 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, data[i]); //plus 8 t/m 15
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, data[i]); //plus 16 t/m 18

		digitalWrite(latchPin_P2, HIGH);
		delay(1000);
	}
}

