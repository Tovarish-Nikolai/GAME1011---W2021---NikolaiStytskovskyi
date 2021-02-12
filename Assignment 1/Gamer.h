#pragma once
#include "Student.h"

enum GamingDevice {PC, PS4, XBOX, SWITCH, STADIALOL};
string GDString[5] = { "PC","PS4", "XBOX", "SWITCH", "STADIA(LOL)" };

class Gamer : public Student
{
public:
	Gamer(GamingDevice GD, int hrs,int age, string name, string collName, Program prog, int currSem);
	~Gamer();

	void setGD(GamingDevice GD);
	void setHours(int hrs);

	GamingDevice getGD();
	int getHours();

	string getPreferred();
	int getAverageHours();
private:
	GamingDevice m_preferred;
	int m_hours;
};

inline Gamer::Gamer(GamingDevice GD, int hrs,int age, string name, string collName, Program prog, int currSem) : Student(age, name, collName, prog, currSem, "gamer")
{
	setGD(GD);
	setHours(hrs);
}

inline Gamer::~Gamer()
{
}

inline void Gamer::setGD(GamingDevice GD)
{
	m_preferred = GD;
}

inline void Gamer::setHours(int hrs)
{
	m_hours = hrs;
}

inline GamingDevice Gamer::getGD()
{
	return m_preferred;
}

inline int Gamer::getHours()
{
	return m_hours;
}

inline string Gamer::getPreferred()
{
	return GDString[getGD()];
}

inline int Gamer::getAverageHours()
{
	if (getHours() >= 12)
		return 12;
	else if (getHours() >= 8)
		return 8;
	else if (getHours() >= 5)
		return 5;
	else if (getHours() <= 3)
		return 3;
}
