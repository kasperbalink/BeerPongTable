#pragma once
#include "Scores.h"



/*Deze methode laat de score van de speler zien. Count is aantal cups bij andere speler.*/
void showScoreFromPlayer(int player, int count, int totalTime)
{
	int time = totalTime;
	char charArray[] = "0";
	
	if (player == 1)
	{
		int score = 10 - count;
		sprintf(charArray, "%ld", score);
		/*if (score == 10)
		{
			sprintf(charArray, "%ld", "WIN");
			time = 60000;
		}*/
	}
	else if (player == 2)
	{
		int score = 10 - count;
		sprintf(charArray, "%ld", score);
		/*if (score == 10)
		{
			sprintf(charArray, "%ld", "WIN");
			time = 60000;
		}*/
	}
	text(player, charArray, time);
}

void showScoreFromPlayerNoYield(int player, int count)
{
	char charArray[] = "0";

		int score = 10 - count;
		if (score == 10)
		{
			char winArray[] = "win";
			if (player == 1)
			{
				textNoYield(player, winArray);
				smileyBoosNoYield(2);
			}
			else if(player == 2)
			{
				textNoYield(player, winArray);
				smileyBoosNoYield(1);
			}
		}
		else
		{
			sprintf(charArray, "%ld", score);
			textNoYield(player, charArray);
		}
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
	text(player, charArray, totalTime);
}