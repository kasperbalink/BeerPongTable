#pragma once
#include "Drawing.h"



long rowData = 0;
long rowDataP2 = 0;

int setRowData(int _column)
{
	if (_column > 18 || _column < 0)
	{
		return -1;
	}
	rowData |= ((long)1 << (long)_column);
	return 0;
}

void setRealRowData(long value)
{
	rowData = value;
}

//_row = 0 t/m 12
void drawRow(int _row)
{
	//@to-do //0xFF = 255 
	digitalWrite(latchPin_P1, LOW);

	shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
	shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

	shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData >> 16) & 0xFF); //plus 0 t/m 7
	shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData >> 8) & 0xFF); //plus 8 t/m 15
	shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData & 0xFF)); //plus 16 t/m 18

	digitalWrite(latchPin_P1, HIGH);
	//irRead();
}

void clearData()
{
	rowData = (long)0;
}


//om 2 borden aan te kunnen sturen player meegeven. 1 = BLAUW, 2 = ROOD, 3 = beide
void setRowData(int _column, int player)
{
	if (player == 0)
	{
		rowData |= ((long)1 << (long)_column);
	}
	else
	{
		rowDataP2 |= ((long)1 << (long)_column);
	}

}

//_row = 0 t/m 12
void drawRow(int _row, int player)
{
	if (player == 2)
	{
		drawRow(_row, 0);
		drawRow(_row, 1);
	}

	else if (player == 0)
	{
		//@to-do //0xFF = 255 
		digitalWrite(latchPin_P1, LOW);

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData >> 16) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData >> 8) & 0xFF); //plus 8 t/m 15
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (rowData & 0xFF)); //plus 16 t/m 18

		digitalWrite(latchPin_P1, HIGH);
	}
	else if (player == 1)
	{
		digitalWrite(latchPin_P2, LOW);

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (rowDataP2 >> 16) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (rowDataP2 >> 8) & 0xFF); //plus 8 t/m 15
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (rowDataP2 & 0xFF)); //plus 16 t/m 18

		digitalWrite(latchPin_P2, HIGH);
	}

}

void clearData(int player)
{
	if (player == 0)
	{
		rowData = 0;
	}
	else if (player == 1)
	{
		rowDataP2 = 0;
	}
	else if (player == 2)
	{
		rowData = 0;
		rowDataP2 = 0;
	}
}
