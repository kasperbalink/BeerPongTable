#pragma once
#include "elapsedMillis.h"

#define latchPin_P1 12 //A0
#define clockPin_P1 11 //A1
#define dataPin_P1  8// A2

#define latchPin_P2 12 //A0
#define clockPin_P2 11 //A1
#define dataPin_P2  8// A2

#define MIN 13
#define PLUS 19

void setRowData(int _column);
void drawRow(int _row);
void clearData();



void setRowData(int _column, int player);
void drawRow(int _row, int player);
void clearData(int player);