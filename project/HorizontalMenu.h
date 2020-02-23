#pragma once
#include "Point.h"
#define MENU_COUNT 4
#define MENU_LEN 50

typedef struct _horizontalMenu {
	char items[MENU_COUNT][MENU_LEN];
	int count;
	int selectedIndex;
	Point menuCursor;
}HorizontalMenu;

void HorizontalMenu_Create(HorizontalMenu* horizontalMenu, char(*items)[MENU_LEN], int count, int startPositionXToPrint, int startPositionYToPrint);
void HorizontalMenu_Print(HorizontalMenu* horizontalMenu);
int HorizontalMenu_ProcessKey(HorizontalMenu* horizontalMenu);
const char* HorizontalMenu_GetSelectedContent(HorizontalMenu* horizontalMenu);
