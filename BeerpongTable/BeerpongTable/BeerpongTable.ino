/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*/

#pragma once
#include "Animations.h"
#include <Scheduler.h>
#include "Read.h"
#include <stdio.h>
#include <string>


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
}
char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
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

int count = 3;

	void drawTablePlayerBlue() { //in loop
		char charArray2[] = "hoi";

	//bracketRight(1, 1, 50, 5000);
	//arrowLeft(1, 50, count * 50 * 18);
	//arrowUp(1, 50, count * 50 * 12);
	//for (int i = 0; i < 10; i++)
	//{
	//	insideOn(1, 50);
	//	outsideOn(1, 50);
	//}

	//smileyBoosToBlij(1, 200);
	ballAnimation(1, 50, 5000);
	diagonalLeftUpRight(1, 3, 29, 75, 10000);
	//text(1, charArray2, 1000);
}

void drawTablePlayerRed() { //in loop
	char charArray[] = "beerpong!";
	bracketLeft(2, 19, 50, 5000);
	arrowRight(2, 50, 1 * 50 * 18);
	arrowUp(2, 50, count * 50 * 12);

	for (int i = 0; i < 10; i++)
	{
		insideOn(2, 100);
		outsideOn(2, 100);
	}
	
	text(2, charArray, 1000);
	smileyBoosToBlij(2, 200);

	//text(2, charArray, 10000);
}

void drawLedCupsPlayerBlue() {//in loop

	//randomLedCups(1, 4, 200, 2000);
	for (int i = 0; i < 10; i++)
	{
		addCup(1, i);
	}
	drawLedCups(1);
	//checkCups(1);
}

void drawLedCupsPlayerRed() { //in loop
	/*for (int i = 0; i < 10; i++)
	{
		addCup(2, i);
	}
	drawLedCups(2);*/
	randomLedCups(2, 4, 200, 2000);

	//checkCups(2);

	
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

