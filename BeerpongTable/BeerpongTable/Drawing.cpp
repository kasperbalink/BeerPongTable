#pragma once
#include "Drawing.h"


long cupData = 0;
long cupDataP2 = 0;
long rowData = 0;
long rowDataP2 = 0;

elapsedMillis cupTimerP1[10];
elapsedMillis cupTimerP2[10];

elapsedMillis cupTimerOffP1[10];
elapsedMillis cupTimerOffP2[10];


void drawLedCups(int player)
{
	if (player == 1)
	{
		digitalWrite(latchPinCup_P1, LOW);
		shiftOut(dataPinCup_P1, clockPinCup_P1, LSBFIRST, (cupData >> 8) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPinCup_P1, clockPinCup_P1, LSBFIRST, (cupData & 0xFF)); //plus 8 t/m 15
		digitalWrite(latchPinCup_P1, HIGH);
	}
	else if (player == 2)
	{
		digitalWrite(latchPinCup_P2, LOW);
		shiftOut(dataPinCup_P2, clockPinCup_P2, LSBFIRST, (cupDataP2 >> 8) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPinCup_P2, clockPinCup_P2, LSBFIRST, (cupDataP2 & 0xFF)); //plus 8 t/m 15
		digitalWrite(latchPinCup_P2, HIGH);
	}
}
void clearCupData(int player)
{
	if (player == 1)
	{
		cupData = (long)0;
	}
	else if(player == 2)
	{
		cupDataP2 = (long)0;
	}
}
void setCup(int player, int cup)
{
	if (player == 1)
	{	
		//if (cupTimerOffP1[cup] > 1000)
		{
			cupTimerOffP1[cup] = 1001;
			cupTimerP1[cup] = 0;
			cupData |= ((long)1 << (long)cup);
		}
	}
	else if (player == 2)
	{
		//if (cupTimerOffP2[cup] > 1000)
		{
			cupTimerOffP2[cup] = 1001;
			cupTimerP2[cup] = 0;
			cupDataP2 |= ((long)1 << (long)cup);
		}
	}
}
void disableCup(int player, int cup)
{	
	if (player == 1)
	{
		//if (cupTimerP1[cup] > 1000)
		{
			cupTimerOffP1[cup] = 0;
			cupTimerP1[cup] = 1001;
			cupData &= ~((long)1 << (long)cup);
		}
	}
	else if (player == 2)
	{
		//if (cupTimerP2[cup] > 1000)
		{
			cupTimerP2[cup] = 1001;
			cupDataP2 &= ~((long)1 << (long)cup);
		}
	}
}


void setRowData(int player, int _column)
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

void shiftRowData(int player, int shiftLeft)
{
	//rowData = rowData << shiftLeft
}
void drawRow(int player, int _row)
{

	if (player == 1)
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
	yield();

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

void drawTable(int player, int data[])
{
	for (int i = 0; i < 13; i++)
	{
		drawRow(player, data[i]);
	}
}