#pragma once
#include "Person.h"

class Smoking : public Person
{
private:
	int smokingYear;
	int smokingMonth;
	int smokingDay;
	int smokingPerDay;
	int totMoney;
public:
	Smoking() : Person() {}
	Smoking(int, int, int, int);
	int getTotMoney();
	void calSmokingMoney(int, int, int);
	
};

int leapCheck(int);
int totDays(int, int, int);

