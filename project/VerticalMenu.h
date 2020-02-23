#pragma once
#include "Point.h"
#define MENU_COUNT 4
#define MENU_LEN 50

typedef struct _verticalMenu {
	char items[MENU_COUNT][MENU_LEN];
	int count;
	int selMenu;
	Point menuCursor;
}VerticalMenu;

void VerticalMenu_Create(VerticalMenu* verticalMenu, char(*items)[MENU_LEN], int count, int cursorX, int cursorY);
void VerticalMenu_Print(VerticalMenu* verticalMenu);
int VerticalMenu_ProcessKey(VerticalMenu* verticalMenu);
const char* VerticalMenu_GetSelectedContent(VerticalMenu* verticalMenu);
