#include "Util.h"

void gotoXY(int x, int y) {
	COORD pos = {(SHORT) x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorUtil_Show() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = true;
	cursorInfo.dwSize = CURSOR_SIZE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void CursorUtil_Hide() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void textColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ScreenUtil_ClearRectangle(int leftTopX, int leftTopY, int width, int height) {
	gotoXY(leftTopX, leftTopY++);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << " ";
		}
		gotoXY(leftTopX, leftTopY++);
	}
}