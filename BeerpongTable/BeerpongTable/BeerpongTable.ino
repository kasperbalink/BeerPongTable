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
#include <time.h>



#define blue 1
#define red 2

static bool SHOW_COUNT_AT_SCORE = true;
static bool SHOW_COUNT_AT_STARTUP = true;

long rowDataArray[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
bool firsttime;

int startLedRed;
int startLedBlue;
int startCupRed;
int startCupBlue;


int currentScoreBlue = 0;
int currentScoreRed = 0;

bool endGame = false;

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
	randomSeed(analogRead(A2));

	if (startLedBlue && startLedRed && startCupBlue && startCupRed)
	{
		checkCups(red);
		checkCups(blue);
		//show score when value of cups changed.
		while (isScored() && startLedBlue && startLedRed && startCupBlue && startCupRed && SHOW_COUNT_AT_SCORE)
		{
			elapsedMillis scoreTimer = 0;
			while (scoreTimer < 5000)
			{
				checkCupsNoYield(blue);
				checkCupsNoYield(red);
				int cupsBlue = getCupsNoYield(blue);
				int cupsRed = getCupsNoYield(red);
				if (cupsBlue == 0)
				{
					endGame = true;
					showScoreFromPlayerNoYield(red, cupsBlue);
				}
				else if (cupsRed == 0)
				{
					endGame = true;
					showScoreFromPlayerNoYield(blue, cupsRed);
				}
				else
				{
					showScoreFromPlayerNoYield(blue, cupsRed);
					showScoreFromPlayerNoYield(red, cupsBlue);
				}
				drawLedScoreNoYield(red);
				drawLedScoreNoYield(blue);
			}
			setScored();
		}
	}

	if (firsttime)
	{
		calibrateSensors();
		firsttime = false;
	}
	if (isCalibrated() && SHOW_COUNT_AT_STARTUP)
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
	else if (isCalibrated() && !SHOW_COUNT_AT_STARTUP && (!startLedRed || !startLedBlue || !startCupBlue || !startCupRed)) {
		getCups(blue);
		getCups(red);
		startLedBlue = true;
		startLedRed = true;
		startCupBlue = true;
		startCupRed = true;
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
}

void drawLedCupsPlayerBlue() {//in loop
	if (startCupBlue && startLedBlue)
	{
		randomCupAnimation(blue);
	}
	else
	{
		allCupsOn(blue, 1000);
	}
}

void drawLedCupsPlayerRed() { //in loop

	if (startCupRed && startLedRed)
	{
		randomCupAnimation(red);
	}
	else
	{
		allCupsOn(red, 1000);
	}


}

void randomCupAnimation(int player)
{
	//min is included, max is exclusive
	int numberOfAnimation = endGame ? 10 : random(0, 6);
	
	switch (numberOfAnimation)
	{
	case 0:
		triangle(player, random(100, 300), random(1000, 5000));
		break;
	case 1:
		fourToOne(player, random(100, 300), random(1000, 7000));
		break;
	case 2:
		showStandingCups(player, random(4000, 15000));
		break;
	case 3:
		int onTime;
		onTime = random(200, 1000);
		blinkStandingCups(player, onTime, random(100, onTime), random(4000, 15000));
		break;
	case 4:
		randomCups(player, random(1, 5), random(100, 300), random(500, 5000));
		break; 
	case 5:
		oneToFour(player, random(100, 300), random(1000, 5000));
		break;
	case 10: //endgame
		SHOW_COUNT_AT_SCORE = false;
		allCupsOff(player);
		break;
	}
}

void randomAnimations(int player)
{
	//min is included, max is exclusive
	
	int numberOfAnimation = endGame ? 100 : random(0, 53);

	switch (numberOfAnimation)
	{
	case 0:
		diagonalRightUpToRight(player, random(1, 5), 25, 75, random(5000, 10000));
		break;
	case 1:
		diagonalLeftUpToRight(player, random(1, 5), 25, 75, random(5000, 10000));
		break;
	case 2:
		diagonalRightUpToLeft(player, random(1, 5), 25, 75, random(5000, 10000));
		break;
	case 3:
		diagonalLeftUpToLeft(player, random(1, 5), 25, 75, random(5000, 10000));
		break;
	case 4:
		ballAnimation(player, random(30, 80), random(5000, 10000));
		break;
	case 5:
	{
		int totalTime = random(2000, 10000);
		if (player == 1)
		{
			elapsedMillis timer;
			while (timer < totalTime)
			{
				showScoreFromPlayer(blue, getCups(red), 10);
			}

		}

		else
		{
			elapsedMillis timer;
			while (timer < totalTime)
			{
				showScoreFromPlayer(red, getCups(blue), 10);
			}
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
		circleInOut(player, random(25, 100), random(2000, 10000));
		break;
	case 15:
		circleInOutFilled(player, random(25, 100), random(2000, 10000));
		break;
	case 16:
		circleOutIn(player, random(25, 100), random(2000, 10000));
		break;
	case 17:
		circleOutInFilled(player, random(25, 100), random(2000, 10000));
		break;
	case 18:
		logo2(player, random(2000, 4000));
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
		break;
	case 23:
		thumb(player, 5000);
		break;
	case 24:
		thumbDown(player, 5000);
		break;
	case 25:
		leftToRight(player, random(1, 5), random(100, 400), random(2000, 5000));
		break;
	case 26:
		rightToLeft(player, random(1, 5), random(100, 400), random(2000, 5000));
		break;
	case 27:
		upToDown(player, random(1, 4), random(100, 400), random(2000, 5000));
		break;
	case 28:
		downToUp(player, random(1, 4), random(100, 400), random(2000, 5000));
		break;
	case 29:
		randomRows(player, random(1, 4), random(100, 400), random(2000, 5000));
		break;
	case 30:
		randomColumn(player, random(1, 7), random(100, 400), random(2000, 5000));
		break;
	case 31:
		randomLines(player, random(1, 7), random(1, 5), random(100, 400), random(2000, 5000));
		break;
	case 32:
		smiley(player, 5, random(2000, 5000));
		break;
	case 33:
		squareInOut(player, random(80, 200), random(2000, 5000));
		break;
	case 34:
		squareOutIn(player, random(80, 200), random(2000, 5000));
		break;
	case 35:
		randomLeds(player, random(50, 200), random(2000, 5000));
		break;
	case 36:
		heart(player, 1, random(2000, 5000));
		break;
	case 37:
		heartInToOut(player, random(80, 200), random(2000, 5000));
		break;
	case 38:
		heartOutToIn(player, random(80, 200), random(2000, 5000));
		break;
	case 39:
		heartFilled(player, random(2000, 5000));
		break;
	case 40:
		smiley(player, 1, random(2000, 5000));
		break;
	case 41:
		smiley(player, 2, random(2000, 5000));
		break;
	case 42:
		smiley(player, 3, random(2000, 5000));
		break;
	case 43:
		smiley(player, 4, random(2000, 5000));
		break;
	case 44:
		text(player, "#fissa", random(200, 2000));
		break;
	case 45:
		textByChar(player, "#bier", random(200, 300));
		break;
	case 46:
		text(player, "#party", random(200, 2000));
		break;
	case 47:
		text(player, "hiep hiep hoera", random(200, 2000));
		break;
	case 48:
		text(player, "gefeliciteerd!", random(200, 2000));
		break;
	case 49:
		textByChar(player, "gefeliciteerd", random(200, 300));
		break;
	case 50:
		text(player, "team red", random(200, 300));
		break;
	case 51:
		text(player, "team blue", random(200, 300));
		break;
	case 52:
		text(player, "britta!", random(200, 300));
		break;
	case 53:
		textByChar(player, "britta", random(200, 300));
		break;
	case 100:
		if (player == 1) {
			text(player, "new game?", 10000);
		}
		else {
			text(player, "reboot!   ", 10000);
		}
		break;


	default:
		if (player == 1)
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(blue, getCups(red), 10);
			}
		}
		else
		{
			elapsedMillis timer;
			while (timer < 10000)
			{
				showScoreFromPlayer(red, getCups(blue), 10);
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

