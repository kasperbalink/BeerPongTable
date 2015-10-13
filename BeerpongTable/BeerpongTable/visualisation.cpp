#include "visualisation.h"




//CHARACTERS
void visualisation::letter(char _letter, int _column, int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		letter(_letter, _column, _row);
	}	
}

void visualisation::letter(char _letter, int _column, int _row)
{
	switch (_letter)
	{
	case 'a':
			for (int i = 3; i <= 7; i++)
			{
				drawLed(0 + _column, i + _row);
			}
			drawLed(1 + _column, 2 + _row);
			drawLed(1 + _column, 4 + _row);
			drawLed(2 + _column, 1 + _row);
			drawLed(2 + _column, 4 + _row);
			drawLed(3 + _column, 2 + _row);
			drawLed(3 + _column, 4 + _row);
			for (int i = 3; i <= 7; i++)
			{
				drawLed(4 + _column, i + _row);
			}
		break;

	case 'b':
		break;

	case 'c':
		break;

	case 'd':
		break;

	case 'e':
		break;

	case 'f':
		break;

	case 'g':
		break;
	}
}

void visualisation::bracket(int direction, int x, int y)
{
	switch (direction)
	{
	case 1:
		break;
	}
}

void visualisation::arrow(int direction, int _column, int _row, int interval) //arrow method with interval
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		arrow(direction, _column, _row);
	}
} 

void visualisation::arrow(int direction, int _column, int _row)
{

	switch (direction)
	{
	case 0: //to center
		for (int i = 0; i < 8; i++)
		{
			drawLed(5 + _row, i + _column);
			drawLed(6 + _row, i + _column);
			drawLed(7 + _row, i + _column);
		}
		drawLed(6 + _row, 9);

		for (int i = 2; i < 10; i++)
		{
			drawLed(i + _row, 5 + _column);
		}
		drawLed(3 + _row, 6 + _column);
		drawLed(4 + _row, 6 + _column);
		drawLed(4 + _row, 7 + _column);

		drawLed(8 + _row, 7 + _column);
		drawLed(8 + _row, 6 + _column);
		drawLed(9 + _row, 6 + _column);
		
		break;

	case 1: //to player
		break;

	case 2: //to left from player view
		break;

	case 3: //to right from player view
		break;
	}

}








//ROWS AND COLUMNS
void visualisation::row(int row)
{
	for (int i = 0; i < plus; i++)
	{
		drawLed(row, i);
	}
}

void visualisation::rowInside(int row)
{
	for (int i = 1; i < plus - 1; i++)
	{
		drawLed(row, i);
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

void visualisation::column(int column)
{
	for (int i = 0; i < min; i++)
	{
		drawLed(i, column);
	}
}

void visualisation::columnInside(int column)
{
	for (int i = 1; i < min - 1; i++)
	{
		drawLed(i, column);
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



//VISUALISATIONS
void visualisation::upToDown(int timeBetweenSteps)
{
	for (int i = 0; i < min; i++)
	{
		row(i, timeBetweenSteps);
	}
}

void visualisation::downToUp(int timeBetweenSteps)
{
	for (int i = min; i > 0; i--)
	{
		row(i, timeBetweenSteps);
	}
}

void visualisation::leftToRight(int timeBetweenSteps)
{
	for (int i = 0; i < plus; i++)
	{
		column(i, timeBetweenSteps);
	}
}

void visualisation::rightToLeft(int timeBetweenSteps)
{
	for (int i = plus; i > 0; i--)
	{
		column(i, timeBetweenSteps);
	}
}




//FIELDS: INSIDE, OUTSIDE, BOTH, NOTHING
void visualisation::outsideOn(int interval)
{
	allOff();
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
	allOff();
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 1; i < min - 1; i++)
		{
			rowInside(i);
		}
	}
}


void visualisation::allOff(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		allOff();
	}
}

void visualisation::allOff()
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

void visualisation::allOn(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 0; i < min; i++)
			row(i);
	}
}

//general method for drawing 1 led.
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