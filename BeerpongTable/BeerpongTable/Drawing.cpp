#pragma once
#include "Drawing.h"

long rowData = 0;

void setRowData(int _column)
{
	rowData |= ((long)1 << (long)_column);
}

//_row = 0 t/m 12
void drawRow(int _row)
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

void clearData()
{
	rowData = 0;
}
