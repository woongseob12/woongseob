//�ܼ�â ���� 80 �ʺ� 25
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
	}*/                         //������ �Ź����̵�ġ������Ƽ� �ּ�ó��
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
	cout << "�ش��ϴ� ID�� �����ϴ�. �űԷ� ��� �Ͻðڽ��ϱ�?";
	
	HorizontalMenu horizontalMenu = { 0, };
	char items[YES_NO][MENU_LEN] = { "ȸ������", "���θ޴�" };
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
		cout << ID_LIST_FILE << "ȸ�� ���� file open error!!" << endl;
		system("pause");
		return;
	}
	system("cls");
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
	char items[MENU_COUNT][MENU_LEN] = { "[1] �ｺ ���", "[2] ���� ���", "[3] ���� ���", "[4] ����"};
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

void control()
{

}

void alcohol()
{
	int num;
	char **name;
	char temp[20];

	cout << "����̼� ���̽��ϱ�? ";
	cin >> num;
	name = new char*[num];
	cout << "���� ���� ����� �̸��� �Է��ϼ���" << endl;
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