#include "Smoking.h"

Smoking::Smoking(int smokingYear, int smokingMonth, int smokingDay, int smokingPerDay) : Person()
{
	this->smokingYear = smokingYear;
	this->smokingMonth = smokingMonth;
	this->smokingDay = smokingDay;
	this->smokingPerDay = smokingPerDay;
	this->totMoney = 0;
}

int Smoking::getTotMoney()
{
	return totMoney;
}

void Smoking::calSmokingMoney(int year, int month, int day) 
{
	int dayCnt;
	int dayMoney;
	int totMoney;

	if (this->smokingYear < 2015) {
		dayCnt = totDays(2014, 12, 31) - totDays(smokingYear, smokingMonth, smokingDay);
		dayMoney = (int)((smokingPerDay / 20.0) * 2700);
		totMoney = dayCnt * dayMoney;
		dayCnt = totDays(year, month, day) - totDays(2015, 1, 1);
		dayMoney = (int)((smokingPerDay / 20.0) * 4500);
		totMoney = dayCnt * dayMoney + totMoney;
	}
	else {
		dayCnt = totDays(year, month, day) - totDays(smokingYear, smokingMonth, smokingDay);

		dayMoney = (int)((smokingPerDay / 20.0) * 4500);
		totMoney = dayCnt * dayMoney;
	}
	this->totMoney = totMoney;
}

int leapCheck(int year)
{
	int check;

	if (year % 4 != 0) {
		check = 0;
	}
	else if (year % 100 != 0) {
		check = 1;
	}
	else if ((year % 100 == 0) && (year % 400 == 0)) {
		check = 1;
	}
	else {
		check = 0;
	}

	return check;
}

int totDays(int year, int mon, int day)
{
	int total = 0;
	int mAry[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leap;

	for (int i = 0; i < year; i++) {
		if (leapCheck(i) == 0) {
			total += 365;
		}
		else {
			total += 366;
		}
	}
	leap = leapCheck(year);
	mAry[1] += leap;
	for (int i = 0; i < mon - 1; i++) {
		total += mAry[i];
	}
	total += day;

	return total;
}