#pragma once
#include "Drawing.h"
//characters
void letter(char _letter, int _column, int _row, int interval);
void letter(char _letter, int _column, int _row);

void number(int _number);
void number(int _number, int interval);
void number(int _number, int _column, int _row);
void number(int _number, int _column, int _row, int interval);

void number2(int _number, int player);
void number2(int _number, int interval, int player);
void number2(int _number, int _column, int _row, int player);
void number2(int _number, int _column, int _row, int interval, int player);