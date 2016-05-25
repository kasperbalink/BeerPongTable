/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*
*/

//this code will display the values of ledData across a 4x4 led matrix
#pragma once
#include "Animations.h"
#include <Scheduler.h>
#include "Read.h"


long rowDataArray[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void setup()
{

	Serial.begin(9600);
	//set pins as output
	pinMode(13, OUTPUT);
	pinMode(latchPin_P1, OUTPUT);
	pinMode(clockPin_P1, OUTPUT);
	pinMode(dataPin_P1, OUTPUT);
	pinMode(latchPin_P2, OUTPUT);
	pinMode(clockPin_P2, OUTPUT);
	pinMode(dataPin_P2, OUTPUT);


	//rowDataArray = ;
	// rowData = new List<long>();
	for (int i = 0; i < 13; i++)
	{
		rowDataArray[i] = 0;
	}

	//start threads 2 en 3
	//Scheduler.startLoop(loop2);
	//Scheduler.startLoop(loop3);

}
char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
int data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

int player = 3;

int cup = 2;
void loop()
{
	readCup(1, 0);

	


	//for (int i = 0; i < 10; i++)
	//{
	//	disableCup(1, i);
	//}
	//setCup(1, 1);
	//drawLedCups(1);
	//Serial.println("start");
	//calculateArea(1);
	//readCup(1, 4);
	//drawLedCups(1);
	//4, 5
	//calculateArea(1);
	////readCups();
	//for (int i = 2; i <= 12; i++)
	//{
	//	isCup(1, 5);
	//	delay(100);
	//	calculateArea(1);
	//	delay(100);
	//}
	//drawLedCups(1);
	//readCup(1, 7);
	//drawLedCups(1);

	
	
	//readCups();

	//letter(1, 'b', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'e', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'e', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'r', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'p', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'o', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'n', 0, 0, 200);
	//allOff(1, 200);
	//letter(1, 'g', 0, 0, 200);
	//allOff(1, 400);
	//smileyBlij(1, 400);

}
void loop2() {
	for (int i = 0; i < 5; i++)
	{
		leftToRight(2, 1, 50);
		rightToLeft(2, 1, 50);
		upToDown(2, 1, 50);
		downToUp(2, 1, 50);
	}
	//logo(2);
	int SPEED = 50;
	for (int x = 0; x < 5; x++)
	{
		for (int i = 0; i < 6; i++)
		{
			square_(2, i, SPEED);
		}
		for (int i = 6; i > 0; i--)
		{
			square_(2, i, SPEED);
		}
	}
	for (int x = 0; x < 10; x++)
	{
		insideOn(2, 50);
		outsideOn(2, 50);
	}
	smileyBoosToBlij(2, 200);

}
void loop3()
{
	readCups();
	delay(200); //switch naar andere threads.
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
		delay(1000);
	}
}

