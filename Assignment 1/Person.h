#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(int a, string n,string t);
	Person();
	~Person();

	void setAge(int a);
	void setName(string n);
	void setType(string t);

	int getAge();
	string getType();

	virtual string getPreferred();
	virtual int getAverageHours();
private:
	int m_age;
	string m_name;

	string m_type;
};

inline Person::Person(int a, string n,string t)
{
	setAge(a);
	setName(n);

	setType(t);
}

inline Person::Person()
{
	setAge(18);
	setName("Alex");

	setType("gamer");
}

inline Person::~Person()
{
}

inline void Person::setAge(int a)
{
	m_age = a;
}

inline void Person::setName(string n)
{
	m_name = n;
}

inline void Person::setType(string t)
{
	m_type = t;
}

inline int Person::getAge()
{
	return m_age;
}

inline string Person::getType()
{
	return m_type;
}

inline string Person::getPreferred()
{
	return 0;
}

inline int Person::getAverageHours()
{
	return 0;
}
