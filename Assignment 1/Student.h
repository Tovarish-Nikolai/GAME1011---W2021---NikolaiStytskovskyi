#pragma once
#include "Person.h"

enum Program { GAMEDEV, FINANCE, MARKETING, BIOLOGY }; 

class Student : public Person
{
public:
	Student(int age, string name, string collName, Program prog, int currSem, Types type);
	Student();
	~Student();

	void setCollName(string n);
	void setProg(Program p);
	void setCurrSem(int n);

	int getAge();
	Types getType();		//should've been virtual.

	string getPreferred() = 0;		//pure virtual "transfer", not sure if necessary, I think they arent.
	int getAverageHours() = 0;
private:
	string m_collegeName;
	Program m_program;
	int m_currentSemester;
};

inline Student::Student(int age, string name, string collName, Program prog, int currSem, Types type) : Person(age, name, type) //param constructor
{
	setCollName(collName);
	setProg(prog);
	setCurrSem(currSem);
}

inline Student::Student() //default
{
	setCollName("GBC");
	setProg(GAMEDEV);
	setCurrSem(3);
}

inline Student::~Student()
{
}

inline void Student::setCollName(string n)
{
	m_collegeName = n;
}

inline void Student::setProg(Program p)
{
	m_program = p;
}

inline void Student::setCurrSem(int n)
{
	m_currentSemester = n;
}

inline int Student::getAge()
{
	return Person::getAge();
}

inline Types Student::getType()
{
	return Person::getType();
}

//inline string Student::getPreferred()			//a shadow of the past.
//{
//	return " ";
//}
//
//inline int Student::getAverageHours()
//{
//	return 0;
//}
