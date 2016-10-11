#pragma once
#include "Drawing.h"

void triangle(int player, int timeBetweenSteps, int totalTime);
void fourToOne(int player, int timeBetweenSteps, int totalTime);
void oneToFour(int player, int timeBetweenSteps, int totalTime);
void randomCups(int player, int count, int timeBetweenSteps, int totalTime);
void allCupsOn(int player, int totalTime);
void allCupsOff(int player, int totalTime);
void allCupsOff(int player);
//void drawLedCupScore(int player, int cupArray[10], int totalTime);

void allCupsOnNoYield(int player);
void allCupsOffNoYield(int player);
//void drawLedCupScoreNoYield(int player, int cupArray[10]);