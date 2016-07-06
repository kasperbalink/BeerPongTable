#pragma once
#include "elapsedMillis.h"
#define dataPin_P1  22 //DataPin
#define clockPin_P1 24 //ClockPin
#define latchPin_P1 26 //LatchPin 

#define dataPinCup_P1 28
#define clockPinCup_P1 30
#define latchPinCup_P1 32


#define dataPin_P2  23
#define clockPin_P2 25
#define latchPin_P2 27

#define dataPinCup_P2 29
#define clockPinCup_P2 31
#define latchPinCup_P2 33

#define MIN 12
#define PLUS 18

void drawLedCups(int player);
void clearCupData(int player);
int addCup(int player, int cup);
int removeCup(int player, int cup);

void setRawRowData(int player, int data);

void drawRow(int player, int _row, long inputdata);
void setRowData(int player, int _column);
void drawRow(int player, int _row);
void clearData(int player);
void drawTable(int player, long data[]);


long shiftRight(long input, int bits);
long shiftUp(long input[13], int current, int bits);