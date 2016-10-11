#pragma once

#include "Drawing.h"



void column(int player, int column);
void column(int player, int column, int totalTime);
void columnBig(int player, int starColumn, int endColumn);
void columnBig(int player, int starColumn, int endColumn, int totalTime);

void columnInside(int player, int column);
void columnInside(int player, int column, int totalTime);
void columnBigInside(int player, int startColumn, int endColumn);
void columnBigInside(int player, int startColumn, int endColumn, int totalTime);

void randomColumn(int player, int count, int timeBetweenSteps, int totalTime);

long* getColumnArray();
long* getInsideColumnArray();