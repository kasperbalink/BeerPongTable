#pragma once
#include "Smileys.h"
#include "SmileyData.h"

//moeten deze nog?
void smileyBlij(int player)
{
	/*
	//Eyes and nose
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 1);
	setRowData(player, 9);
	drawRow(player, 2);
	clearData(player);
	setRowData(player, 9);
	drawRow(player, 3);
	setRowData(player, 8); setRowData(player, 10);
	drawRow(player, 4); drawRow(player, 5);
	clearData(player);

	//Mouth
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 7);
	setRowData(player, 6); setRowData(player, 12);
	drawRow(player, 8);
	clearData(player);
	setRowData(player, 5); setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 11); setRowData(player, 12); setRowData(player, 13);
	drawRow(player, 9);
	clearData(player);
	setRowData(player, 6); setRowData(player, 7); setRowData(player, 8); setRowData(player, 9);
	setRowData(player, 10); setRowData(player, 11); setRowData(player, 12);
	drawRow(player, 10);
	clearData(player);
	setRowData(player, 7); setRowData(player, 8); setRowData(player, 9);
	setRowData(player, 10); setRowData(player, 11);
	drawRow(player, 11);
	*/
}
void smileyBoos(int player)
{
	//Eyes and nose
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 1);
	setRowData(player, 9);
	drawRow(player, 2);
	clearData(player);
	setRowData(player, 9);
	drawRow(player, 3);
	setRowData(player, 8); setRowData(player, 10);
	drawRow(player, 4); drawRow(player, 5);
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);

	//Mouth
	clearData(player);
	setRowData(player, 7); setRowData(player, 8); setRowData(player, 9);
	setRowData(player, 10); setRowData(player, 11);
	drawRow(player, 7);
	setRowData(player, 6); setRowData(player, 12);
	drawRow(player, 8);
	clearData(player);
	setRowData(player, 5); setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 11); setRowData(player, 12); setRowData(player, 13);
	drawRow(player, 9);
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 6);
	setRowData(player, 12); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 10);
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 11);
}
void smileyNeutraal(int player)
{
	/*
	//Eyes and nose
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 1);
	setRowData(player, 9);
	drawRow(player, 2);
	clearData(player);
	setRowData(player, 9);
	drawRow(player, 3);
	setRowData(player, 8); setRowData(player, 10);
	drawRow(player, 4); drawRow(player, 5);
	clearData(player);
	setRowData(player, 4); setRowData(player, 5); setRowData(player, 13); setRowData(player, 14);

	//Mouth
	clearData(player);
	for (int i = 5; i <= 13; i++)
	{
		setRowData(player, i);
	}
	drawRow(player, 8); drawRow(player, 9);
	*/
}

void smiley(int player, int smiley, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSmiley(smiley)[i];
	}
	elapsedMillis timer;
	while (timer < totalTime)
	{
		drawTable(player, animation);
	}
}
//nieuwe manier
void smileyBlij(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSmileyBlij()[i];
	}
	drawTable(player, animation);
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}
void smileyBoos(int player, int totalTime)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSmileyBoos()[i];
	}
	drawTable(player, animation);
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

void smileyBoosNoYield(int player)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSmileyBoos()[i];
	}
	drawTableNoYield(player, animation);

}
void smileyNeutraal(int player, int totalTime)
{
	long animation[13]{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getSmileyNeutraal()[i];
	}
	drawTable(player, animation);
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

long* getSmileyBlij()
{
	return smileyBlijArray;
}

long* getSmileyNeutraal()
{
	return smileyNeutraalArray;
}

long* getSmileyBoos()
{
	return smileyBoosArray;
}

long* getSmiley(int smiley)
{
	switch (smiley)
	{
	case 1:
		return smiley1;
		break;
	case 2:
		return smiley2;
		break; 
	case 3:
		return smiley3;
		break;
	case 4:
		return smiley4;
		break;
	case 5:
		return smiley5;
		break;
	}
}