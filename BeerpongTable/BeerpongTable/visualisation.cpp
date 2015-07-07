#include "visualisation.h"


void visualisation::letter(char letter, int x, int y, int interval)
{
	elapsedMillis tempTimer;
	tempTimer = 0;
	switch (letter)
	{
	case 'a':
		while (tempTimer < interval)
		{
			for (int i = 3; i <= 7; i++)
			{
				drawLed(0 + x, i + y);
			}
			drawLed(1 + x, 2 + y);
			drawLed(1 + x, 4 + y);
			drawLed(2 + x, 1 + y);
			drawLed(2 + x, 4 + y);
			drawLed(3 + x, 2 + y);
			drawLed(3 + x, 4 + y);
			for (int i = 3; i <= 7; i++)
			{
				drawLed(4 + x, i + y);
			}
		}
		break;
	case 'b':
		while (tempTimer < interval)
		{
			for (int r = 1; r <= 7; r++)
			{
				drawLed(0 + x, r + y);
			}
			for (int c = 1; c <= 3; c++)
			{
				drawLed(c + x, 1 + y);
				drawLed(c + x, 4 + y);
				drawLed(c + x, 7 + y);
			}
			drawLed(4 + x, 2 + y);
			drawLed(4 + x, 3 + y);
			drawLed(4 + x, 5 + y);
			drawLed(4 + x, 6 + y);
		}
		break;
	case 'c':
		while (tempTimer < interval)
		{
			for (int r = 2; r < 6; r++)
			{
				drawLed(0 + x, r + y);
			}
			for (int c = 1; c <= 3; c++)
			{
				drawLed(c + x, 1 + y);
				drawLed(c + x, 7 + y);
			}
			drawLed(4 + x, 2 + y);
			drawLed(4 + x, 6 + y);
		}
		break;
	case 'd':
		while (tempTimer < interval)
		{
			for (int r = 1; r <= 7; r++)
			{
				drawLed(0 + x, r + y);
			}
			for (int c = 1; c <= 3; c++)
			{
				drawLed(c + x, 1 + y);
				drawLed(c + x, 7 + y);
			}
			for (int r = 2; r <= 6; r++)
			{
				drawLed(4 + x, r + y);
			}
		}
		break;

	case 'e':
		while (tempTimer < interval)
		{
			for (int r = 1; r <= 7; r++)
			{
				drawLed(0 + x, r + y);
			}
			for (int c = 1; c <= 4; c++)
			{
				drawLed(c + x, 1 + y);
				drawLed(c + x, 7 + y);
			}
			for (int c = 1; c <= 3; c++)
			{
				drawLed(c + x, 4 + y);
			}

		}
		break;

	case 'f':
		while (tempTimer < interval)
		{
		}
		break;

	case 'g':
		while (tempTimer < interval)
		{
		}
		break;
	}
}

void visualisation::arrow(int direction, int x, int y, int interval)
{
	elapsedMillis tempTimer;
	tempTimer = 0;
	switch (direction)
	{
	case 0: //up

		while (tempTimer < interval)
		{
			for (int r = 0; r <= 7; r++)
			{
				drawLed(3 + x, r);
				drawLed(4 + x, r);
			}
			drawLed(2 + x, 2 + y);
			drawLed(2 + x, 3 + y);
			drawLed(1 + x, 3 + y);
			drawLed(5 + x, 2 + y);
			drawLed(5 + x, 3 + y);
			drawLed(6 + x, 3 + y);
		}
		break;

	case 1: //right
		while (tempTimer < interval)
		{
			for (int c = x; c <= 6 + x; c++)
			{
				drawLed(c, 3 + y);
				drawLed(c, 4 + y);
				drawLed(c, 5 + y);
			}
			drawLed(5 + x, 2 + y);
			drawLed(5 + x, 5 + y);
			drawLed(5 + x, 6 + y);
			drawLed(6 + x, 5 + y);
			drawLed(4 + x, 6 + y);
			drawLed(4 + x, 7 + y);
			drawLed(4 + x, 1 + y);
			drawLed(4 + x, 2 + y);
			drawLed(7 + x, 4 + y);

		}
		break;

	case 2: //down
		while (tempTimer < interval)
		{
			for (int r = 0; r <= 7; r++)
			{
				drawLed(3 + x, r);
				drawLed(4 + x, r);

			}
			drawLed(2 + x, 5 + y);
			drawLed(2 + x, 6 + y);
			drawLed(1 + x, 5 + y);
			drawLed(5 + x, 5 + y);
			drawLed(5 + x, 6 + y);
			drawLed(6 + x, 5 + y);
		}
		break;

	case 3: //left
		while (tempTimer < interval)
		{
			for (int c = x + 1; c <= 7 + x; c++)
			{
				drawLed(c, 3 + y);
				drawLed(c, 4 + y);
				drawLed(c, 5 + y);
			}
			drawLed(0 + x, 4 + y);
			drawLed(2 + x, 2 + y);
			drawLed(2 + x, 6 + y);
			drawLed(3 + x, 1 + y);
			drawLed(3 + x, 2 + y);
			drawLed(3 + x, 6 + y);
			drawLed(3 + x, 7 + y);
		}
		break;
	}

}

void visualisation::arrow(int direction, int x, int y)
{

	switch (direction)
	{
	case 0: //up

		for (int r = 0; r <= 7; r++)
		{
			drawLed(3 + x, r);
			drawLed(4 + x, r);
		}
		drawLed(2 + x, 2 + y);
		drawLed(2 + x, 3 + y);
		drawLed(1 + x, 3 + y);
		drawLed(5 + x, 2 + y);
		drawLed(5 + x, 3 + y);
		drawLed(6 + x, 3 + y);

		break;

	case 1: //right

		for (int c = x; c <= 6 + x; c++)
		{
			drawLed(c, 3 + y);
			drawLed(c, 4 + y);
			drawLed(c, 5 + y);
		}
		drawLed(5 + x, 2 + y);
		drawLed(5 + x, 5 + y);
		drawLed(5 + x, 6 + y);
		drawLed(6 + x, 5 + y);
		drawLed(4 + x, 6 + y);
		drawLed(4 + x, 7 + y);
		drawLed(4 + x, 1 + y);
		drawLed(4 + x, 2 + y);
		drawLed(7 + x, 4 + y);


		break;

	case 2: //down

		for (int r = 0; r <= 7; r++)
		{
			drawLed(3 + x, r);
			drawLed(4 + x, r);

		}
		drawLed(2 + x, 5 + y);
		drawLed(2 + x, 6 + y);
		drawLed(1 + x, 5 + y);
		drawLed(5 + x, 5 + y);
		drawLed(5 + x, 6 + y);
		drawLed(6 + x, 5 + y);

		break;

	case 3: //left

		for (int c = x + 1; c <= 7 + x; c++)
		{
			drawLed(c, 3 + y);
			drawLed(c, 4 + y);
			drawLed(c, 5 + y);
		}
		drawLed(0 + x, 4 + y);
		drawLed(2 + x, 2 + y);
		drawLed(2 + x, 6 + y);
		drawLed(3 + x, 1 + y);
		drawLed(3 + x, 2 + y);
		drawLed(3 + x, 6 + y);
		drawLed(3 + x, 7 + y);

		break;
	}

}

int visualisation::drawLed(int column, int row)
{
	if (column < 0)
		return -1;
	else if (column > columns - 1)
		return -1;
	if (row < 0)
		return -1;
	else if (row > rows - 1)
		return -1;
	//	byte dataToSend = ((c[column] | 15 & ~r[row]));
	// setlatch pin low so the LEDs don't change while sending in bits
	digitalWrite(latchPin, LOW);
	// shift out the bits of dataToSend to the 74HC595
	//	shiftOut(dataPin, clockPin, LSBFIRST, r[column]);
	shiftOut(dataPin, clockPin, LSBFIRST, r[row]);
	shiftOut(dataPin, clockPin, LSBFIRST, c2[column]);
	//set latch pin high- this sends data to outputs so the LEDs will light up
	digitalWrite(latchPin, HIGH);
	return 0;
}

void visualisation::allOff(int interval)
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

void visualisation::allOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < rows; i++)
			row(i);
	}
}

void visualisation::row(int row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < columns; i++)
		{
			drawLed(i, row);
		}
	}
}
void visualisation::row(int row)
{
	for (int i = 0; i < columns; i++)
	{
		drawLed(i, row);
	}
}

void visualisation::column(int column, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < rows; i++)
		{
			drawLed(column, i);
		}
	}
}

void visualisation::column(int column)
{
	for (int i = 0; i < rows; i++)
	{
		drawLed(column, i);
	}
}

void visualisation::upToDown(int interval, int startAt)
{
	for (int i = startAt; i < rows; i++)
	{
		row(i, interval);
	}
}

void visualisation::downToUp(int interval, int startAt)
{
	for (int i = rows - startAt - 1; i >= 0; i--)
	{
		row(i, interval);
	}
}


void visualisation::leftToRight(int interval, int startAt)
{
	for (int i = startAt; i < columns; i++)
	{
		column(i, interval);
	}
}

void visualisation::rightToLeft(int interval, int startAt)
{
	for (int i = columns - startAt - 1; i >= 0; i--)
	{
		column(i, interval);
	}
}

void visualisation::bracket(int direction, int x, int y)
{
	switch (direction)
	{
	case 1:
		drawLed(0 + x, 1 + y);
		drawLed(0 + x, 2 + y);
		drawLed(0 + x, 6 + y);
		drawLed(0 + x, 7 + y);
		drawLed(1 + x, 2 + y);
		drawLed(1 + x, 3 + y);
		drawLed(1 + x, 5 + y);
		drawLed(1 + x, 6 + y);
		drawLed(2 + x, 3 + y);
		drawLed(2 + x, 4 + y);
		drawLed(2 + x, 5 + y);
		drawLed(3 + x, 4 + y);
		break;
	}
}