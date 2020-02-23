#pragma once
#include <cstring>

class Person
{
private:
	char name[20];
	int age;
	double height;
	double weight;
public:
	Person();
	~Person();
	Person(char*, int, double , double);
	void setName(char *);
	char* getName();
	void setAge(int);
	int getAge();
	void setHeight(double);
	double getHeight();
	void setWeight(double);
	double getWeight();
};