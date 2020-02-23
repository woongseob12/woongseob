#include "Person.h"

Person::Person()
{
	strcpy(this->name, "");
	age = 0;
	height = 0;
	weight = 0;
}

Person::~Person() {}

Person::Person(char* name, int age, double height, double weight)
{
	strcpy(this->name, name);
	this->age = age;
	this->height = height;
	this->weight = weight;
}

void Person::setName(char * cp)
{
	strcpy(this->name, cp);
}

char* Person::getName()
{
	return this->name;
}

void Person::setAge(int age)
{
	this->age = age;
}

int Person::getAge()
{
	return this->age;
}

void Person::setHeight(double height)
{
	this->height = height;
}

double Person::getHeight()
{
	return this->height;
}

void Person::setWeight(double weight)
{
	this->weight = weight;
}

double Person::getWeight()
{
	return this->weight;
}