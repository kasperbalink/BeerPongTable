#pragma once
#include "Drawing.h"
#include "Fields.h"

void logo(int player);
void logo(int player, int interval);

void pacMan(int player, int timeBetweenSteps, int totalTime);

long* getLogo();
long* getPacMan(int step);