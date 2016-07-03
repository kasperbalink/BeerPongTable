#pragma once
#include "Drawing.h"


#define s0 36
#define s1 38
#define s2 40
#define s3 42

#define SIG_pin_1 A0
#define SIG_pin_2 A1

void checkCups();
int readMux(int player, int channel);