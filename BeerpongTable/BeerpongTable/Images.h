#pragma once
#include "Drawing.h"
#include "Fields.h"

void logo(int player);
void logo(int player, int interval);

void thumb(int player, int totalTime);
void thumbDown(int player, int totalTime);

void pacMan(int player, int timeBetweenSteps, int totalTime);

void logo2(int player, int totalTime);

long* getLogo();
long* getPacMan(int step);

long* getThumb();
long* getThumbDown();

long* getLogo2();
