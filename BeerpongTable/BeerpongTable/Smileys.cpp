#pragma once
#include "Smileys.h"

void smileyBlij()
{
	//Eyes and nose
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);
	drawRow(1);
	setRowData(9);
	drawRow(2);
	clearData();
	setRowData(9);
	drawRow(3);
	setRowData(8); setRowData(10);
	drawRow(4); drawRow(5);
	clearData();

	//Mouth
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);
	drawRow(7);
	setRowData(6); setRowData(12);
	drawRow(8);
	clearData();
	setRowData(5); setRowData(6); setRowData(7);
	setRowData(11); setRowData(12); setRowData(13);
	drawRow(9);
	clearData();
	setRowData(6); setRowData(7); setRowData(8); setRowData(9); 
	setRowData(10); setRowData(11); setRowData(12);
	drawRow(10);
	clearData();
	setRowData(7); setRowData(8); setRowData(9);
	setRowData(10); setRowData(11);
	drawRow(11);
}

void smileyBlij(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyBlij();
	}
}
void smileyBoos()
{
	//Eyes and nose
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);
	drawRow(1);
	setRowData(9);
	drawRow(2);
	clearData();
	setRowData(9);
	drawRow(3);
	setRowData(8); setRowData(10);
	drawRow(4); drawRow(5);
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);

	//Mouth
	clearData();
	setRowData(7); setRowData(8); setRowData(9);
	setRowData(10); setRowData(11);
	drawRow(7);
	setRowData(6); setRowData(12);
	drawRow(8);
	clearData();
	setRowData(5); setRowData(6); setRowData(7);
	setRowData(11); setRowData(12); setRowData(13);
	drawRow(9);
	clearData();
	setRowData(4); setRowData(5); setRowData(6);
	setRowData(12); setRowData(13); setRowData(14);
	drawRow(10);
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);
	drawRow(11);
}

void smileyBoos(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyBoos();
	}
}
void smileyNeutraal()
{
	//Eyes and nose
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);
	drawRow(1);
	setRowData(9);
	drawRow(2);
	clearData();
	setRowData(9);
	drawRow(3);
	setRowData(8); setRowData(10);
	drawRow(4); drawRow(5);
	clearData();
	setRowData(4); setRowData(5); setRowData(13); setRowData(14);

	//Mouth
	clearData();
	for (int i = 5; i <= 13; i++)
	{
		setRowData(i);
	}
	drawRow(8); drawRow(9);
}

void smileyNeutraal(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		smileyNeutraal();
	}
}