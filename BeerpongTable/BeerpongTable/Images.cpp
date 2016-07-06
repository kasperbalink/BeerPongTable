#pragma once
#include "Images.h"
#include "ImagesData.h"

void logo(int player)
{	
	/*
	clearData(player);
	setRowData(player, 6); setRowData(player, 7); setRowData(player, 10); setRowData(player, 11);
	setRowData(player, 12); setRowData(player, 13); setRowData(player, 14); setRowData(player, 15);
	setRowData(player, 16);
	drawRow(player, 3);
	setRowData(player, 9); setRowData(player, 2);
	drawRow(player, 4);
	clearData(player);
	setRowData(player, 2); setRowData(player, 3); setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 8); setRowData(player, 9); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 5); 
	setRowData(player, 4);
	drawRow(player, 6);
	clearData(player);
	setRowData(player, 2); setRowData(player, 3); setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 9); setRowData(player, 10); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 7);
	clearData(player);
	setRowData(player, 2); setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 10); setRowData(player, 11); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 8);
	clearData(player);
	setRowData(player, 6); setRowData(player, 7);
	setRowData(player, 11); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 8);
	clearData(player);
	setRowData(player, 6); setRowData(player, 7); setRowData(player, 11);  setRowData(player, 12); setRowData(player, 13); setRowData(player, 14);
	drawRow(player, 9);
	*/
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getLogo()[i];
	}
	drawTable(player, animation);
}

void logo(int player, int totalTime)
{
	long animation[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		animation[i] |= getLogo()[i];
	}
	elapsedMillis tempTimer;
	while (tempTimer < totalTime)
	{
		drawTable(player, animation);
	}
}

long* getLogo()
{
	return logoArray;
}