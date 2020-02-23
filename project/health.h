#pragma once
#pragma warning (disable : 4996)
#include "Person.h"
#include <time.h>
#include <iostream>
#include <string>
#define WINDOW_HEALTH_Y 9
using namespace std;

class Health : public Person
{
private:
	static time_t startHour;  
    static time_t endHour;
	static int sportTime;
	struct tm* sTime;
	struct tm* eTime;
	static string part;
public:
	Health() :Person() {};
	static void setStartHour(time_t);
	static time_t getStartHour(); 
	static void setEndHour(time_t);
	static time_t getEndHour();
	static void setSportTime(int);
	static int getSportTime();
	void setSTime(time_t);
	void setETime(time_t);
	static void setPart(string);
	static string getPart();
	void showDate();
	void showInfo();
	void showInfo(int);
	int countBreakTime(int);
	void helpSport(int,string);

};