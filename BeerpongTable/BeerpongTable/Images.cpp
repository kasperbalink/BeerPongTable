#pragma once
#include "Images.h"
#include "Rows.h"
#include "Columns.h"

void logo()
{
	
	row(0);
	row(12);
	clearData();
	setRowData(6); setRowData(7); setRowData(10); setRowData(11);
	setRowData(12); setRowData(13); setRowData(14); setRowData(15);
	setRowData(16);
	drawRow(3);
	setRowData(9); setRowData(2);
	drawRow(4);
	clearData();
	setRowData(2); setRowData(3); setRowData(6); setRowData(7);
	setRowData(8); setRowData(9); setRowData(13); setRowData(14);
	drawRow(5); 
	setRowData(4);
	drawRow(6);
	clearData();
	setRowData(2); setRowData(3); setRowData(6); setRowData(7);
	setRowData(9); setRowData(10); setRowData(13); setRowData(14);
	drawRow(7);
	clearData();
	setRowData(2); setRowData(6); setRowData(7);
	setRowData(10); setRowData(11); setRowData(13); setRowData(14);
	drawRow(8);
	clearData();
	setRowData(6); setRowData(7);
	setRowData(11); setRowData(13); setRowData(14);
	drawRow(8);
	clearData();
	setRowData(6); setRowData(7); setRowData(11);  setRowData(12); setRowData(13); setRowData(14);
	drawRow(9);
}

void logo(int interval)
{
	elapsedMillis tempTimer;
	while (tempTimer < interval)
	{
		logo();
	}
}