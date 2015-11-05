#pragma once
#include "Drawing.h"

long rowData = 0;
long rowDataP2 = 0;

void setRowData(int _column)
{
	rowData |= ((long)1 << (long)_column);
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

}

void clearData()
{
	rowData = (long)0;
}


//om 2 borden aan te kunnen sturen player meegeven. 1 = BLAUW, 2 = ROOD, 3 = beide
void setRowData(int _column, int player)
{
	if (player == 1)
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
	if (player == 3)
	{
		drawRow(_row, 1);
		drawRow(_row, 2);
	}

	else if (player == 1)
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
	else if (player == 2)
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
	if (player == 1)
	{
		rowData = 0;
	}
	else if (player == 2)
	{
		rowDataP2 = 0;
	}
	else if (player == 3)
	{
		rowData = 0;
		rowDataP2 = 0;
	}
}
