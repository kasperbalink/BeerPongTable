#pragma once
#include "Drawing.h"


#define s0 36
#define s1 38
#define s2 40
#define s3 42

#define SIG_pin_1 A0
#define SIG_pin_2 A1

//void randomLedCups(int player, int count, int interval, int timer);
void addRemoveCup(int player, int cup, int value);
void checkCups(int player);
int getScore(int player);
void drawLedScore(int player, int totalTime);
int readMux(int player, int channel);