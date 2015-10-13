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
			
		}
		break;
	case 'c':
		while (tempTimer < interval)
		{
		}
		break;
	case 'd':
		while (tempTimer < interval)
		{
		}
		break;

	case 'e':
		while (tempTimer < interval)
		{
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
	while (tempTimer < interval)
	{
		arrow(direction, x, y);
	}
}

void visualisation::arrow(int direction, int x, int y)
{

	switch (direction)
	{
	case 0: //up
		break;

	case 1: //right
		break;

	case 2: //down
		break;

	case 3: //left
		break;
	}

}

int visualisation::drawLed(int _min, int _plus)
{
	if (_plus < 0 || _plus > plus || _min < 0 || _min > min) //foute waarde? -> niks doen
	{
		return -1;
	}


	if (_plus < 8) //kolom 0 tm 7
	{
		digitalWrite(latchPin, LOW);
		if (_min < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 0 t/m 7
		}
		else
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
		}

		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
	}
	else if (_plus < 16) //kolom 8 tm 15
	{
		digitalWrite(latchPin, LOW);
		if (_min < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 0 t/m 7
		}
		else
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
		}

		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
	}
	else //kolom 16 tm 18
	{
		digitalWrite(latchPin, LOW);
		if (_min < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 0 t/m 7
		}
		else
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
		}

		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
	}
	return 0;
}

void visualisation::allOff(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		digitalWrite(latchPin, LOW);
		//minnen uit
		shiftOut(dataPin, clockPin, LSBFIRST, ~0);
		shiftOut(dataPin, clockPin, LSBFIRST, ~0);

		//plussen uit
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		shiftOut(dataPin, clockPin, LSBFIRST, 0);
		digitalWrite(latchPin, HIGH);
	}
}

void visualisation::allOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < min; i++)
			row(i);
	}
}

void visualisation::outsideOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		row(0);
		row(min);
		column(0);
		column(plus);
	}
}

void visualisation::insideOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 1; i < min-1; i++)
		{
			rowInside(i);
		}
	}
}

void visualisation::row(int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		row(_row);
	}
}

void visualisation::column(int _column, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		column(_column);
	}
}


void visualisation::row(int row)
{
	for (int i = 0; i < plus; i++)
	{
		drawLed(row, i);
	}
}

void visualisation::rowInside(int row)
{
	for (int i = 1; i < plus-1; i++)
	{
		drawLed(row, i);
	}
}

void visualisation::column(int column)
{
	for (int i = 0; i < min; i++)
	{
		drawLed(i, column);
	}
}

void visualisation::columnInside(int column)
{
	for (int i = 1; i < min-1; i++)
	{
		drawLed(i, column);
	}
}


void visualisation::upToDown(int interval)
{
	for (int i = 0; i < min; i++)
	{
		row(i, interval);
	}
}

void visualisation::downToUp(int interval)
{
	for (int i = min; i > 0; i--)
	{
		row(i, interval);
	}
}


void visualisation::leftToRight(int interval)
{
	for (int i = 0; i < plus; i++)
	{
		column(i, interval);
	}
}

void visualisation::rightToLeft(int interval)
{
	for (int i = plus; i > 0; i--)
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