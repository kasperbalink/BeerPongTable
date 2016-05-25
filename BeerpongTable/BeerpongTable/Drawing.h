#pragma once
#include "elapsedMillis.h"

#define latchPin_P1 10 //LatchPin 
#define clockPin_P1 9 //ClockPin
#define dataPin_P1  8 //DataPin

#define latchPinCup_P1 10
#define clockPinCup_P1 9
#define dataPinCup_P1 8

#define latchPin_P2 26
#define clockPin_P2 24
#define dataPin_P2  22

#define latchPinCup_P2 27
#define clockPinCup_P2 25
#define dataPinCup_P2 23

#define MIN 12
#define PLUS 18


void drawLedCups(int player);
void clearCupData(int player);
void setCup(int player, int cup);
void disableCup(int player, int cup);


void setRowData(int player, int _column);
void drawRow(int player, int _row);
void clearData(int player);
void drawTable(int player, int data[]);