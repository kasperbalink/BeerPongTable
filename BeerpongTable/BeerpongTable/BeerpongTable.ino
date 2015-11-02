/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*
*/

//this code will display the values of ledData across a 4x4 led matrix
#pragma once
#include "Animations.h"
//pin connections- the #define tag will replace all instances of "latchPin_P1" in your code with A1 (and so on)


void setup()
{
	//set pins as output
	pinMode(latchPin_P1, OUTPUT);
	pinMode(clockPin_P1, OUTPUT);
	pinMode(dataPin_P1, OUTPUT);
	pinMode(latchPin_P2, OUTPUT);
	pinMode(clockPin_P2, OUTPUT);
	pinMode(dataPin_P2, OUTPUT);
}

void loop()
{
	number2(5, 1);
	number2(2, 2);
	/*movingArrow(0, 0, 0, 100);
	for (int x = 0; x < 5; x++)
	{

		for (int i = 0; i <= 6; i++)
		{
			square_(0, 50);
		}
		for (int i = 6; i >= 0; i--)
		{
			square_(i, 50);
		}
	}
	
	upToDown(0, 20);
	downToUp(0, 20);
	leftToRight(0, 20);
	rightToLeft(0, 20);
	for (int i = 0; i < 10; i++)
	{
		insideOn(100);
		outsideOn(100);
	}*/
}



