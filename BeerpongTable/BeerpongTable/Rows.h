#pragma once
#include "Drawing.h"


void row(int player, int row);
void row(int player, int row, int totalTime);
void rowBig(int player, int startRow, int endRow);
void rowBig(int player, int startRow, int endRow, int totalTime);
void rowInside(int player, int row);
void rowInside(int player, int row, int totalTime);
void rowBigInside(int player, int startRow, int endRow);
void rowBigInside(int player, int startRow, int endRow, int totalTime);

void randomRows(int player, int count, int timeBetweenSteps, int totalTime);

long* getInsideRowArray();
long* getRowArray();


