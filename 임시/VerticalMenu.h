#ifndef _VERTICAL_MENU_H
#define _VERTICAL_MENU_H
#include "Point.h"

#define ITEMS_COUNT 20
#define ITEMS_CONTENT_SIZE 128

typedef struct _verticalMenu {
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE];
	int count;
	int selectedIndex;
	Point startPositionToPrint;
}VerticalMenu;

void VerticalMenu_Create(VerticalMenu* verticalMenu, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint);
void VerticalMenu_Print(VerticalMenu* verticalMenu);
int VerticalMenu_ProcessKey(VerticalMenu* verticalMenu);
const char* VerticalMenu_GetSelectedContent(VerticalMenu* verticalMenu);

#endif