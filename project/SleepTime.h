#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class SleepTime
{
private:
	int hour;
	int min;
	enum { AM, PM };
public:
	SleepTime();
	SleepTime(int, int);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	SleepTime operator-(double);
	void show();
	void show(double);
};