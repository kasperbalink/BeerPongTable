#pragma once

#include "Characters.h"
#include "Columns.h"
#include "Fields.h"
#include "Images.h"
#include "Rows.h"
#include "Scores.h"
#include "Shapes.h"
#include "Smileys.h"



void testAnimation();
void ballAnimation();

void upToDown(int player, int size, int timeBetweenSteps);
void downToUp(int player, int size, int timeBetweenSteps);
void leftToRight(int player, int size, int timeBetweenSteps);
void rightToLeft(int player, int size, int timeBetweenSteps);
void smileyBlijToBoos(int player, int timeBetweenSteps);
void smileyBoosToBlij(int player, int timeBetweenSteps);
void movingArrow(int player, int direction, int _column, int _row, int timeBetweenSteps);


int shiftRight(int input, int bits);
void shiftUp(int input[13], int bits);
void clearArray(int inputArray[13]);