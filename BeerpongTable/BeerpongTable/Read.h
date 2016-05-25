#pragma once
#include "Drawing.h"
#define s0 22
#define s1 24
#define s2 26
#define s3 28

#define readPinP1 A0
#define readPinP2 A1

void readCups();
bool isCup(int player, int cup);
void calculateArea(int player);
int readCup(int player, int cup); //read cup for both players

