#pragma once
#include <Arduino.h>
#include "Characters.h"
#include "CharacterData.h"
//#define SIZE(x)  (sizeof(x) / sizeof((x)[0]))


void text(int player, char textArray[], int totalTime)
{
	long finalData[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int length = strlen(textArray);
	if (length < 4 && length > 0) //Max 3 elements
	{
		switch (length)
		{
		case 1:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] |= getCharArray(textArray[0])[i];
			}
			break;
		case 2:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] |= (getCharArray(textArray[0])[i] << 3);
				finalData[i] |= (getCharArray(textArray[1])[i] >> 3);
			}
			break;
		case 3:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] |= (getCharArray(textArray[0])[i] << 5);
				finalData[i] |= (getCharArray(textArray[1])[i] << 0);
				finalData[i] |= (getCharArray(textArray[2])[i] >> 5);
			}
			break;
		}
		elapsedMillis tempTimer;
		while (tempTimer < totalTime)
		{
			drawTable(player, finalData);
		}
	}
	else if (length >= 4)
	{
		scrollingText(player, textArray, 75);
	}
	
}

void startUpText(int player, int count)
{
	char charArray[] = "0";
	sprintf(charArray, "%ld", count);
	long finalData[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int length = strlen(charArray);
	switch (length)
	{
	case 1:
		for (int i = 0; i < 13; i++)
		{
			finalData[i] |= getCharArray(charArray[0])[i];
		}
		break;
	case 2:
		for (int i = 0; i < 13; i++)
		{
			finalData[i] |= (getCharArray(charArray[0])[i] << 3);
			finalData[i] |= (getCharArray(charArray[1])[i] >> 3);
		}
		break;
	}
	if (player == 1)
	{
		finalData[9] |= 0b0110000000000000000;
		finalData[10] |= 0b0110000000000000000;
	}
	else
	{
		finalData[1] |= 0b0000000000000000110;
		finalData[2] |= 0b0000000000000000110;
	}

	drawTable(player, finalData);

}

void textByChar(int player, char textArray[], int timeBetweenSteps)
{
	int length = strlen(textArray);
	for (int s = 0; s < length; s++)
	{
		long finalData[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 13; i++)
		{
			finalData[i] |= getCharArray(textArray[s])[i];
		}
		elapsedMillis tempTimer = 0;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, finalData);
		}
		allOff(player, 100);
	}
}

void scrollingText(int player, char textArray[], int timeBetweenSteps)
{
	int length = strlen(textArray);
	int shiftOriginal = 0;
	while (shiftOriginal > (length+1) * -6)
	{
		int shift = shiftOriginal;
		long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int c = 0; c < length; c++) //characters (length)
		{
			for (int i = 0; i < 13; i++) //data (13)
			{
				animation[i] |= shiftRight(getCharArray(textArray[c])[i], shift);
			}
			//shift caracter >> 6 
			shift += 6;
		}

		//draw table
		elapsedMillis tempTimer;
		while (tempTimer < timeBetweenSteps)
		{
			drawTable(player, animation);
		}

		//scroll
		shiftOriginal -= 1;
	}
}

long* getCharArray(char letter)
{
	switch (letter)
	{
	case 'a':
		return a;
		break;
	case 'b':
		return b;
		break;
	case 'c':
		return c;
		break;
	case 'd':
		return d;
		break;
	case 'e':
		return e;
		break;
	case 'f':
		return f;
		break;
	case 'g':
		return g;
		break;
	case 'h':
		return h;
		break;
	case 'i':
		return i;
		break;
	case 'j':
		return j;
		break;
	case 'k':
		return k;
		break;
	case 'l':
		return l;
		break;
	case 'm':
		return m;
		break;
	case 'n':
		return n;
		break;
	case 'o':
		return o;
		break;
	case 'p':
		return p;
		break;
	case 'q':
		return q;
		break;
	case 'r':
		return r;
		break;
	case 's':
		return s;
		break;
	case 't':
		return t;
		break;
	case 'u':
		return u;
		break;
	case 'v':
		return v;
		break;
	case 'w':
		return w;
		break;
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	case 'z':
		return z;
		break;
	case '0':
		return zero;
		break;
	case '1':
		return one;
		break;
	case '2':
		return two;
		break;
	case '3':
		return three;
		break;
	case '4':
		return four;
		break;
	case '5':
		return five;
		break;
	case '6':
		return six;
		break;
	case '7':
		return seven;
		break;
	case '8':
		return eight;
		break;
	case '9':
		return nine;
		break;
	case ' ':
		return empty;
		break;
	case '!':
		return exclamationmark;
		break;
	case '?':
		return questionmark;
		break;
	case '#':
		return hashtag;
		break;
	case '+':
		return plus;
		break;
	case '-':
		return min;
		break;
	default:
		return empty;
		break;
	}
}

