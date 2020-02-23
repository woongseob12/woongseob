#pragma warning (disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "VerticalMenu.h"
#include "Util.h"

enum KeyCode {
	ENTER = 13, UP = 72, DOWN = 80
};

void VerticalMenu_Create(VerticalMenu* verticalMenu, char(*items)[MENU_LEN], int count, int cursorX, int cursorY) {
	int i;
	for (i = 0; i < count; i++) {
		strcpy(verticalMenu->items[i], items[i]);
	}
	verticalMenu->count = count;
	verticalMenu->selMenu = 0;
	verticalMenu->menuCursor.x = cursorX;
	verticalMenu->menuCursor.y = cursorY;
}

void VerticalMenu_Print(VerticalMenu* verticalMenu) {
	int i;
	Point menuCursor = verticalMenu->menuCursor;
	CursorUtil_Hide();
	for (i = 0; i < verticalMenu->count; i++) {
		gotoXY(menuCursor.x, menuCursor.y++);
		if (i == verticalMenu->selMenu) {
			textColor(WHITE_INVERSION);
		}
		else {
			textColor(WHITE);
		}
		printf("%s", verticalMenu->items[i]);
	}
	textColor(WHITE);
}

int VerticalMenu_ProcessKey(VerticalMenu* verticalMenu) {
	while (true) {
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
						verticalMenu->selMenu = (verticalMenu->selMenu - 1 + verticalMenu->count) % verticalMenu->count;
						VerticalMenu_Print(verticalMenu);
						break;
					case DOWN:
						verticalMenu->selMenu = (verticalMenu->selMenu + 1) % verticalMenu->count;
						VerticalMenu_Print(verticalMenu);
						break;
					}
				}
				break;
			}
		}
	}
	return verticalMenu->selMenu;
}

const char* VerticalMenu_GetSelectedContent(VerticalMenu* verticalMenu) {
	return verticalMenu->items[verticalMenu->selMenu];
}