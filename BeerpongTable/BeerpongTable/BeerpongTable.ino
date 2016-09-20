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

	calibrateSensors();
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
	yield(); //switch to other threads.
}


void drawTablePlayerBlue() { //in loop
	//allOn(blue, 1000);

		//char charArray2[] = "beerpong!";
	randomAnimations(blue);
	//bracketRight(blue, 20, 50, 5000);
	//bracketLeft(blue, 20, 50, 5000);
	//arrowLeft(blue, 50, count * 50 * 18);
	//arrowUp(blue, 50, count * 50 * 12);
	//for (int i = 0; i < 10; i++)
	//{
	//	insideOn(blue, 50);
	//	outsideOn(blue, 50);
	//}

	//smileyBoosToBlij(blue, 200);
	//ballAnimation(blue, 50, 5000);
	//diagonalRightUpToRight(blue, 3, 25, 75, 10000);
	//diagonalLeftUpToRight(blue, 3, 25, 75, 10000);
	//diagonalRightUpToLeft(blue, 3, 25, 75, 10000);
	//diagonalLeftUpToLeft(blue, 3, 25, 75, 10000);

	//text(blue, charArray2, 1000);
}

void drawTablePlayerRed() { //in loop


	/*char charArray[] = "0";
	sprintf(charArray, "%ld", 10-getScore(blue));
	text(red, charArray, 2000);*/

	/*showScoreFromPlayer(red, getScore(1), 2000);
	bracketLeft(red, 19, 50, 5000);
	arrowRight(red, 50, 1 * 50 * 18);
	arrowUp(red, 50, 9 * 50 * 12);

	showScoreFromPlayer(red, getScore(1), 2000);

	for (int i = 0; i < 10; i++)
	{
		insideOn(red, 100);
		outsideOn(red, 100);
	}
	for (int i = 0; i < 5; i++)
	{
		circleOutIn(red, 50);
		circleInOut(red, 50);
	}*/
	randomAnimations(red);

}

void drawLedCupsPlayerBlue() {//in loop
	//yield();
	//checkCups(blue);
	//triangle(blue, 400, 2000);
	//fourToOne(blue, 200, 5000);
	//rallandomCups(blue, 4, 400, 3000);
	//oneToFour(blue, 200, 5000);
	allCupsOn(blue, 1000);
}

void drawLedCupsPlayerRed() { //in loop

	checkCups(red);

	//drawLedScore(red, 5000);
	/*
	randomCups(red, 4, 400, 2000);
	triangle(red, 400, 2000);
	fourToOne(red, 200, 5000);
	drawLedScore(red, 5000);
	randomCups(red, 4, 400, 3000);
	oneToFour(red, 200, 5000);
	*/
	//allCupsOn(red, 1000);


}

void randomAnimations(int player)
{
	int numberOfAnimation =  random(0, 20);

	switch (numberOfAnimation)
	{
	case 0:
		diagonalRightUpToRight(player, random(1, 4), 25, 75, random(5000, 10000));
		break;
	case 1:
		diagonalLeftUpToRight(player, random(1, 4), 25, 75, random(5000, 10000));
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
			showScoreFromPlayer(1, getScore(2), random(2000, 8000));
		}
		else
		{
			showScoreFromPlayer(2, getScore(1), random(2000, 8000));
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
		text(player, "beerpong", 100);
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
		logo(player, random(2000, 75000));
		break;
	case 19:
		pacMan(player, 50, random(2000, 10000));
		break;
	case 20:

		break;
	case 21:
		break;


	default:
		text(player, "beerpong", 100);



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

