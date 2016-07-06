#pragma once
#include "Drawing.h"
//SHAPES
//int* square_(int player, int size, int interval);
//void bracket(int player, int direction, int x, int y);
//void arrow(int player, int direction, int _column, int _row, int interval);
//void arrow(int player, int direction, int _column, int _row);
long* getSquareArray(int size);
long* getBallArray(int size);
long* getBracketLeft();
long* getBracketRight();
long* getArrowUp();
long* getArrowDown();
long* getArrowLeft();
long* getArrowRight();

void arrowLeft(int player, int timeBetweenSteps);
void arrowRight(int player, int timeBetweenSteps);
void arrowUp(int player, int timeBetweenSteps);
void arrowDown(int player, int timeBetweenSteps);
void square_(int player, int size, int totalTime);