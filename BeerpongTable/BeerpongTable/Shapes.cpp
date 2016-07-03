#pragma once
#include "Shapes.h"
#include "ShapeData.h"



int* getSquareArray(int size)
{
	switch (size)
	{
	case 1:
		return square1;
		break;
	case 2:
		return square2;
		break;
	case 3:
		return square3;
		break;
	case 4:
		return square4;
		break;
	case 5:
		return square5;
		break;
	case 6:
		return square6;
		break;
	case 7:
		return square7;
		break;
	default:
		break;
	}
}

int* getBallArray(int size)
{
	switch (size)
	{
	case 1:
		return ball1;
		break;
	case 2:
		return ball2;
		break;
	default:
		break;
	}
}