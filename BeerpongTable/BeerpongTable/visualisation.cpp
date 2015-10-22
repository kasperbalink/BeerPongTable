#include "visualisation.h"


//FIGURES

int visualisation::square(int size, int interval)
{
	if (size > MIN / 2)
	{
		return -1;
	}

	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		square(size);
	}
}

int visualisation::square(int size)
{

	if (size > MIN / 2)
	{
		return -1;
	}
	rowData = 0;
	for (int i = 0 + size; i <= PLUS - size; i++)
	{
		setLedsInRow(i);
	}
	drawRow(0 + size);
	drawRow(MIN - size);
	rowData = 0;
	setLedsInRow(size);
	setLedsInRow(PLUS - size);
	for (int i = 0 + size; i <= MIN - size; i++)
	{
		drawRow(i);
	}
	return 0;
}

void visualisation::scoreSquare()
{
	rowData = 0;
	for (int i = 2; i < PLUS - 1; i++)
	{
		setLedsInRow(i);
	}
	drawRow(1);
	drawRow(11);

	rowData = 0;

	setLedsInRow(2);
	setLedsInRow(16);
	for (int x = 2; x < MIN - 1; x++)
	{
		drawRow(x);
	}
}

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

/* _number is real number 0 - 99*/
void visualisation::number(int _number)
{
	number(_number, 0, 0);
}

/* _number is real number 0 - 99
interval is time to be dispaled in MS*/
void visualisation::number(int _number, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number(_number, 0, 0);
	}
}

/* _number is real number 0 - 99
_column is offset X, 0 = center
_row is offset Y, 0 = center */
void visualisation::number(int _number, int _column, int _row)
{
	if (_number > 9 && _number < 100)
	{
		number(_number % 10, 4 + _column, _row);
		number(_number / 10, -4 + _column, _row);
	}
	else
	{
		switch (_number)
		{
		case 0:
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(9 + _column);
			drawRow(3 + _row); drawRow(4 + _row); drawRow(5 + _row);
			drawRow(6 + _row); drawRow(7 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(2 + _row); drawRow(8 + _row);
			break;
		case 1:
			rowData = 0;
			setLedsInRow(8 + _column); drawRow(2 + _row);
			setLedsInRow(7 + _column); drawRow(3 + _row);
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(8 + _column);
			rowData = 0;
			setLedsInRow(8 + _column);
			drawRow(5 + _row); drawRow(6 + _row); drawRow(7 + _row);
			setLedsInRow(6 + _column); setLedsInRow(7 + _column); setLedsInRow(9 + _column);
			drawRow(8 + _row);
			break;
		case 2:
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(7 + _column);
			setLedsInRow(8 + _column); setLedsInRow(9 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			rowData = 0;
			setLedsInRow(9 + _column); drawRow(3 + _row); drawRow(4 + _row);
			rowData = 0;
			setLedsInRow(6 + _column); drawRow(6 + _row); drawRow(7 + _row);
			break;
		case 3:
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(7 + _column);
			setLedsInRow(8 + _column); setLedsInRow(9 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			rowData = 0;
			setLedsInRow(9 + _column);
			drawRow(3 + _row); drawRow(4 + _row); drawRow(6 + _row); drawRow(7 + _row);
			break;
		case 4:
			rowData = 0;
			setLedsInRow(9 + _column);
			drawRow(6 + _row); drawRow(7 + _row); drawRow(8 + _row);
			setLedsInRow(6 + _column);
			drawRow(2 + _row); drawRow(3 + _row); drawRow(4 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(5 + _row);
			break;
		case 5:
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(7 + _column);
			setLedsInRow(8 + _column); setLedsInRow(9 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			rowData = 0;
			setLedsInRow(6 + _column);
			drawRow(3 + _row); drawRow(4 + _row);
			rowData = 0;
			setLedsInRow(9 + _column); drawRow(6 + _row); drawRow(7 + _row);
			break;
		case 6:
			rowData = 0;
			setLedsInRow(6 + _column);
			drawRow(3 + _row); drawRow(4 + _row);
			setLedsInRow(9 + _column);
			drawRow(6 + _row); drawRow(7 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			break;
		case 7:
			rowData = 0;
			setLedsInRow(9 + _column);
			drawRow(3 + _row); drawRow(4 + _row); drawRow(6 + _row);
			drawRow(7 + _row); drawRow(8 + _row);
			setLedsInRow(8 + _column); setLedsInRow(10 + _column);
			drawRow(5 + _row);
			rowData = 0;
			setLedsInRow(6 + _column);  setLedsInRow(9 + _column);
			drawRow(3 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(2 + _row);
			break;
		case 8:
			rowData = 0;
			setLedsInRow(6 + _column); setLedsInRow(9 + _column);
			drawRow(3 + _row); drawRow(4 + _row); drawRow(6 + _row); drawRow(7 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			break;
		case 9:
			rowData = 0;
			setLedsInRow(9 + _column);
			drawRow(6 + _row); drawRow(7 + _row);
			setLedsInRow(6 + _column);
			drawRow(3 + _row); drawRow(4 + _row);
			setLedsInRow(7 + _column); setLedsInRow(8 + _column);
			drawRow(2 + _row); drawRow(5 + _row); drawRow(8 + _row);
			break;
		}
	}
}

/* _number is real number 0 - 99
_column is offset X, 0 = center
_row is offset Y, 0 = center
interval is time to be dispaled in MS*/
void visualisation::number(int _number, int _column, int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number(_number, _row, _column);
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
	for (int i = 0; i <= PLUS; i++)
	{
		setLedsInRow(i);
	}
	drawRow(row);
}

void visualisation::rowInside(int row)
{
	rowData = 0;
	for (int i = 1; i < PLUS; i++)
	{
		setLedsInRow(i);
	}
	drawRow(row);
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
	rowData = 0;
	setLedsInRow(column);
	for (int i = 0; i <= MIN; i++)
	{
		drawRow(i);
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

void visualisation::column(int starColumn, int endColumn)
{
	rowData = 0;
	for (int i = starColumn; i < endColumn; i++)
	{
		setLedsInRow(i);
	}
	for (int i = 0; i <= MIN; i++)
	{
		drawRow(i);
	}
}

void visualisation::column(int startColumn, int endColumn, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		column(startColumn, endColumn);
	}
}

void visualisation::columnInside(int column)
{
	rowData = 0;
	setLedsInRow(column);
	for (int i = 1; i < MIN - 1; i++)
	{
		drawRow(i);
	}
}


//VISUALISATIONS

//size is thickness of line, size 0 = 1 line thick
void visualisation::upToDown(int size, int timeBetweenSteps)
{
	for (int i = 0; i <= MIN; i++)
	{
		for (int x = 0; x < size; x++)
		{
			row(i - x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void visualisation::downToUp(int size, int timeBetweenSteps)
{
	for (int i = MIN; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			row(i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void visualisation::leftToRight(int size, int timeBetweenSteps)
{
	for (int i = 0; i <= PLUS; i++)
	{
		for (int x = 0; x < size; x++)
		{
			column(i + x, timeBetweenSteps);
		}
	}
}

//size is thickness of line, size 0 = 1 line thick
void visualisation::rightToLeft(int size, int timeBetweenSteps)
{
	for (int i = PLUS; i >= 0; i--)
	{
		for (int x = 0; x < size; x++)
		{
			column(i - x, timeBetweenSteps);
		}
	}
}

//_column = verplaatsing links/rechts
//_row = verplaatsing boven/benden
//_column & _row == 0: pijl aan spelers kant
void visualisation::arrow(int direction, int _column, int _row, int interval) //arrow method with interval
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		arrow(direction, _column, _row);
	}
}

//_column = verplaatsing links/rechts
//_row = verplaatsing boven/benden
//_column & _row == 0: pijl aan spelers kant
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
	row(MIN);
	column(0);
	column(PLUS);
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
		for (int i = 1; i < MIN; i++)
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
		allOn();
	}
}

void visualisation::allOn()
{
	for (int m = 0; m < MIN; m++)
	{
		for (int i = 0; i < PLUS; i++)
		{
			setLedsInRow(i);
		}
		drawRow(m);
	}
}

//general method for drawing 1 led.
int visualisation::drawLed(int _min, int _plus)
{
	if (_plus < 0 || _plus > PLUS || _min < 0 || _min > MIN) //foute waarde? -> niks doen
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



//RIJ 4, LED 2, 6 EN 9
//setLedInRow(1);
//setLedInRow(5);
//setLedInRow(8);
//drawRow(3);


//_column = 0 t/m 18
//rowData = _column -> welke kolommen moeten er aan?
void visualisation::setLedsInRow(int _column)
{
	rowData |= ((long)1 << (long)_column);
}

//_row = 0 t/m 12
void visualisation::drawRow(int _row)
{
	//@to-do //0xFF = 255 
	digitalWrite(latchPin, LOW);

	shiftOut(dataPin, clockPin, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
	shiftOut(dataPin, clockPin, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

	shiftOut(dataPin, clockPin, LSBFIRST, (rowData >> 16) & 0xFF); //plus 0 t/m 7
	shiftOut(dataPin, clockPin, LSBFIRST, (rowData >> 8) & 0xFF); //plus 8 t/m 15
	shiftOut(dataPin, clockPin, LSBFIRST, (rowData & 0xFF)); //plus 16 t/m 18



	digitalWrite(latchPin, HIGH);

}