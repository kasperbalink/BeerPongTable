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

	visual.outsideOn(100);
	visual.insideOn(100);
	//digitalWrite(latchPin, LOW);
	//	// shift out the bits of dataToSend to the 74HC595
	//	shiftOut(dataPin, clockPin, LSBFIRST, ~255);
	//	shiftOut(dataPin, clockPin, LSBFIRST, ~255);

	//	shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//	shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//	shiftOut(dataPin, clockPin, LSBFIRST, 255);
	//	digitalWrite(latchPin, HIGH);
	elapsedMillis tempTimer;
	tempTimer = 0;
	while (tempTimer < 500)
	{
		for (int i = 128; i > 1; i = i / 2)
		{
			digitalWrite(latchPin, LOW);
			// shift out the bits of dataToSend to the 74HC595
			shiftOut(dataPin, clockPin, LSBFIRST, ~255);
			shiftOut(dataPin, clockPin, LSBFIRST, ~255);

			shiftOut(dataPin, clockPin, LSBFIRST, i);
			shiftOut(dataPin, clockPin, LSBFIRST, i);
			shiftOut(dataPin, clockPin, LSBFIRST, i);
			digitalWrite(latchPin, HIGH);
			delay(100);
		}
	}

	tempTimer = 0;
	while (tempTimer < 500)
	{
		for (int i = 128; i > 1; i = i / 2)
		{
			digitalWrite(latchPin, LOW);
			// shift out the bits of dataToSend to the 74HC595
			shiftOut(dataPin, clockPin, LSBFIRST, ~i);
			shiftOut(dataPin, clockPin, LSBFIRST, ~i);

			shiftOut(dataPin, clockPin, LSBFIRST, 255);
			shiftOut(dataPin, clockPin, LSBFIRST, 255);
			shiftOut(dataPin, clockPin, LSBFIRST, 255);
			digitalWrite(latchPin, HIGH);
			delay(100);
		}
	}

	

	// shift out the bits of dataToSend to the 74HC595
	//shiftOut(dataPinB, clockPinB, LSBFIRST, 256);
	//digitalWrite(latchPinB, HIGH);

	//HC259_send_data();
}

void HC259_send_data()
{
	for (int i = 0; i <= 7; i++)
	{
		HC259_set_address(i);
	//	digitalWrite(HC259_data_pin, HC259_data[i]);
	}
}

void HC259_set_address(int latch)
{
	switch (latch)
	{
	case 0:
		HC259_address[0] = 0;
		HC259_address[1] = 0;
		HC259_address[2] = 0;
		digitalWrite(HC259_A_PIN, 0);
		digitalWrite(HC259_B_PIN, 0);
		digitalWrite(HC259_C_PIN, 0);
		break;
	case 1:
		HC259_address[0] = 0;
		HC259_address[1] = 0;
		HC259_address[2] = 1;
		digitalWrite(HC259_A_PIN, 0);
		digitalWrite(HC259_B_PIN, 0);
		digitalWrite(HC259_C_PIN, 1);
		break;
	case 2:
		HC259_address[0] = 0;
		HC259_address[1] = 1;
		HC259_address[2] = 0;
		digitalWrite(HC259_A_PIN, 0);
		digitalWrite(HC259_B_PIN, 1);
		digitalWrite(HC259_C_PIN, 0);
		break;
	case 3:
		HC259_address[0] = 0;
		HC259_address[1] = 1;
		HC259_address[2] = 1;
		digitalWrite(HC259_A_PIN, 0);
		digitalWrite(HC259_B_PIN, 1);
		digitalWrite(HC259_C_PIN, 1);
		break;
	case 4:
		HC259_address[0] = 1;
		HC259_address[1] = 0;
		HC259_address[2] = 0;
		digitalWrite(HC259_A_PIN, 1);
		digitalWrite(HC259_B_PIN, 0);
		digitalWrite(HC259_C_PIN, 0);
		break;
	case 5:
		HC259_address[0] = 1;
		HC259_address[1] = 0;
		HC259_address[2] = 1;
		digitalWrite(HC259_A_PIN, 1);
		digitalWrite(HC259_B_PIN, 0);
		digitalWrite(HC259_C_PIN, 1);
		break;
	case 6:
		HC259_address[0] = 1;
		HC259_address[1] = 1;
		HC259_address[2] = 0;
		digitalWrite(HC259_A_PIN, 1);
		digitalWrite(HC259_B_PIN, 1);
		digitalWrite(HC259_C_PIN, 0);
		break;
	case 7:
		HC259_address[0] = 1;
		HC259_address[1] = 1;
		HC259_address[2] = 1;
		digitalWrite(HC259_A_PIN, 1);
		digitalWrite(HC259_B_PIN, 1);
		digitalWrite(HC259_C_PIN, 1);
		break;
	default:
		break;
		//nothing;
	}
}


