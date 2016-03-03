/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*
*/

//this code will display the values of ledData across a 4x4 led matrix
#pragma once
#include "Animations.h"


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

long dataReceived;
int rowReceived;
int playerReceived;

long rowDataArray[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
long player1Cups = 0;
long player2Cups = 0;

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


	inputString.reserve(200);

	//rowDataArray = ;
	// rowData = new List<long>();
	for (int i = 0; i < 13; i++)
	{
		rowDataArray[i] = 0;
	}

}
char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
int data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

void loop()
{
	if (stringComplete) {
		String tempData;
		String tempRow;
		String tempPlayer;
		Serial.println(inputString);
		tempData = inputString.substring(0, 22); //length of 22
		char charArray[256];
		tempData.toCharArray(charArray, 256);
		dataReceived = atol(charArray);
		Serial.println(dataReceived);

		tempRow = inputString.substring(23, 25); //length of 2
		rowReceived = tempRow.toInt();
		Serial.println(rowReceived);
		tempPlayer = inputString.substring(26, 27); //length of 1
		playerReceived = tempPlayer.toInt();
		Serial.println(playerReceived);
		// clear the string:
		inputString = "";
		stringComplete = false;
	}

	////////EXAMPLE FOR RECEIVED DATA VIA COM///////
	/*if (rowDataArray[5] == 1025)
	{
		digitalWrite(13, HIGH);
	}
	else
	{
		digitalWrite(13, LOW);
	}*/

	//for (int i = 0; i < 13; i++) //drawing data received from COM in loop.
	//{setRealRowData(rowDataArray[i]);
	//	drawRow(i);
	//}
	/////////////END OF EXAMPLE///////////
	smileyBlijToBoos(250);
	smileyNeutraal(250);
	smileyBlij(500);
	for (int x = 0; x < 5; x++)
	{
		for (int i = 0; i < 7; i++)
		{
			square_(i, 50);
		}
		for (int i = 7; i >= 0; i--)
		{
			square_(i, 50);
		}
	}
	for (int z = 0; z < 5; z++)
	{
		outsideOn(50);
		insideOn(50);
	}
	logo(2000);
	//drawRow(rowIncomingData, playerIncomingData); //als players zijn geimplementeerd.

	//test();
	//row(0);
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


void serialEvent() {
	while (Serial.available()) 
	{
		// get the new byte:
		char inChar = (char)Serial.read();
		// add it to the inputString:
		inputString += inChar;
		// if the incoming character is a newline, set a flag
		// so the main loop can do something about it:
		if (inChar == '\n' || inChar == ';') {
			stringComplete = true;
		}


	}
}

