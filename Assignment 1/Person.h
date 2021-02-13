#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Types {GAMER, LAMER};

class Person
{
public:
	Person(int a, string n,Types t);
	Person();
	virtual ~Person(); //virtual destructor for avoiding Heap (memory leak) errors

	void setAge(int a);
	void setName(string n);
	void setType(Types t);

	int getAge();
	Types getType();	// in hindsight, this should've been a virtual function.

	virtual string getPreferred() = 0;
	virtual int getAverageHours() = 0;
private:
	int m_age;
	string m_name;

	Types m_type;
};

inline Person::Person(int a, string n,Types t) //param constructor
{
	setAge(a);
	setName(n);

	setType(t);
}

inline Person::Person() //default
{
	setAge(18);
	setName("Alex");

	setType(GAMER);
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

inline void Person::setType(Types t)
{
	m_type = t;
}

inline int Person::getAge()
{
	return m_age;
}

inline Types Person::getType()
{
	return m_type;
}

//inline string Person::getPreferred()		//a shadow of the past.
//{
//	return " ";
//}
//
//inline int Person::getAverageHours()
//{
//	return 0;
//}
