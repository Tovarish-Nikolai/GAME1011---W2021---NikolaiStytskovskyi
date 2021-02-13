#pragma once
#include "Student.h"

enum StreamingDevice { TV, ANDROID_TV, APPLE_TV, PC_Internet };
string SDString[4] = { "TV", "ANDROID", "APPLE TV", "PC" };

class Lamer : public Student
{
public:
	Lamer(StreamingDevice SD, int hrs, int age, string name, string collName, Program prog, int currSem);
	~Lamer();

	void setSD(StreamingDevice SD);
	void setHours(int hrs);

	StreamingDevice getSD();
	int getHours();

	string getPreferred();
	int getAverageHours();
private:
	StreamingDevice m_preferred;
	int m_hours;
};


inline Lamer::Lamer(StreamingDevice SD, int hrs, int age, string name, string collName, Program prog, int currSem) : Student(age, name, collName, prog, currSem, LAMER)
{
	setSD(SD);
	setHours(hrs);
}

inline Lamer::~Lamer()
{
}

inline void Lamer::setSD(StreamingDevice SD)
{
	m_preferred = SD;
}

inline void Lamer::setHours(int hrs)
{
	m_hours = hrs;
}

inline StreamingDevice Lamer::getSD()
{
	return m_preferred;
}

inline int Lamer::getHours()
{
	return m_hours;
}

inline string Lamer::getPreferred()
{
	return SDString[getSD()];
}

inline int Lamer::getAverageHours()
{
	if (getHours() >= 12)
		return 12;
	else if (getHours() >= 8)
		return 8;
	else if (getHours() >= 5)
		return 5;
	else //if (getHours() <= 3)
		return 3;
}
