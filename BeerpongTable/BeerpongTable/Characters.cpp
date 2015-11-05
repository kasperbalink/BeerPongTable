#pragma once
#include "Characters.h"

void letter(char _letter, int _column, int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		letter(_letter, _column, _row);
	}
}

void letter(char _letter, int _column, int _row)
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

/* _number is real number 0 - 99*/
void number(int _number)
{
	number(_number, 0, 0);
}

/* _number is real number 0 - 99
interval is time to be dispaled in MS*/
void number(int _number, int interval)
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
void number(int _number, int _column, int _row)
{
	if (_number > 9 && _number < 100)
	{
		number(_number % 10, 3 + _column, _row);
		number(_number / 10, -3 + _column, _row);
	}
	else if (_number < 0 || _number > 99)
	{
		number(0);
	}
	else
	{
		switch (_number)
		{
		case 0:
			clearData();
			setRowData(7 + _column); setRowData(10 + _column);
			drawRow(8 + _row); drawRow(4 + _row); drawRow(5 + _row);
			drawRow(6 + _row); drawRow(7 + _row);
			setRowData(9 + _column); setRowData(8 + _column);
			drawRow(3 + _row); drawRow(9 + _row);
			break;
		case 1:
			clearData();
			setRowData(9 + _column); drawRow(3 + _row);
			setRowData(8 + _column); drawRow(4 + _row);
			clearData();
			setRowData(7 + _column); setRowData(9 + _column);
			drawRow(5);
			clearData();
			setRowData(9 + _column);
			drawRow(6 + _row); drawRow(7 + _row); drawRow(8 + _row);
			setRowData(7 + _column); setRowData(8 + _column); setRowData(10 + _column);
			drawRow(9 + _row);
			break;
		case 2:
			clearData();
			setRowData(7 + _column); setRowData(8 + _column);
			setRowData(9 + _column); setRowData(10 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			clearData();
			setRowData(10 + _column); drawRow(4 + _row); drawRow(5 + _row);
			clearData();
			setRowData(7 + _column); drawRow(7 + _row); drawRow(8 + _row);
			break;
		case 3:
			clearData();
			setRowData(7 + _column); setRowData(8 + _column);
			setRowData(9 + _column); setRowData(10 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			clearData();
			setRowData(10 + _column);
			drawRow(4 + _row); drawRow(5 + _row); drawRow(7 + _row); drawRow(8 + _row);
			break;
		case 4:
			clearData();
			setRowData(10 + _column);
			drawRow(7 + _row); drawRow(8 + _row); drawRow(9 + _row);
			setRowData(7 + _column);
			drawRow(3 + _row); drawRow(4 + _row); drawRow(5 + _row);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(6 + _row);
			break;
		case 5:
			clearData();
			setRowData(10 + _column); setRowData(7 + _column);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			clearData();
			setRowData(7 + _column);
			drawRow(4 + _row); drawRow(5 + _row);
			clearData();
			setRowData(10 + _column); drawRow(7 + _row); drawRow(8 + _row);
			break;
		case 6:
			clearData();
			setRowData(7 + _column);
			drawRow(4 + _row); drawRow(5 + _row);
			setRowData(10 + _column);
			drawRow(7 + _row); drawRow(8 + _row);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			break;
		case 7:
			clearData();
			setRowData(10 + _column);
			drawRow(5 + _row); drawRow(7 + _row);
			drawRow(8 + _row); drawRow(9 + _row);
			setRowData(9 + _column); setRowData(11 + _column);
			drawRow(6 + _row);
			clearData();
			setRowData(7 + _column);  setRowData(10 + _column);
			drawRow(4 + _row);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(3 + _row);
			break;
		case 8:
			clearData();
			setRowData(7 + _column); setRowData(10 + _column);
			drawRow(4 + _row); drawRow(5 + _row); drawRow(7 + _row); drawRow(8 + _row);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			break;
		case 9:
			clearData();
			setRowData(10 + _column);
			drawRow(7 + _row); drawRow(8 + _row);
			setRowData(7 + _column);
			drawRow(4 + _row); drawRow(5 + _row);
			setRowData(8 + _column); setRowData(9 + _column);
			drawRow(3 + _row); drawRow(6 + _row); drawRow(9 + _row);
			break;
		}
	}
}

/* _number is real number 0 - 99
_column is offset X, 0 = center
_row is offset Y, 0 = center
interval is time to be dispaled in MS*/
void number(int _number, int _column, int _row, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number(_number, _row, _column);
	}
}


//////////////////////////////////////////////////
////////////////////WITH PLAYER///////////////////
//////////////////////////////////////////////////


/* _number is real number 0 - 99*/
void number2(int _number, int player)
{
	number2(_number, 0, 0, player);
}

/* _number is real number 0 - 99
interval is time to be dispaled in MS*/
void number2(int _number, int interval, int player)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number2(_number, 0, 0, player);
	}
}

/* _number is real number 0 - 99
_column is offset X, 0 = center
_row is offset Y, 0 = center */
void number2(int _number, int _column, int _row, int player)
{
	if (_number > 9 && _number < 100)
	{
		number2(_number % 10, 4 + _column, _row, player);
		number2(_number / 10, -4 + _column, _row, player);
	}
	else if (_number < 0 || _number > 99)
	{
		number2(0, player);
	}
	else
	{
		switch (_number)
		{
		case 0:
			clearData(player);
			setRowData(7 + _column, player); setRowData(10 + _column, player);
			drawRow(8 + _row, player); drawRow(4 + _row, player); drawRow(5 + _row, player);
			drawRow(6 + _row, player); drawRow(7 + _row, player);
			setRowData(9 + _column, player); setRowData(8 + _column, player);
			drawRow(3 + _row, player); drawRow(9 + _row, player);
			break;
		case 1:
			clearData(player);
			setRowData(9 + _column, player); drawRow(2 + _row, player);
			setRowData(8 + _column, player); drawRow(3 + _row, player);
			clearData(player);
			setRowData(7 + _column, player); setRowData(9 + _column, player);
			clearData(player);
			setRowData(9 + _column, player);
			drawRow(5 + _row, player); drawRow(6 + _row, player); drawRow(7 + _row, player);
			setRowData(7 + _column, player); setRowData(8 + _column, player); setRowData(10 + _column, player);
			drawRow(8 + _row, player);
			break;
		case 2:
			clearData(player);
			setRowData(10 + _column, player); setRowData(7 + _column, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			clearData(player);
			setRowData(10 + _column, player); drawRow(3 + _row, player); drawRow(4 + _row, player);
			clearData(player);
			setRowData(7 + _column, player); drawRow(6 + _row, player); drawRow(7 + _row, player);
			break;
		case 3:
			clearData(player);
			setRowData(10 + _column, player); setRowData(7 + _column, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			clearData(player);
			setRowData(10 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player); drawRow(6 + _row, player); drawRow(7 + _row, player);
			break;
		case 4:
			clearData(player);
			setRowData(10 + _column, player);
			drawRow(6 + _row, player); drawRow(7 + _row, player); drawRow(8 + _row, player);
			setRowData(7 + _column, player);
			drawRow(2 + _row, player); drawRow(3 + _row, player); drawRow(4 + _row, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(5 + _row, player);
			break;
		case 5:
			clearData(player);
			setRowData(10 + _column, player); setRowData(7 + _column, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			clearData(player);
			setRowData(7 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player);
			clearData(player);
			setRowData(10 + _column, player); drawRow(7 + _row, player); drawRow(8 + _row, player);
			break;
		case 6:
			clearData(player);
			setRowData(7 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player);
			setRowData(10 + _column, player);
			drawRow(6 + _row, player); drawRow(7 + _row, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			break;
		case 7:
			clearData(player);
			setRowData(10 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player); drawRow(6 + _row, player);
			drawRow(7 + _row, player); drawRow(8 + _row, player);
			setRowData(9 + _column, player); setRowData(11 + _column, player);
			drawRow(5 + _row, player);
			clearData(player);
			setRowData(7 + _column, player);  setRowData(10 + _column, player);
			drawRow(3 + _row, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player);
			break;
		case 8:
			clearData(player);
			setRowData(7 + _column, player); setRowData(10 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player); drawRow(6 + _row, player); drawRow(7 + _row, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			break;
		case 9:
			clearData(player);
			setRowData(10 + _column, player);
			drawRow(6 + _row, player); drawRow(7 + _row, player);
			setRowData(7 + _column, player);
			drawRow(3 + _row, player); drawRow(4 + _row, player);
			setRowData(8 + _column, player); setRowData(9 + _column, player);
			drawRow(2 + _row, player); drawRow(5 + _row, player); drawRow(8 + _row, player);
			break;
		}
	}
}

/* _number is real number 0 - 99
_column is offset X, 0 = center
_row is offset Y, 0 = center
interval is time to be dispaled in MS*/
void number2(int _number, int _column, int _row, int interval, int player)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		number2(_number, _row, _column, player);
	}
}