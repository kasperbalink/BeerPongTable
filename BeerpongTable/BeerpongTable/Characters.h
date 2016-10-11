#pragma once
#include "Drawing.h"
#include <stdio.h>
#include "Fields.h"


void text(int player, char textArray[], int totalTime);
void scrollingText(int player, char tekstArray[], int timeBetweenSteps);
void textByChar(int player, char textArray[], int timeBetweenSteps);
void startUpText(int player, int count);

void textNoYield(int player, char textArray[]);

long* getCharArray(char letter);
