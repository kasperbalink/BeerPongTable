#pragma once
#include "elapsedMillis.h"

#define latchPin 12 //A0
#define clockPin 11 //A1
#define dataPin  8// A2

#define MIN 13
#define PLUS 19

void setRowData(int _column);
void drawRow(int _row);
void clearData();
