#pragma once
#include "Drawing.h"
#include "Fields.h"

void logo(int player);
void logo(int player, int interval);

void thumb(int player, int totalTime);
void thumbDown(int player, int totalTime);

void pacMan(int player, int timeBetweenSteps, int totalTime);

void logo2(int player, int totalTime);

void heart(int player, int size, int totalTime);
void heartFilled(int player, int totalTime);
void heartInToOut(int player, int timeBetweenSteps, int totalTime);
void heartOutToIn(int player, int timeBetweenSteps, int totalTime);

long* getHeart(int size);

long* getLogo();
long* getPacMan(int step);

long* getThumb();
long* getThumbDown();

long* getLogo2();
