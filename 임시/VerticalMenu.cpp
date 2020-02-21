#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "VerticalMenu.h"
#include "Util.h"

enum KeyCode {
	ENTER = 13, UP = 72, DOWN = 80
};

enum Boolean {
	False, True
};

void VerticalMenu_Create(VerticalMenu* verticalMenu, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint) {
	int i;
	for (i = 0; i < count; i++) {
		strcpy(verticalMenu->items[i], items[i]);
	}
	verticalMenu->count = count;
	verticalMenu->selectedIndex = 0;
	verticalMenu->startPositionToPrint.x = startPositionXToPrint;
	verticalMenu->startPositionToPrint.y = startPositionYToPrint;
}

void VerticalMenu_Print(VerticalMenu* verticalMenu) {
	int i;
	Point startPositionToPrint = verticalMenu->startPositionToPrint;
	CursorUtil_Hide();
	for (i = 0; i < verticalMenu->count; i++) {
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
		if (i == verticalMenu->selectedIndex) {
			FontUtil_ChangeFontColor(WHITE_INVERSION);
		}
		else {
			FontUtil_ChangeFontColor(WHITE);
		}
		printf("%s", verticalMenu->items[i]);
	}
	FontUtil_ChangeFontColor(WHITE);
}

int VerticalMenu_ProcessKey(VerticalMenu* verticalMenu) {
	while (True) {
		if (_kbhit()) {
			int key = _getch();
			if (key == ENTER) {
				break;
			}
			switch (key) {
			case 0xE0:
				if (_kbhit()) {
					switch (_getch()) {
					case UP:
						verticalMenu->selectedIndex = (verticalMenu->selectedIndex - 1 + verticalMenu->count) % verticalMenu->count;
						VerticalMenu_Print(verticalMenu);
						break;
					case DOWN:
						verticalMenu->selectedIndex = (verticalMenu->selectedIndex + 1) % verticalMenu->count;
						VerticalMenu_Print(verticalMenu);
						break;
					}
				}
				break;
			}
		}
	}
	return verticalMenu->selectedIndex;
}

const char* VerticalMenu_GetSelectedContent(VerticalMenu* verticalMenu) {
	return verticalMenu->items[verticalMenu->selectedIndex];
}