/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*
*/

//this code will display the values of ledData across a 4x4 led matrix
#include "elapsedMillis.h"
#include "visualisation.h"
//pin connections- the #define tag will replace all instances of "latchPin" in your code with A1 (and so on)


#define  latchPin 12 //A0
#define  clockPin 11 //A1
#define  dataPin  8// A2



visualisation visual;

void setup()
{
	//set pins as output
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
}

void loop()
{
	elapsedMillis tempTimer;
	while (tempTimer < 3000)
	{
		visual.setLedsInRow(4);
		visual.drawRow(2);
	}
	tempTimer = 0;
	while (tempTimer < 5000)
	{
		visual.allOn(); //TEST NIEUWE PROGRAMMERING 
	}
	/*int time = 20;
	visual.downToUp(time);
	visual.upToDown(time);
	visual.downToUp(time);
	visual.upToDown(time);
	visual.leftToRight(time);
	visual.rightToLeft(time);
	visual.leftToRight(time);
	visual.rightToLeft(time);

	for (int x = 0; x < 3; x++)
	{
	for (int i = -10; i < 18; i++)
	{
	visual.arrow(0, i, 0, time);
	}
	}

	visual.outsideOn(50);
	visual.insideOn(50);
	visual.outsideOn(50);
	visual.insideOn(50);
	visual.outsideOn(50);
	visual.insideOn(50);
	visual.outsideOn(50);
	visual.insideOn(50);

	for (int i = 0; i <= 10; i++)
	{
	elapsedMillis tempTimer;
	while (tempTimer < 1000)
	{
	visual.number(i);
	}
	}*/





}



