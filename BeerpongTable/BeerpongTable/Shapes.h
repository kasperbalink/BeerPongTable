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
long* getCircle(int size);
long* getDiagonalRighUp();
long* getDiagonalLeftUp();

void circleInOut(int player, int timeBetweenSteps, int totalTime);
void circleOutIn(int player, int timeBetweenSteps, int totalTime);

void arrowLeft(int player, int timeBetweenSteps, int totalTime);
void arrowRight(int player, int timeBetweenSteps, int totalTime);

void arrowUp(int player, int timeBetweenSteps, int totalTime);
void arrowDown(int player, int timeBetweenSteps, int totalTime);

void bracketLeft(int player, int count, int timeBetweenSteps, int totalTime);
void bracketRight(int player, int count, int timeBetweenSteps, int totalTime);

void diagonalLeftUpRight(int player, int size, int count, int timeBetweenSteps, int totalTime);


void square_(int player, int size, int totalTime);