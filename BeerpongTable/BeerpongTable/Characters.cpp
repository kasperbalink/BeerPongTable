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


// @TODO: kolommen en rijen toevoegen aan de positie, speler toevoegen...
void letter(char _letter, int _column, int _row)
{
	clearData();

	switch (tolower(_letter))
	{
	
	case 'a':
		setRowData(9 + _column);
		drawRow(_row + 3);
		clearData();
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 4);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 5); drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 6);
		
		
		break;
	case 'b':
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 6); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 7); drawRow(_row + 8);
		break;

	case 'c':
		setRowData(_column + 7);
		drawRow(_row + 5); drawRow(_row + 6); drawRow(_row + 7);
		setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 8);
		clearData(); 
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 9);
		break;

	case 'd':
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8);
		break;

	case 'e':
		setRowData(_column + 7);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 7); drawRow(_row + 8);
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 6); drawRow(_row + 9);
		break;

	case 'f':
		setRowData(_column + 7);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); drawRow(_row + 9);
		drawRow(_row + 6);
		setRowData(_column + 10);
		drawRow(_row + 3);
		break;

	case 'g':
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7);
		drawRow(_row + 4); drawRow(_row + 5);
		setRowData(_column + 11);
		drawRow(_row + 7); drawRow(_row + 8);
		clearData();
		setRowData(_column + 7); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 6);
		break;

	case 'h':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 5);
		drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 6);
		break;
	case 'i':
		setRowData(_column + 9);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6); 
		drawRow(_row + 7); drawRow(_row + 8);
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 9);
		break;
	case 'j':
		setRowData(_column + 9);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6);
		setRowData(_column + 8);
		drawRow(_row + 9);
		setRowData(_column + 10);
		drawRow(_row + 3);
		clearData();
		setRowData(_column + 9); setRowData(_column + 7);
		drawRow(_row + 7); drawRow(_row + 8);
		break;
	case 'k':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 10);
		drawRow(_row + 4); drawRow(_row + 8);
		clearData();
		setRowData(_column + 7); setRowData(_column + 9);
		drawRow(_row + 5); drawRow(_row + 7);
		clearData();
		setRowData(_column + 7); setRowData(_column + 8);
		drawRow(_row + 6);
		break;
	case 'l':
		setRowData(_column + 7);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 5);
		drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8);
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10); setRowData(_column + 11);
		drawRow(_row + 9);
		break;
	case 'm':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 4);
		clearData();
		setRowData(_column + 7); setRowData(_column + 9); setRowData(_column + 11);
		drawRow(_row + 5);
		break;
	case 'n':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); 
		drawRow(_row + 5);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11); setRowData(_column + 9);
		drawRow(_row + 6);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11); setRowData(_column + 10);
		drawRow(_row + 7);
		break;
	case 'o':
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8);
		break;
	case 'p':
		setRowData(_column + 7);
		drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 6);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5);
		break;
	case 'q':
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3);
		setRowData(_column + 11); 
		drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11); setRowData(_column + 9);
		drawRow(_row + 7); 
		clearData();
		setRowData(_column + 7); setRowData(_column + 11); setRowData(_column + 10);
		drawRow(_row + 8);
		clearData();
		setRowData(_column + 12);
		drawRow(_row + 10);
		break;
	case 'r':
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 3); drawRow(_row + 6);
		clearData();
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 9);
		clearData();
		setRowData(_column + 7); setRowData(_column + 9);
		drawRow(_row + 7);
		clearData();
		setRowData(_column + 7); setRowData(_column + 10);
		drawRow(_row + 8);
		break;
	case 's':
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 6);
		setRowData(_column + 11);
		drawRow(_row + 3);
		clearData();
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 9);
		clearData();
		setRowData(_column + 7);
		drawRow(_row + 4); drawRow(_row + 5);
		clearData();
		setRowData(_column + 11);
		drawRow(_row + 7); drawRow(_row + 8);
		break;
	case 't':
		setRowData(_column + 9);
		drawRow(_row + 4); drawRow(_row + 5); drawRow(_row + 6);
		drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 10); setRowData(_column + 11);
		drawRow(_row + 3);
		break;
	case 'u':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 5); 
		drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8);
		clearData();
		setRowData(_column + 8); setRowData(_column + 9); setRowData(_column + 10);
		drawRow(_row + 9);
		break;
	case 'v':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 5);
		drawRow(_row + 6); drawRow(_row + 7); 
		clearData();
		setRowData(_column + 8); setRowData(_column + 10); 
		drawRow(_row + 8);
		clearData();
		setRowData(_column + 9); 
		drawRow(_row + 9);
		break;
	case 'w':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 5);
		drawRow(_row + 6); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 8);
		clearData();
		setRowData(_column + 7); setRowData(_column + 9); setRowData(_column + 11);
		drawRow(_row + 7);
		break;
	case 'x':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4); drawRow(_row + 8);	drawRow(_row + 9);
		clearData();
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 5); drawRow(_row + 7);
		clearData(); 
		setRowData(_column + 9);
		drawRow(_row + 6);
		break;
	case 'y':
		setRowData(_column + 7); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 4);
		clearData();
		setRowData(_column + 9);
		drawRow(_row + 6); drawRow(_row + 7); drawRow(_row + 8); drawRow(_row + 9);
		setRowData(_column + 8); setRowData(_column + 10);
		drawRow(_row + 5);
		break;
	case 'z':
		setRowData(_column + 7); setRowData(_column + 8); setRowData(_column + 9); 
		setRowData(_column + 10); setRowData(_column + 11);
		drawRow(_row + 3); drawRow(_row + 9);
		clearData(); setRowData(_column + 11); drawRow(_row + 4);
		clearData(); setRowData(_column + 10); drawRow(_row + 5);
		clearData(); setRowData(_column + 9); drawRow(_row + 6);
		clearData(); setRowData(_column + 8); drawRow(_row + 7);
		clearData(); setRowData(_column + 7); drawRow(_row + 8);
		break;
	case ' ':
		//SPATIE
		break;
	case '!':
		setRowData(8 + _column); setRowData(9 + _column);
		drawRow(3 + _row); drawRow(4 + _row); drawRow(5 + _row);
		drawRow(6 + _row); drawRow(8 + _row); drawRow(9 + _row);
		break;
	case '?':
		setRowData(9 + _column);
		drawRow(9 + _row); drawRow(8 + _row); drawRow(7 + _row);
		setRowData(8 + _column); setRowData(10 + _column);
		drawRow(3 + _row);
		clearData();
		setRowData(7 + _column); setRowData(11 + _column);
		drawRow(4 + _row); drawRow(5 + _row);
		clearData();
		setRowData(10 + _column);
		drawRow(6 + _row);
		break;
	case '#':
		setRowData(8 + _column); setRowData(10 + _column);
		drawRow(3 + _row); drawRow(4 + _row); drawRow(6 + _row);
		drawRow(8 + _row); drawRow(9 + _row);
		setRowData(7 + _column); setRowData(9 + _column); setRowData(11 + _column);
		drawRow(5 + _row); drawRow(7 + _row);
		break;

	case '+':
		setRowData(9 + _column);
		drawRow(4 + _row); 	drawRow(5 + _row); 
		drawRow(7 + _row);	drawRow(8 + _row);
		setRowData(7 + _column); setRowData(8 + _column);
		setRowData(10 + _column); setRowData(11 + _column);
		drawRow(6 + _row);
		break;
	case '-':
		setRowData(7 + _column); setRowData(8 + _column); setRowData(9 + _column);
		setRowData(10 + _column); setRowData(11 + _column);
		drawRow(6 + _row);
		break;
	default:
		break;
	}
}
//A (size = 1)
//ABC (size = 3)

void text(char _text[999], int scrollTime)
{

	int size = 0;
	for (int i = 0; i < 999; i++)
	{
		if (_text[i] == 0)
		{
			size = i;
		}
		break;
	}
	if (size == 3)
	{
		textOffThree(_text[0], _text[1], _text[2], scrollTime);
	}
	else if (size == 2)
	{
		textOffTwo(_text[0], _text[1], scrollTime);
	}
	else if (size == 1)
	{
		letter(_text[0], 0, 0, scrollTime);
	}
	else if (size > 3)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				textOffThree(_text[i], ' ', ' ', scrollTime);
			}
			else if (i == size - 2)
			{
				textOffThree(_text[i], _text[i + 1], ' ', scrollTime);
			}
			else
			{
				textOffThree(_text[i], _text[i + 1], _text[i + 2], scrollTime);
			}
		}
	}

}

void textOffTwo(char a, char b, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		letter(a, -6, 0);
		letter(b, 0, 0);
	}
}

void textOffThree(char a, char b, char c, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		letter(a, -6, 0);
		letter(b, 0, 0);
		letter(c, 6, 0);
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