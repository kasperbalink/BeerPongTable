//LED TEST 2 w/ 74HC595
//by Amanda Ghassaei 2012
//http://www.instructables.com/id/Multiplexing-with-Arduino-and-the-74HC595/

/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

//this code will display the values of ledData across a 4x4 led matrix
#include "elapsedMillis.h"
#include "visualisation.h"
//pin connections- the #define tag will replace all instances of "latchPin" in your code with A1 (and so on)
#define latchPin A1
#define clockPin A0
#define dataPin A2



//looping variables
byte i;
byte j;
visualisation visual;
//storage variable
byte dataToSend;

//storage for led states, 4 bytes
byte r[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
byte c[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
void setup()
{
	//set pins as output
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
}

void writeLed(int column, int row)
{
	//	byte dataToSend = ((c[column] | 15 & ~r[row]));
	// setlatch pin low so the LEDs don't change while sending in bits
	digitalWrite(latchPin, LOW);
	// shift out the bits of dataToSend to the 74HC595
	//	shiftOut(dataPin, clockPin, LSBFIRST, r[column]);
	shiftOut(dataPin, clockPin, LSBFIRST, r[row]);
	shiftOut(dataPin, clockPin, LSBFIRST, c[column]);
	//set latch pin high- this sends data to outputs so the LEDs will light up
	digitalWrite(latchPin, HIGH);
}

void writeLed(int column, int row, int interval)
{
	elapsedMillis tempTimer;
	tempTimer = 0;
	while (tempTimer < interval)
	{
		//byte dataToSend = ((c[column] | 15 & ~r[row]));
		// setlatch pin low so the LEDs don't change while sending in bits
		digitalWrite(latchPin, LOW);
		// shift out the bits of dataToSend to the 74HC595
		shiftOut(dataPin, clockPin, LSBFIRST, r[row]);
		shiftOut(dataPin, clockPin, LSBFIRST, c[column]);
		//set latch pin high- this sends data to outputs so the LEDs will light up
		digitalWrite(latchPin, HIGH);
	}
}

void upToDown(int interval, int startAt)
{
	for (int i = startAt; i < rows; i++)
	{
		row(i, interval);
	}
}

void downToUp(int interval, int startAt)
{
	for (int i = rows - startAt - 1; i >= 0; i--)
	{
		row(i, interval);
	}
}


void leftToRight(int interval, int startAt)
{
	for (int i = startAt; i < columns; i++)
	{
		column(i, interval);
	}
}

void rightToLeft(int interval, int startAt)
{
	for (int i = columns - startAt - 1; i >= 0; i--)
	{
		column(i, interval);
	}
}

void diagonalLeftUpRightDown(int interval, int startAt)
{
	elapsedMillis tempTimer;
	tempTimer = interval*startAt;;
	while (tempTimer < interval * 7)
	{
		if (tempTimer < interval)
		{
			writeLed(0, 0);
		}
		else if (tempTimer < interval * 2)
		{
			writeLed(0, 1);
			writeLed(1, 0);
		}
		else if (tempTimer < interval * 3)
		{
			writeLed(0, 2);
			writeLed(1, 1);
			writeLed(2, 0);
		}
		else if (tempTimer < interval * 4)
		{
			writeLed(0, 3);
			writeLed(1, 2);
			writeLed(2, 1);
			writeLed(3, 0);
		}
		else if (tempTimer < interval * 5)
		{
			writeLed(1, 3);
			writeLed(2, 2);
			writeLed(3, 1);
		}
		else if (tempTimer < interval * 6)
		{
			writeLed(2, 3);
			writeLed(3, 2);
		}
		else if (tempTimer < interval * 7)
		{
			writeLed(3, 3);
		}
	}
}

void diagonalRightDownLeftUp(int interval, int startAt)
{
	elapsedMillis tempTimer;
	tempTimer = interval*startAt;
	while (tempTimer < interval * 7)
	{
		if (tempTimer < interval)
		{
			writeLed(3, 3);
		}
		else if (tempTimer < interval * 2)
		{
			writeLed(2, 3);
			writeLed(3, 2);

		}
		else if (tempTimer < interval * 3)
		{
			writeLed(1, 3);
			writeLed(2, 2);
			writeLed(3, 1);
		}
		else if (tempTimer < interval * 4)
		{
			writeLed(0, 3);
			writeLed(1, 2);
			writeLed(2, 1);
			writeLed(3, 0);
		}
		else if (tempTimer < interval * 5)
		{
			writeLed(0, 2);
			writeLed(1, 1);
			writeLed(2, 0);
		}
		else if (tempTimer < interval * 6)
		{
			writeLed(0, 1);
			writeLed(1, 0);
		}
		else if (tempTimer < interval * 7)
		{
			writeLed(0, 0);
		}
	}
}

void row(int row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < columns; i++)
		{
			writeLed(i, row);
		}
	}
}
void row(int row)
{
	for (int i = 0; i < columns; i++)
	{
		writeLed(i, row);
	}
}

void column(int column, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < rows; i++)
		{
			writeLed(column, i);
		}
	}
}

void column(int column)
{
	for (int i = 0; i < rows; i++)
	{
		writeLed(column, i);
	}
}

void snake(int interval)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			writeLed(j, i, interval);
		}
	}
}

void squareInside(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		writeLed(1, 1);
		writeLed(2, 1);
		writeLed(1, 2);
		writeLed(2, 2);
	}
}
void squareOutside(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		row(0);
		row(3);
		column(0);
		column(3);
	}
}

void allOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < rows; i++)
			row(i);
	}
}
void allOff(int interval)
{
	byte dataToSend = (0);
	// setlatch pin low so the LEDs don't change while sending in bits
	digitalWrite(latchPin, LOW);
	// shift out the bits of dataToSend to the 74HC595
	shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
	shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
	//set latch pin high- this sends data to outputs so the LEDs will light up
	digitalWrite(latchPin, HIGH);
	delay(interval);
}
void loop()
{
	//writeLed(8, 7);
	//upToDown(50, 0);
	//leftToRight(50, 0);
	//allOn(500);
	//visual.drawLetter('a', 0, 0, 2000);
	//visual.drawLetter('b', 0, 0, 2000);
	//visual.drawLetter('c', 0, 0, 2000);
	//visual.drawLetter('d', 0, 0, 2000);
	//visual.drawLetter('e', 0, 0, 2000);
	for (int i = 0; i < 5; i++)
	{
		for (int x = -4; x < 8; x++)
			visual.drawArrow(1, x, 0, 50);
		allOff(50);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int x = 7; x >= -4; x--)
			visual.drawArrow(3, x, 0, 50);
		allOff(50);
	}
	visual.drawLetter('a', 0, 0, 100);
}

// the heart of the program




