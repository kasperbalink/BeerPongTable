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


#define HC259_A_PIN A0
#define HC259_B_PIN A1
#define HC259_C_PIN A2

#define latchPin  A0
#define clockPin A1
#define dataPin  A2

#define latchPinB  A3
#define clockPinB A4
#define dataPinB  A5

boolean HC259_address[3] = { 0, 0, 0 };
boolean HC259_data[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

visualisation visual;

//storage for led states, 4 bytes
byte r[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
//byte r[] = { 1, 2, 4, 8, 16, 32, 64, 128};
byte c[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
void setup()
{
	pinMode(HC259_A_PIN, OUTPUT);
	pinMode(HC259_B_PIN, OUTPUT);
	pinMode(HC259_C_PIN, OUTPUT);
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

void writeLed2(int row, int interval)
{
	elapsedMillis tempTimer;
	tempTimer = 0;
	while (tempTimer < interval)
	{
		//	byte dataToSend = ((c[column] | 15 & ~r[row]));
		// setlatch pin low so the LEDs don't change while sending in bits
		digitalWrite(latchPin, LOW);
		// shift out the bits of dataToSend to the 74HC595
		if (row < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
			shiftOut(dataPin, clockPin, LSBFIRST, r[row]);
		}
		else if (row < 16)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
			shiftOut(dataPin, clockPin, LSBFIRST, r[row - 8]);
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
		}
		else if (row < 24)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, r[row - 16]);
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
			shiftOut(dataPin, clockPin, LSBFIRST, 0);
		}
		//set latch pin high- this sends data to outputs so the LEDs will light up
		digitalWrite(latchPin, HIGH);
	}
}

void allOff(int interval)
{
	digitalWrite(latchPin, LOW);
	elapsedMillis tempTimer;
	tempTimer = 0;
	while (tempTimer < interval)
	{
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
	}
	digitalWrite(latchPin, HIGH);
}
void allOn(int interval)
{
	digitalWrite(latchPin, LOW);
	elapsedMillis tempTimer;
	tempTimer = 0;
	while (tempTimer < interval)
	{
		for (int i = 0; i < 19; i++)
		{
			row(i);
		}
	}
	digitalWrite(latchPin, HIGH);
}
void row(int x)
{
	//	byte dataToSend = ((c[column] | 15 & ~r[row]));
	// setlatch pin low so the LEDs don't change while sending in bits
	digitalWrite(latchPin, LOW);
	// shift out the bits of dataToSend to the 74HC595
	if (x < 8)
	{
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, r[x]);
	}
	else if (x < 16)
	{
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, r[x - 8]);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
	}
	else if (x < 24)
	{
		shiftOut(dataPin, clockPin, LSBFIRST, r[x - 16]);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
	}
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
		/*row(0);
		row(3);
		column(0);
		column(3);*/
	}
}
void line(int size, int interval)
{
	int min = 0;
	int max = 0;

	while (max < size)
	{
		elapsedMillis tempTimer;
		tempTimer = 0;
		while (tempTimer < interval)
		{
			for (int i = min; i < max; i++)
			{
				row(i);
			}
		}
		max++;
	}
	while (min <= 19)
	{
		elapsedMillis tempTimer;
		tempTimer = 0;
		while (tempTimer < interval)
		{
			for (int i = min; i < max; i++)
			{
				row(i);
			}
		}
		min++;
		max++;
	}
	while (max >= 0)
	{
		elapsedMillis tempTimer;
		tempTimer = 0;
		while (tempTimer < interval)
		{
			for (int i = min; i < max; i++)
			{
				row(i);
			}
		}
		if (min != 0)
		{
			min--;
		}
		max--;
	}
}
void loop()
{
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


