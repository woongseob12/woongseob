//콘솔창 높이 80 너비 25
#pragma warning (disable : 4996)
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
#include "VerticalMenu.h"
#include "HorizontalMenu.h"
#include "Util.h"
#include "health.h"
#include "SleepTime.h"
using namespace std;

#define ID_LIST_FILE "c:\\data\\idlist.txt"
#define YES_NO 2

bool login();
void signUp();
void screen();
void health();
void control();
void sleep();

int Health::sportTime = 0;
string Health::part = "";
time_t Health::startHour = time(NULL);
time_t Health::endHour = time(NULL);

int main()
{
	/*bool lRes = false;
	while (lRes == false) {
		system("cls");
		lRes = login();
	}*/                         //실행중 매번아이디치기귀찮아서 주석처리
	system("cls");
	screen();

	return 0;
}

bool login()
{
	ifstream fin;
	char userId[20];
	char serverId[20];
	char userPass[20];
	char serverPass[20];
	bool sign = true;

	fin.open(ID_LIST_FILE);
	if (fin.fail()) {
		cout << ID_LIST_FILE << "file open error!!" << endl;
		system("pause");
		return false;
	}

	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
	cout << "<로그인>";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
	cout << "ID : ";
	cin >> userId;
	while (1) {
		fin.getline(serverId, sizeof(serverId), '/');
		fin.getline(serverPass, sizeof(serverPass));
		if (fin.eof()) { break; }
		if (strcmp(userId, serverId) == 0) {			// ID 같으면 PW 입력
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
			cout << "PW : ";
			cin >> userPass;
			if (strcmp(userPass, serverPass) == 0) {	// ID, PW 모두 같으면 프로그램 실행
				fin.close();
				return true;
			}			
			else {										// ID 같고 PW 입력오류 
				textColor(RED);
				gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
				cout << "*비밀번호가 일치하지 않습니다." << endl;
				textColor(WHITE);
				fin.close();
				gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 3);
				system("pause");
				return false;
			}
		}
	}													// ID 같은게 없음
	fin.clear();
	fin.seekg(0);
	fin.close();
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
	cout << "해당하는 ID가 없습니다. 신규로 등록 하시겠습니까?";
	
	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { "회원가입", "메인메뉴" };
	int count = YES_NO;
	
	HorizontalMenu_Create(&horizontalMenu, items, count, WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
	HorizontalMenu_Print(&horizontalMenu);
	sign = HorizontalMenu_ProcessKey(&horizontalMenu);
	
	if (sign == 0) {
		signUp();
	}
	return false;
}

void signUp()
{
	ifstream fin;
	char userId[20];
	char serverId[20];
	char userPass[20];
	char serverPass[20];

	fin.open(ID_LIST_FILE);
	if (fin.fail()) {
		cout << ID_LIST_FILE << "회원 가입 file open error!!" << endl;
		system("pause");
		return;
	}
	system("cls");
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
	cout << "<회원 가입>";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
	cout << "ID : ";
	cin >> userId;
	while (1) {
		fin.getline(serverId, sizeof(serverId), '/');
		fin.getline(serverPass, sizeof(serverPass));
		if (fin.eof()) { break; }
		if (strcmp(userId, serverId) == 0) {		// 중복ID 있으면
			textColor(RED);
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
			cout << "*이미 있는 ID 입니다." << endl;
			textColor(WHITE);
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
			system("pause");
			system("cls");
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
			cout << "<회원 가입>";
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
			cout << "ID : ";
			cin >> userId;
			fin.seekg(0);
		}
	}// 중복ID 없으면
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
	cout << "PW : ";
	cin >> userPass;
	fin.close();
	ofstream fout(ID_LIST_FILE, ios_base::app);
	fout << userId << '/' << userPass << endl;
	fout.close();
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
	cout << "회원가입이 완료되었습니다. ";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 3);
	system("pause");
}

void screen()
{
	VerticalMenu verticalMenu = { 0, };
	char items[MENU_COUNT][MENU_LEN] = { "[1] 헬스 모드", "[2] 절제 모드", "[3] 수면 모드", "[4] 종료"};
	int count = MENU_COUNT;
	int selMenu;
	
	while (1) {
		VerticalMenu_Create(&verticalMenu, items, count, WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
		VerticalMenu_Print(&verticalMenu);
		selMenu = VerticalMenu_ProcessKey(&verticalMenu);
		if (selMenu == MENU_COUNT - 1) {
			break;
		}
		switch (selMenu)
		{
		case 0:health(); break;
		case 1:control(); break;
		case 2:sleep(); break;
		default:
			break;
		}
	}
}

void health()
{
	Health now;

	system("cls");
	cout << "<헬스 모드>" << endl;

	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { "운동 시작하기", "운동 정보보기" };
	int count = YES_NO;
	int sign;

	HorizontalMenu_Create(&horizontalMenu, items, count, 0, 2);
	HorizontalMenu_Print(&horizontalMenu);
	sign = HorizontalMenu_ProcessKey(&horizontalMenu);

	if (sign == 0)	{						//운동 시작하기 메뉴
		string part;
		string sportName;
		int setCycle;
		int line;

		now.setStartHour(time(NULL));

		// 상단 정보 표시(날짜, 시간, 부위)
		cout << endl << "운동할 부위를 입력하세요 : ";
		cin >> part;
		now.setPart(part);
		now.setSTime(now.getStartHour());
		while (1) {
			system("cls");
			cout << "<헬스 모드>" << endl;
			now.showInfo();
			// 운동 도우미

			cout << "운동 이름 : ";
			cin >> sportName;
			cout << "세트수 : ";
			cin >> setCycle;
			cout << "---------------------------------------------------------------------------" << endl;
			for (int i = 0; i < setCycle; i++) {
				now.helpSport(i + 1, sportName);
				line = now.countBreakTime(i);
			}
			cout << "---------------------------------------------------------------------------" << endl;
			char sport[YES_NO][MENU_LEN] = { "운동 계속하기", "운동 종료" };
			int count = YES_NO;
			int sel;

			HorizontalMenu_Create(&horizontalMenu, sport, count, 0, line);
			HorizontalMenu_Print(&horizontalMenu);
			sel = HorizontalMenu_ProcessKey(&horizontalMenu);
			if (sel == 1) {
				now.setEndHour(time(NULL));
				now.setSportTime((int)(now.getEndHour() - now.getStartHour()));
				system("cls");
				break;
			}
		}
	}
	else {							// 운동 정보보기 메뉴
		if (now.getSportTime() == 0) {
			now.setSTime(now.getStartHour());
			cout << endl;
			now.showDate();
			cout << "오늘의 운동 정보가 없습니다." << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << endl;
			//cout << "시작 시간 전달인자 : " << now.getStartHour() << "종료 시간 전달인자 : " << now.getEndHour() << endl;  전달인자확인용 주석해제할 필요 X
			now.setSTime(now.getStartHour());
			now.setETime(now.getEndHour());
			now.showInfo(now.getSportTime());
			system("pause");
			system("cls");
		}
	}
}

void control()
{

}

void alcohol()
{
	int num;
	char **name;
	char temp[20];

	cout << "몇명이서 마셨습니까? ";
	cin >> num;
	name = new char*[num];
	cout << "같이 마신 사람의 이름을 입력하세요" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". ";
		cin >> temp;
		name[i] = new char[strlen(temp) + 1];
		strcpy(name[i], temp);
	}
}

void sleep()
{
	int h, m, sign;
	while (1) {
		system("cls");
		cout << "<수면모드>" << endl;
		cout << "기상 시간을 입력하세요 (ex. 7시30분 -> 7 30): ";
		cin >> h >> m;
		if (cin.fail()) {
			cout << "문자가 입력되어 메인메뉴로 이동합니다." << endl;
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			return;
		}
		SleepTime wake(h, m);
		wake.show();
	
		wake.show(9.0);
		wake.show(7.5);
		wake.show(6.0);
		wake.show(4.5);


		HorizontalMenu horizontalMenu = { 0, };
		char items[YES_NO][MENU_LEN] = { "다시 계산하기", "메인메뉴" };
		int count = YES_NO;

		HorizontalMenu_Create(&horizontalMenu, items, count,1, WINDOW_LOGIN_Y + 3);
		HorizontalMenu_Print(&horizontalMenu);
		sign = HorizontalMenu_ProcessKey(&horizontalMenu);
		if (sign == 1) {
			system("cls");
			return;
		}
	}
}