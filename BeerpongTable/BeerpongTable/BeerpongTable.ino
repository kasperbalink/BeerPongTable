/*
*	Title: Beerpong Table
*	Author: Kasper Balink
*	Date: 08-July-2015
*
*/

//this code will display the values of ledData across a 4x4 led matrix
#pragma once
#include "Animations.h"




void setup()
{
	//Serial.begin(9600);
	//set pins as output
	pinMode(latchPin_P1, OUTPUT);
	pinMode(clockPin_P1, OUTPUT);
	pinMode(dataPin_P1, OUTPUT);
	pinMode(latchPin_P2, OUTPUT);
	pinMode(clockPin_P2, OUTPUT);
	pinMode(dataPin_P2, OUTPUT);


}
char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
int data[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

void loop()
{
	


	//letter('a', 0, 0);
	
//	text("kasper en tim", 100);
	/*textOffThree('a', 'b', 'c', 800);
	textOffTwo('a', 'b', 800);*/
	//smileyBoosToBlij(500);

}



