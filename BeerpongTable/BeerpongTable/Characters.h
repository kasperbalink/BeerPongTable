#pragma once
#include "Drawing.h"
#include <stdio.h>
#include "Fields.h"


long* text(char tekst[]);
void scrollingText(int player, char tekstArray[], int timeBetweenSteps);
long* getCharArray(char letter);
