#pragma once
#include "elapsedMillis.h"
#include "IR.h"

#define latchPin_P1 12 //LatchPin 
#define clockPin_P1 11 //ClockPin
#define dataPin_P1  8 //DataPin

#define latchPin_P2 12 //A0
#define clockPin_P2 11 //A1
#define dataPin_P2  8// A2

#define MIN 12
#define PLUS 18


int setRowData(int _column);
void setRealRowData(long value);
void drawRow(int _row);
void clearData();



void setRowData(int _column, int player);
void drawRow(int _row, int player);
void clearData(int player);