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


#define latchPin  A0
#define clockPin A1
#define dataPin  A2


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
	int time = 100;
	visual.downToUp(time);
	visual.upToDown(time);
	visual.downToUp(time);
	visual.upToDown(time);
	visual.downToUp(time);
	visual.upToDown(time);
	visual.leftToRight(time);
	visual.rightToLeft(time);
	visual.leftToRight(time);
	visual.rightToLeft(time);
	visual.leftToRight(time);
	visual.rightToLeft(time);

	visual.outsideOn(time);
	visual.insideOn(time);
	visual.outsideOn(time);
	visual.insideOn(time);
	visual.outsideOn(time);
	visual.insideOn(time);

	for (int i = 10; i > 0; i--)
	{
		visual.showScore(i, 200);
	}

	//elapsedMillis tempTimer;
	//tempTimer = 0;
	//while (tempTimer < 500)
	//{
	//	for (int i = 128; i > 1; i = i / 2)
	//	{
	//		digitalWrite(latchPin, LOW);
	//		// shift out the bits of dataToSend to the 74HC595
	//		shiftOut(dataPin, clockPin, LSBFIRST, ~255);
	//		shiftOut(dataPin, clockPin, LSBFIRST, ~255);

	//		shiftOut(dataPin, clockPin, LSBFIRST, i);
	//		shiftOut(dataPin, clockPin, LSBFIRST, i);
	//		shiftOut(dataPin, clockPin, LSBFIRST, i);
	//		digitalWrite(latchPin, HIGH);
	//		delay(100);
	//	}
	//}

	//tempTimer = 0;
	//while (tempTimer < 500)
	//{
	//	for (int i = 128; i > 1; i = i / 2)
	//	{
	//		digitalWrite(latchPin, LOW);
	//		// shift out the bits of dataToSend to the 74HC595
	//		shiftOut(dataPin, clockPin, LSBFIRST, ~i);
	//		shiftOut(dataPin, clockPin, LSBFIRST, ~i);

	//		shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//		shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//		shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//		digitalWrite(latchPin, HIGH);
	//		delay(100);
	//	}
	//}

}



