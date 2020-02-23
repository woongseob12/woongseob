#pragma once;
#pragma warning (disable : 4996)

#include <Windows.h>
#include <iostream>

#define FONT_COLOR_SIZE 16
#define WINDOW_LOGIN_X 20
#define WINDOW_LOGIN_Y 12
#define CURSOR_SIZE 30
#define BLACK 0
#define RED 4
#define WHITE 15
#define WHITE_INVERSION 240

using namespace std;


void gotoXY(int , int);
void CursorUtil_Show();
void CursorUtil_Hide();
void textColor(int);
void ScreenUtil_ClearRectangle(int leftTopX, int leftTopY, int width, int height);
