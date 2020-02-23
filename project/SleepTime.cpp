#include "SleepTime.h"

SleepTime::SleepTime()
{
	hour = 0;
	min = 0;
}

SleepTime::SleepTime(int h, int m)
{
	if (h >= 24 || h < 0) {
		cout << "시간 값에 올바르지 않은 값이 입력되어 0으로 초기화 됩니다." << endl;
		hour = 0;
	}
	else {
		hour = h;
	}
	
	if (m >= 60 || m < 0) {
		cout << "분 값에 올바르지 않은 값이 입력되어 0으로 초기화 됩니다." << endl;
		min = 0;
	}
	else {
		min = m;
	}
}

void SleepTime::setHour(int h)
{
	hour = h;
}

int SleepTime::getHour()
{
	return hour;
}

void SleepTime::setMin(int m)
{
	min = m;
}

int SleepTime::getMin()
{
	return min;
}

SleepTime SleepTime::operator-(double time)
{
	int h, m;
	h = (int)time;
	m = (int)((time - h) * 60);
	h = this->hour - h;
	m = this->min - m;
	if (m < 0) {
		m += 60;
		h -= 1;
	}
	if (h < 0) {
		h += 24;
	}
	SleepTime temp(h, m);

	return temp;
}

void SleepTime::show()
{
	if (this->hour > 12) {
		cout << endl << "기상 시간 : PM " << setw(2) << hour - 12 << ":" << setw(2) << min << endl;
	}
	else {
		cout << endl << "기상 시간 : AM " << setw(2) << hour << ":" << setw(2) << min << endl;
	}
}

void SleepTime::show(double time)
{
	SleepTime temp;

	temp = *this - time;

	if (temp.getHour() > 12) {
		cout << "취침 시간 : PM " << setw(2) << temp.getHour() - 12 << ":" << setw(2) << temp.getMin() << endl;
	}
	else {
		cout << "취침 시간 : AM " << setw(2) << temp.getHour() << ":" << setw(2) << temp.getMin() << endl;
	}
}

