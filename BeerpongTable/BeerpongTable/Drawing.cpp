#pragma once
#include "Drawing.h"


long cupData = 0;
long cupDataP2 = 0;
long rowData = 0;
long rowDataP2 = 0;


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
	yield();
}
int addCup(int player, int cup)
{
	if (cup > 10 || cup < 0)
	{
		return -1;
	}
	if (player == 1)
	{	
		cupData |= ((long)1 << (long)cup);
	}
	else if (player == 2)
	{
		cupDataP2 |= ((long)1 << (long)cup);
	}
	return 0;
}
int removeCup(int player, int cup)
{
	if (cup > 10 || cup < 0)
	{
		return -1;
	}
	if (player == 1)
	{		
		cupData &= ~((long)1 << (long)cup);
	}
	else if (player == 2)
	{
		cupDataP2 &= ~((long)1 << (long)cup);
	}
	return 0;
}
void clearCupData(int player)
{
	if (player == 1)
	{
		cupData = (long)0;
	}
	else if (player == 2)
	{
		cupDataP2 = (long)0;
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

void drawRow(int player, int _row)
{
	if (player == 1)
	{
		//0xFF = 255 
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

void drawRow(int player, int _row, long inputdata)
{
	if (player == 1)
	{
		//0xFF = 255 
		digitalWrite(latchPin_P1, LOW);

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (inputdata >> 16) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (inputdata >> 8) & 0xFF); //plus 8 t/m 15
		shiftOut(dataPin_P1, clockPin_P1, LSBFIRST, (inputdata & 0xFF)); //plus 16 t/m 18

		digitalWrite(latchPin_P1, HIGH);
	}
	else if (player == 2)
	{
		digitalWrite(latchPin_P2, LOW);

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~((1 << _row) >> 8) & 0xFF); //min 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, ~(1 << _row) & 0xFF); //min 8 t/m 12

		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (inputdata >> 16) & 0xFF); //plus 0 t/m 7
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (inputdata >> 8) & 0xFF); //plus 8 t/m 15
		shiftOut(dataPin_P2, clockPin_P2, LSBFIRST, (inputdata & 0xFF)); //plus 16 t/m 18

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


void drawTable(int player, long inputData[])
{
	if (player == 1)
	{
		for (int i = 0; i < 13; i++)
		{
				drawRow(1, i, inputData[i]);
		}
	}
	else if (player == 2)
	{
		for (int i = 0; i < 13; i++)
		{
				drawRow(2, i, inputData[i]);
		}
	}
}


long shiftRight(long input, int bits)
{
	long tmp = 0;
	if (bits > 0)
	{
		tmp = input >> bits;
	}
	else if (bits == 0)
	{
		tmp = input;
	}
	else
	{
		tmp = input << (bits * -1);
	}
	if (tmp > 0b1111111111111111111)
	{
		//tmp = 0b1111111111111111111;
		//tmp = 0; //valt buiten matrix
	}
	else if (tmp <= 0)
	{
		//tmp = 0; //valt buiten matrix
	}
	return tmp;
}

long shiftUp(long input[13], int current, int bits)
{
	int tmp = current + bits;
	if (tmp < 0)
	{
		return 0; //leds moeten van tafel verdwijnen
		//tmp = 12; 
	}
	else if (tmp > 12)
	{
		return 0;
		//tmp = 0;
	}
	else
	{
		return input[tmp];
	}
}