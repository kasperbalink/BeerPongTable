#pragma once
#include "Characters.h"
#include "CharacterData.h"
#define SIZE(x)  (sizeof(x) / sizeof((x)[0]))


int* text(char textArray[])
{
	int finalData[13];
	int length = SIZE(textArray);
	if (length < 4 && length > 0) //Max 3 elements
	{
		switch (length)
		{
		case 1:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] += getCharArray(textArray[0])[i];
			}
			break;
		case 2:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] += (getCharArray(textArray[0])[i] << 3);
				finalData[i] += (getCharArray(textArray[1])[i] << -3);
			}
			break;
		case 3:
			for (int i = 0; i < 13; i++)
			{
				finalData[i] += (getCharArray(textArray[0])[i] << 5);
				finalData[i] += (getCharArray(textArray[1])[i] << 0);
				finalData[i] += (getCharArray(textArray[2])[i] << -5);
			}
			break;
		}
	}
	return finalData;
}

void scrollingText(int player, char textArray[], int timeBetweenSteps)
{
	int finalData[13];
	int length = SIZE(textArray);
	while (length > 3)
	{
		for (int i = 0; i < length - 3; i++)
		{
			char tmptext[3] = { textArray[i], textArray[i + 1], textArray[i + 2] };
			elapsedMillis tempTimer;
			while (tempTimer < timeBetweenSteps)
			{
				drawTable(player, text(tmptext));
			}
		}
	}
}

int* getCharArray(char letter)
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

