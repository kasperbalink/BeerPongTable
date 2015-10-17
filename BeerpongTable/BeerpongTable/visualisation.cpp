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

void visualisation::bracket(int direction, int _column, int _row)
{

}
void visualisation::number(int _number, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number(_number);
	}
}

void visualisation::number(int _number)
{
	switch (_number)
	{
	case 0:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 7); drawLed(4, 10);
		drawLed(5, 7); drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);
		drawLed(8, 7); drawLed(7, 7);
		break;
	case 1:
		drawLed(3, 9); drawLed(4, 8); drawLed(4, 9);
		drawLed(5, 7); drawLed(5, 9); drawLed(6, 9);
		drawLed(7, 9); drawLed(8, 9); drawLed(9, 9);
		drawLed(9, 7); drawLed(9, 8); drawLed(9, 10);
		break;
	case 2:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 10);
		drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);
		drawLed(8, 7); drawLed(7, 7);
		break;
	case 3:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10);drawLed(4, 10);
		drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);		
		break;
	case 4:
		drawLed(3, 7); 
		drawLed(3, 10); drawLed(4, 7); drawLed(4, 10);
		drawLed(5, 7); drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		break;
	case 5:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 7); 
		drawLed(5, 7); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);
		
		break;
	case 6:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 7); drawLed(5, 7);
		drawLed(6, 7); drawLed(6, 8); drawLed(6, 9);
		drawLed(6, 10);	drawLed(7, 10); drawLed(8, 10);
		drawLed(9, 10);	drawLed(9, 9); drawLed(9, 8);
		drawLed(9, 7); drawLed(8, 7); drawLed(7, 7);
		break;
	case 7:
		drawLed(4, 7); drawLed(3, 7); drawLed(3, 8);
		drawLed(3, 9); drawLed(3, 10); drawLed(4, 10);
		drawLed(5, 10); drawLed(6, 10); drawLed(7, 10);
		drawLed(8, 10); drawLed(9, 10); drawLed(6, 9);
		drawLed(6, 11);
		break;
	case 8:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 7); drawLed(4, 10);
		drawLed(5, 7); drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);
		drawLed(8, 7); drawLed(7, 7);
		break;
	case 9:
		drawLed(3, 7); drawLed(3, 8); drawLed(3, 9);
		drawLed(3, 10); drawLed(4, 7); drawLed(4, 10);
		drawLed(5, 7); drawLed(5, 10); drawLed(6, 7);
		drawLed(6, 8); drawLed(6, 9); drawLed(6, 10);
		drawLed(7, 10); drawLed(8, 10); drawLed(9, 10);
		drawLed(9, 9); drawLed(9, 8); drawLed(9, 7);

		break;
	case 10:
		drawLed(5, 4); drawLed(4, 5); drawLed(3, 6);
		drawLed(4, 6); drawLed(5, 6); drawLed(6, 6);
		drawLed(7, 6); drawLed(8, 6); drawLed(9, 6);
		drawLed(9, 4); drawLed(9, 5); drawLed(9, 7);

		drawLed(3, 11); drawLed(3, 12); drawLed(3, 13);
		drawLed(4, 10); drawLed(4, 14); drawLed(5, 10);
		drawLed(5, 14); drawLed(6, 10); drawLed(6, 14);
		drawLed(7, 10); drawLed(7, 14); drawLed(8, 10);
		drawLed(8, 14);
		drawLed(9, 11); drawLed(9, 12); drawLed(9, 13);
		break;
	}
}

void visualisation::showScore(int _number)
{
	scoreSquare();
	number(_number);
}

void visualisation::showScore(int _number, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		showScore(_number);
	}
}

//ROWS AND COLUMNS
void visualisation::row(int row)
{
	for (int i = 0; i <= plus; i++)
	{
		drawLed(row, i);
	}
}

void visualisation::rowInside(int row)
{
	for (int i = 1; i < plus; i++)
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
	for (int i = 0; i <= min; i++)
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
		for (int i = 0; i <= 8; i++)
		{
			drawLed(5 + _row, i + _column);
			drawLed(6 + _row, i + _column);
			drawLed(7 + _row, i + _column);
		}
		drawLed(6 + _row, 9 + _column);

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
		drawLed(10 + _row, 5 + _column);

		break;

	case 1: //to player
		break;

	case 2: //to left from player view
		break;

	case 3: //to right from player view
		break;
	}

}


//FIELDS: INSIDE, OUTSIDE, BOTH, NOTHING
void visualisation::outsideOn()
{
	row(0);
	row(min);
	column(0);
	column(plus);
}
void visualisation::outsideOn(int interval)
{
	allOff();
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		outsideOn();
	}
}

void visualisation::insideOn(int interval)
{
	allOff();
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		for (int i = 1; i < min; i++)
		{
			rowInside(i);
		}
	}
}

void visualisation::scoreSquare()
{
	for (int i = 2; i < plus -1; i++)
	{
		drawLed(1, i);
		drawLed(11, i);
	}
	for (int i = 2; i < min; i++)
	{
		drawLed(i, 2);
		drawLed(i, 16);
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
		for (int i = 0; i <= plus; i++)
		{
			column(i);
		}
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
			_min = _min - 8;
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
			
		}

		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
		return 0;
	}
	else if (_plus < 16) //kolom 8 tm 15
	{
		_plus = _plus - 8;
		digitalWrite(latchPin, LOW);
		if (_min < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 0 t/m 7
		}
		else
		{
			_min = _min - 8;
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
		}

		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
		return 0;

	}
	else //kolom 16 tm 18
	{
		_plus = _plus - 16;
		digitalWrite(latchPin, LOW);
		if (_min < 8)
		{
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 0 t/m 7
		}
		else
		{
			_min = _min - 8;
			shiftOut(dataPin, clockPin, LSBFIRST, ~data[_min]); //min 8 t/m 12
			shiftOut(dataPin, clockPin, LSBFIRST, ~0); //min 0 t/m 7
		}

		shiftOut(dataPin, clockPin, LSBFIRST, data[_plus]); //plus 16 t/m 18
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 8 t/m 15
		shiftOut(dataPin, clockPin, LSBFIRST, 0); //plus 0 t/m 7
		digitalWrite(latchPin, HIGH);
		return 0;

	}
	return 0;
}