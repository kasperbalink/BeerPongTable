#pragma once
#include "Drawing.h"

void smileyBlij(int player);
void smileyBlij(int player, int interval);
void smileyBoos(int player);
void smileyBoos(int player, int interval);
void smileyNeutraal(int player);
void smileyNeutraal(int player, int interval);

void smiley(int player, int smiley, int totalTime);

void smileyBoosNoYield(int player);

long* getSmileyBlij();
long* getSmileyNeutraal();
long* getSmileyBoos();
long* getSmiley(int smiley);