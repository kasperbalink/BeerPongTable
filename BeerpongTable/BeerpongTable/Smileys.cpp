#pragma once
#include "Smileys.h"

void smileyBlij(int player)
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
}

void smileyBlij(int player, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyBlij(player);
	}
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

void smileyBoos(int player, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyBoos(player);
	}
}
void smileyNeutraal(int player)
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
	for (int i = 5; i <= 13; i++)
	{
		setRowData(player, i);
	}
	drawRow(player, 8); drawRow(player, 9);
}

void smileyNeutraal(int player, int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyNeutraal(player);
	}
}