#pragma once

#include "Characters.h"
#include "Columns.h"
#include "Fields.h"
#include "Images.h"
#include "Rows.h"
#include "Scores.h"
#include "Shapes.h"
#include "Smileys.h"




void upToDown(int size, int timeBetweenSteps);
void downToUp(int size, int timeBetweenSteps);
void leftToRight(int size, int timeBetweenSteps);
void rightToLeft(int size, int timeBetweenSteps);
void smileyBlijToBoos(int timeBetweenSteps); 
void smileyBoosToBlij(int timeBetweenSteps); 
void movingArrow(int direction, int _column, int _row, int timeBetweenSteps);