#include "SleepTime.h"

SleepTime::SleepTime()
{
	hour = 0;
	min = 0;
}

SleepTime::SleepTime(int h, int m)
{
	if (h >= 24 || h < 0) {
		cout << "�ð� ���� �ùٸ��� ���� ���� �ԷµǾ� 0���� �ʱ�ȭ �˴ϴ�." << endl;
		hour = 0;
	}
	else {
		hour = h;
	}
	
	if (m >= 60 || m < 0) {
		cout << "�� ���� �ùٸ��� ���� ���� �ԷµǾ� 0���� �ʱ�ȭ �˴ϴ�." << endl;
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
		cout << endl << "��� �ð� : PM " << setw(2) << hour - 12 << ":" << setw(2) << min << endl;
	}
	else {
		cout << endl << "��� �ð� : AM " << setw(2) << hour << ":" << setw(2) << min << endl;
	}
}

void SleepTime::show(double time)
{
	SleepTime temp;

	temp = *this - time;

	if (temp.getHour() > 12) {
		cout << "��ħ �ð� : PM " << setw(2) << temp.getHour() - 12 << ":" << setw(2) << temp.getMin() << endl;
	}
	else {
		cout << "��ħ �ð� : AM " << setw(2) << temp.getHour() << ":" << setw(2) << temp.getMin() << endl;
	}
}

