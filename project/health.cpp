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
	cout << sTime->tm_year << "년 " << sTime->tm_mon << "월 " << sTime->tm_mday << "일 " << endl;
}

void Health::showInfo()
{
	cout << "날짜 : " << sTime->tm_year << "년 " << sTime->tm_mon << "월 " << sTime->tm_mday << "일 " << endl
	    << "시작 시간 : " << sTime->tm_hour << "시 " << sTime->tm_min << "분 " << endl
		<< "운동 부위 : " << part << endl;
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


	cout << "날짜 : " << sTime->tm_year << "년 " << sTime->tm_mon << "월 " << sTime->tm_mday << "일 " << endl
		//    << "시작 시간 : " << sTime->tm_hour << "시 " << sTime->tm_min << "분 " << endl
		<< "시작 시간 : " << sTimeHourTemp << "시 " << sTimeMinTemp << "분 " << endl	// 임시 해결책
		<< "종료 시간 : " << eTime->tm_hour << "시 " << eTime->tm_min << "분 " << endl
		<< "운동 부위 : " << part << endl
		<< "운동 시간 : " << useHour/60 << "분" << endl;
}

int Health::countBreakTime(int setCycleI)
{
	int breakTime;
	int lineNum;
	cout << "휴식 할 시간을 입력하세요(초) : ";
	cin >> breakTime;
	for (int i = 0; i < breakTime; i++) {
		gotoXY(0, WINDOW_HEALTH_Y + setCycleI * 3);
		cout << i + 1;
		Sleep(1000);
	}
	gotoXY(0, WINDOW_HEALTH_Y + setCycleI * 3);
	cout << "휴식시간 끝!!" << endl;
	lineNum = WINDOW_HEALTH_Y + setCycleI * 3 + 2;

	return lineNum;
}

void Health::helpSport(int i, string sportName)
{
	cout << i << "회차 : " << sportName << " (" << part << " 운동)" << endl;
}

