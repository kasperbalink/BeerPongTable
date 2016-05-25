#pragma once
#include "Drawing.h"
#include <stdio.h>
#include "Fields.h"


int text(int player, char tekst[]);
int text(int player, char tekstArray[], int interval);
int scrollingText(int player, char tekstArray[], int timeBetweenSteps);
int* getArray(char letter);
