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
#include "Smoking.h"
#include "SleepTime.h"
using namespace std;

#define ID_LIST_FILE "c:\\data\\idlist.txt"
#define YES_NO 2

void logo();
bool login();
void signUp();
void screen();
void health();
void smoking();
void sleep();

int Health::sportTime = 0;
string Health::part = "";
time_t Health::startHour = time(NULL);
time_t Health::endHour = time(NULL);

int main()
{
	bool lRes = false;
	while (lRes == false) {
		system("cls");
		lRes = login();
	}                       
	system("cls");
	screen();

	return 0;
}

void logo() 
{
	system("mode con: cols=80 lines=25");

	string specialWord0 = "��      ��  ������   �����   ��      ������  ��      ��";
	string specialWord1 = "��      ��  ��          ��      ��  ��          ��      ��      ��";
	string specialWord2 = "������  �����    ������  ��          ��      ������";
	string specialWord3 = "��      ��  ��          ��      ��  ��          ��      ��      ��";
	string specialWord4 = "��      ��  ������  ��      ��  �����    ��      ��      ��";
	gotoXY(7, 3); 
	cout << specialWord0;
	gotoXY(7, 4); 
	cout << specialWord1;
	gotoXY(7, 5); 
	cout << specialWord2;
	gotoXY(7, 6); 
	cout << specialWord3;
	gotoXY(7, 7);
	cout << specialWord4 << endl;
	string specialWord5 = " �����   �����   �����   ������ ";
	string specialWord6 = "��         ��      ��  ��     ��  ��        ";
	string specialWord7 = "��         ������  �����   �����  ";
	string specialWord8 = "��         ��      ��  ��     ��  ��        ";
	string specialWord9 = " �����  ��      ��  ��     ��  ������ ";
	gotoXY(18, 9);
	cout << specialWord5;
	gotoXY(18, 10);
	cout << specialWord6;
	gotoXY(18, 11);
	cout << specialWord7;
	gotoXY(18, 12);
	cout << specialWord8;
	gotoXY(18, 13);
	cout << specialWord9 << endl;
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

	textColor(WHITE);
	logo();

	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
	cout << "<�α���>";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
	cout << "ID : ";
	cin >> userId;
	while (1) {
		fin.getline(serverId, sizeof(serverId), '/');
		fin.getline(serverPass, sizeof(serverPass));
		if (fin.eof()) { break; }
		if (strcmp(userId, serverId) == 0) {			// ID ������ PW �Է�
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
			cout << "PW : ";
			cin >> userPass;
			if (strcmp(userPass, serverPass) == 0) {	// ID, PW ��� ������ ���α׷� ����
				fin.close();
				return true;
			}			
			else {										// ID ���� PW �Է¿��� 
				textColor(RED);
				gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
				cout << "*��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
				textColor(WHITE);
				fin.close();
				gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 3);
				system("pause");
				return false;
			}
		}
	}													// ID ������ ����
	fin.clear();
	fin.seekg(0);
	fin.close();
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
	cout << "�ش��ϴ� ID�� �����ϴ�" << endl;
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
	cout << "�űԷ� ��� �Ͻðڽ��ϱ�?";
	
	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { "ȸ������", "�α��θ޴�" };
	int count = YES_NO;
	
	HorizontalMenu_Create(&horizontalMenu, items, count, WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 3);
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
		cout << ID_LIST_FILE << "ȸ�� ���� file open error!!" << endl;
		system("pause");
		return;
	}
	system("cls");
	textColor(WHITE);
	logo();
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
	cout << "<ȸ�� ����>";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
	cout << "ID : ";
	cin >> userId;
	while (1) {
		fin.getline(serverId, sizeof(serverId), '/');
		fin.getline(serverPass, sizeof(serverPass));
		if (fin.eof()) { break; }
		if (strcmp(userId, serverId) == 0) {		// �ߺ�ID ������
			textColor(RED);
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
			cout << "*�̹� �ִ� ID �Դϴ�." << endl;
			textColor(WHITE);
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
			system("pause");
			system("cls");
			textColor(WHITE);
			logo();
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y - 1);
			cout << "<ȸ�� ����>";
			gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
			cout << "ID : ";
			cin >> userId;
			fin.seekg(0);
		}
	}// �ߺ�ID ������
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 1);
	cout << "PW : ";
	cin >> userPass;
	fin.close();
	ofstream fout(ID_LIST_FILE, ios_base::app);
	fout << userId << '/' << userPass << endl;
	fout.close();
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 2);
	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�. ";
	gotoXY(WINDOW_LOGIN_X, WINDOW_LOGIN_Y + 3);
	system("pause");
}

void screen()
{
	VerticalMenu verticalMenu = { 0, };
	char items[MENU_COUNT][MENU_LEN] = { "[1] �ｺ ���", "[2] �ݿ� ���", "[3] ���� ���", "[4] ����"};
	int count = MENU_COUNT;
	int selMenu;
	
	while (1) {
		logo();
		VerticalMenu_Create(&verticalMenu, items, count, WINDOW_LOGIN_X, WINDOW_LOGIN_Y);
		VerticalMenu_Print(&verticalMenu);
		selMenu = VerticalMenu_ProcessKey(&verticalMenu);
		if (selMenu == MENU_COUNT - 1) {
			break;
		}
		switch (selMenu)
		{
		case 0:health(); break;
		case 1:smoking(); break;
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
	cout << "<�ｺ ���>" << endl;

	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { "� �����ϱ�", "� ��������" };
	int count = YES_NO;
	int sign;

	HorizontalMenu_Create(&horizontalMenu, items, count, 0, 2);
	HorizontalMenu_Print(&horizontalMenu);
	sign = HorizontalMenu_ProcessKey(&horizontalMenu);

	if (sign == 0)	{						//� �����ϱ� �޴�
		string part;
		string sportName;
		int setCycle;
		int line;

		now.setStartHour(time(NULL));

		// ��� ���� ǥ��(��¥, �ð�, ����)
		cout << endl << "��� ������ �Է��ϼ��� : ";
		cin >> part;
		now.setPart(part);
		now.setSTime(now.getStartHour());
		while (1) {
			system("cls");
			cout << "<�ｺ ���>" << endl;
			now.showInfo();
			// � �����

			cout << "� �̸� : ";
			cin >> sportName;
			cout << "��Ʈ�� : ";
			cin >> setCycle;
			cout << "---------------------------------------------------------------------------" << endl;
			for (int i = 0; i < setCycle; i++) {
				now.helpSport(i + 1, sportName);
				line = now.countBreakTime(i);
			}
			cout << "---------------------------------------------------------------------------" << endl;
			char sport[YES_NO][MENU_LEN] = { "� ����ϱ�", "� ����" };
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
	else {							// � �������� �޴�
		if (now.getSportTime() == 0) {
			now.setSTime(now.getStartHour());
			cout << endl;
			now.showDate();
			cout << "������ � ������ �����ϴ�." << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << endl;
			//cout << "���� �ð� �������� : " << now.getStartHour() << "���� �ð� �������� : " << now.getEndHour() << endl;  ��������Ȯ�ο� �ּ������� �ʿ� X
			now.setSTime(now.getStartHour());
			now.setETime(now.getEndHour());
			now.showInfo(now.getSportTime());
			system("pause");
			system("cls");
		}
	}
}


void smoking()
{	
	int smokingYear;
	int smokingMonth;
	int smokingDay;
	int stopYear;
	int stopMonth;
	int stopDay;
	int smokingPerDay;
	int sign;

	system("cls");

	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { " ���� ", " ������ " };
	int count = YES_NO;

	HorizontalMenu_Create(&horizontalMenu, items, count, 0, 2);
	HorizontalMenu_Print(&horizontalMenu);
	sign = HorizontalMenu_ProcessKey(&horizontalMenu);
	
	if (sign == 0) {
		cout << endl << "ù �� �ñ� (�� �� ��): ";
		cin >> smokingYear >> smokingMonth >> smokingDay;
		cout << "�Ϸ翡 ����(����) : ";
		cin >> smokingPerDay;
		Smoking smoke(smokingYear, smokingMonth, smokingDay, smokingPerDay);
		cout << "�ݿ� ���� �� (�� �� ��) : ";
		cin >> stopYear >> stopMonth >> stopDay;
		smoke.calSmokingMoney(stopYear, stopMonth, stopDay);
		cout << "����� ������ �ݾ� : " << smoke.getTotMoney() << "��" << endl;
	}
	else {
		cout << endl << "��ſ��� �� ����� �ʿ� ���� �� �����ϴ�!" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

void sleep()
{
	int h, m, sign;
	while (1) {
		system("cls");
		cout << "<������>" << endl;
		cout << "��� �ð��� �Է��ϼ��� (ex. 7��30�� -> 7 30): ";
		cin >> h >> m;
		if (cin.fail()) {
			cout << "���ڰ� �ԷµǾ� ���θ޴��� �̵��մϴ�." << endl;
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
		char items[YES_NO][MENU_LEN] = { "�ٽ� ����ϱ�", "���θ޴�" };
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