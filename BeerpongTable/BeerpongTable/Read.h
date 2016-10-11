#pragma once
#include "Drawing.h"


#define s0 36
#define s1 38
#define s2 40
#define s3 42

#define SIG_pin_1 A0
#define SIG_pin_2 A1

void calibrateSensors();
bool isCalibrated();

void addRemoveCup(int player, int cup, int value);
void checkCups(int player);
int getCups(int player);
void drawLedScore(int player, int totalTime);
int readMux(int player, int channel);

void addRemoveCupNoYield(int player, int cup, int value);
void checkCupsNoYield(int player);
int getCupsNoYield(int player);
void drawLedScoreNoYield(int player);
int readMuxNoYield(int player, int channel);

bool isScored();
void setScored();

//int* getScoreArray(int player);

