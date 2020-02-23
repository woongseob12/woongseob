#include "health.h"
#include "Util.h"
#include <stdlib.h>


void Health::setStartHour(time_t currentTime)
{
	startHour = time(&currentTime);
}

time_t Health::getStartHour()
{
	return startHour;
}

void Health::setEndHour(time_t currentTime)
{
	endHour = time(&currentTime);
}

time_t Health::getEndHour()
{
	return endHour;
}

void Health::setSportTime(int useTime)
{
	sportTime = useTime;
}

int Health::getSportTime()
{
	return sportTime;
}

void Health::setPart(string temp)
{
	part = temp;
}

string Health::getPart()
{
	return part;
}

void Health::setSTime(time_t startTime)
{
	sTime = localtime(&startTime);
	sTime->tm_year += 1900;
	sTime->tm_mon += 1;
}

void Health::setETime(time_t endTime)
{
	eTime = localtime(&endTime);
	eTime->tm_year += 1900;
	eTime->tm_mon += 1;
}

void Health::showDate()
{
	cout << sTime->tm_year << "�� " << sTime->tm_mon << "�� " << sTime->tm_mday << "�� " << endl;
}

void Health::showInfo()
{
	cout << "��¥ : " << sTime->tm_year << "�� " << sTime->tm_mon << "�� " << sTime->tm_mday << "�� " << endl
	    << "���� �ð� : " << sTime->tm_hour << "�� " << sTime->tm_min << "�� " << endl
		<< "� ���� : " << part << endl;
}

void Health::showInfo(int useHour)
{
	int sTimeHourTemp;
	int sTimeMinTemp;
	int useTime = useHour / 60;
	sTimeMinTemp = eTime->tm_min - useTime;
	sTimeHourTemp = eTime->tm_hour;
	while (sTimeMinTemp < 0) {
		sTimeMinTemp += 60;
		sTimeHourTemp -= 1;
	}
	if (sTimeHourTemp < 0) {
		sTimeHourTemp += 24;
	}


	cout << "��¥ : " << sTime->tm_year << "�� " << sTime->tm_mon << "�� " << sTime->tm_mday << "�� " << endl
		//    << "���� �ð� : " << sTime->tm_hour << "�� " << sTime->tm_min << "�� " << endl
		<< "���� �ð� : " << sTimeHourTemp << "�� " << sTimeMinTemp << "�� " << endl	// �ӽ� �ذ�å
		<< "���� �ð� : " << eTime->tm_hour << "�� " << eTime->tm_min << "�� " << endl
		<< "� ���� : " << part << endl
		<< "� �ð� : " << useHour/60 << "��" << endl;
}

int Health::countBreakTime(int setCycleI)
{
	int breakTime;
	int lineNum;
	cout << "�޽� �� �ð��� �Է��ϼ���(��) : ";
	cin >> breakTime;
	for (int i = 0; i < breakTime; i++) {
		gotoXY(0, WINDOW_HEALTH_Y + setCycleI * 3);
		cout << i + 1;
		Sleep(1000);
	}
	gotoXY(0, WINDOW_HEALTH_Y + setCycleI * 3);
	cout << "�޽Ľð� ��!!" << endl;
	lineNum = WINDOW_HEALTH_Y + setCycleI * 3 + 2;

	return lineNum;
}

void Health::helpSport(int i, string sportName)
{
	cout << i << "ȸ�� : " << sportName << " (" << part << " �)" << endl;
}

