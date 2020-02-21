#pragma warning (disable : 4996)
#define MENU_CNT 4
#define WINDOW_X 50
#define WINDOW_TOP 10
#define WINDOW_MID 20
#define WINDOW_BOT 30
#define ITEMS_COUNT 20
#define ITEMS_CONTENT_SIZE 128

#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "VerticalMenu.h"
using namespace std;

void gotoxy(int, int);
void login;
void screen();


int main() {
	//login();
	screen();
	return 0;
}

void login()
{

}

void gotoxy(int x, int y)
{
	COORD Pos = { (SHORT)x - 1, (SHORT)y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void screen()
{
	VerticalMenu verticalMenu = { 0, };
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE] = { "[1] 헬스 모드", "[2] 금욕 모드", "[3] 수면 모드", "[4] 종료", };
	int count = MENU_CNT;
	int startPositionXToPrint = WINDOW_X;
	int startPositionYToPrint = WINDOW_MID;
	int selectedIndex;
	string name;

	VerticalMenu_Create(&verticalMenu, items, count, startPositionXToPrint, startPositionYToPrint);
	VerticalMenu_Print(&verticalMenu);
	selectedIndex = VerticalMenu_ProcessKey(&verticalMenu);
	printf("\n\n선택된 메뉴 내용 : %s\n", VerticalMenu_GetSelectedContent(&verticalMenu));

	switch (selectedIndex)
	{
	case 1:break;
	case 2:break;
	case 3:break;

	default:
		break;
	}
}