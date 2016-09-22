#pragma once
#include "Scores.h"



/*Deze methode laat de score van de speler zien. Count is aantal cups bij andere speler.*/
void showScoreFromPlayer(int player, int count, int totalTime)
{
	char charArray[] = "0";
	if (player == 1)
	{
		int score = 10 - count;
		sprintf(charArray, "%ld", score);
	}
	else if (player == 2)
	{
		int score = 10 - count;
		sprintf(charArray, "%ld", score);
	}
	text(player, charArray, 2000);
}

void showCountFromPlayer(int player, int count, int totalTime)
{
	char charArray[] = "0";
	if (player == 1)
	{		
		sprintf(charArray, "%ld", count);
	}
	else if (player == 2)
	{
		int score = 10 - count;
		sprintf(charArray, "%ld", count);
	}
	text(player, charArray, 2000);
}