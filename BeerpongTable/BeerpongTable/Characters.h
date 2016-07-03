#pragma once
#include "Drawing.h"
#include <stdio.h>
#include "Fields.h"


int* text(char tekst[]);
void scrollingText(int player, char tekstArray[], int timeBetweenSteps);
int* getCharArray(char letter);
