#pragma once
#include "Drawing.h"

void allOn(int player);
void allOn(int player, int totalTime);

void insideOn(int player);
void insideOn(int player, int totalTime);

void allOff(int player);
void allOff(int player, int totalTime);

void outsideOn(int player);
void outsideOn(int player, int totalTime);

void randomLeds(int player, int timeBetweenSteps, int totalTime);

void randomLines(int player, int countRows, int countColumns, int timeBetweenSteps, int totalTime);