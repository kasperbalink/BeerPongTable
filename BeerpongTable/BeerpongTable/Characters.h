#pragma once
#include "Drawing.h"
#include <stdio.h>
//characters
void letter(char _letter, int _column, int _row, int interval);
void letter(char _letter, int _column, int _row);


void textOffTwo(char a, char b, int interval);
void textOffThree(char a, char b, char c, int interval);
void text(char text[999], int scrollTime);


void number(int _number);
void number(int _number, int interval);
void number(int _number, int _column, int _row);
void number(int _number, int _column, int _row, int interval);

void number2(int _number, int player);
void number2(int _number, int interval, int player);
void number2(int _number, int _column, int _row, int player);
void number2(int _number, int _column, int _row, int interval, int player);