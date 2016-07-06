#pragma once
#include "Drawing.h"

void smileyBlij(int player);
void smileyBlij(int player, int interval);
void smileyBoos(int player);
void smileyBoos(int player, int interval);
void smileyNeutraal(int player);
void smileyNeutraal(int player, int interval);

long* getSmileyBlij();
long* getSmileyNeutraal();
long* getSmileyBoos();