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
	column(17);
	column(18);
//	row(1);
//	row(8);
	//row(12);



	//for (int i = 0; i <= 13; i++)
	//{
	//	/*clearData();
	//	setRowData(0);
	//	setRowData(18);
	//	setRowData(16);*/
	//	setRowData(11);
	//	setRowData(10);
	//	setRowData(9);
	//	row(i);
	//	delay(500);
	//}
	//for (int x = 0; x < 13; x++)
	//{
	//	row(x);
	//	delay(500);
	//	/*elapsedMillis temp = 0;
	//	while (temp < 500)
	//	{

	//		for (int i = 0; i < PLUS; i++)
	//		{
	//			clearData();
	//			setRowData(i);
	//			drawRow(x);

	//		}
	//	}*/
	//}
	//for (int i = 0; i <= 19; i++)
	//{
	//	clearData();
	//	setRowData(i);
	//	{
	//		elapsedMillis temp = 0;
	//		while (temp < 100)
	//		{
	//		//	drawRow(10);
	//			drawRow(11);
	//			drawRow(12);
	//		}
	//	}
	//}
	//clearData();
	//setRowData(5);
	//drawRow(5);
	//number(22);
	//column(18);
	//	row(0);
	//clearData();
	//setRowData(0);
	//setRowData(3);
	//drawRow(9);
	//	drawRow(4);
	//	downToUp(0, 20);
	//for (int i = 0; i < 19; i++)
	//{
	//	//row(i, 100);
	//	column(i, 100);
	//}
	//for (int i = 0; i < 13; i++)
	//{
	//row(i, 100);
	//	//column(i, 100);
	//}
	//	leftToRight(0, 20);
	//leftToRight(0, 20);
	//upToDown(0, 20);
	//allOn(5000);
	//number(1);
	//number2(5, 1);
	//number2(2, 2);
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


	downToUp(0, 20);
	leftToRight(0, 20);
	rightToLeft(0, 20);
	for (int i = 0; i < 10; i++)
	{
	insideOn(100);
	outsideOn(100);
	}*/
}



