#pragma once
#include "Person.h"
#include "Gamer.h"
#include "Lamer.h"

class Survey
{
private:
	friend Gamer;
	friend Lamer;

	
	Person** p_Participants = new Person*[getAmount()];
	int m_amount;
public:
	Survey(int amount);
	~Survey();

	void setAmount(int amount);
	int getAmount();

	void putInArray(Person obj, int pos);

	void processInfo();
};


inline Survey::Survey(int amount)
{
	setAmount(amount);
}

inline Survey::~Survey()
{
	//delete p_Participants;
	//delete[] p_Participants;
}

inline void Survey::setAmount(int amount)
{
	m_amount = amount;
}

inline int Survey::getAmount()
{
	return m_amount;
}

inline void Survey::putInArray(Person obj, int pos)
{
	p_Participants[pos] = new Gamer;
}

inline void Survey::processInfo()
{
	int gamers = 0, lamers = 0;
	int averageAgeGamer = 0, averageAgeLamer = 0;

	int TV = 0, ANDROID_TV = 0, APPLE_TV = 0, PCInternet = 0;
	int PC = 0, PS4 = 0, XBOX = 0, SWITCH = 0, STADIA = 0;
	string preferredGD, preferredSD;

	int threeWatching = 0, fiveWatching = 0, eightWatching = 0, twelveWatching = 0;
	int threeGaming = 0, fiveGaming = 0, eightGaming = 0, twelveGaming = 0;
	string averageHoursWatching, averageHoursGaming;

	for (int i = 0; i < m_amount; i++)
	{
		if (p_Participants[i]->getType() == GAMER)
		{
			gamers++;
			averageAgeGamer += p_Participants[i]->getAge();

			if (p_Participants[i]->getPreferred() == "PC")
				PC++;
			else if (p_Participants[i]->getPreferred() == "PS4")
				PS4++;				  
			else if (p_Participants[i]->getPreferred() == "XBOX")
				XBOX++;				  
			else if (p_Participants[i]->getPreferred() == "SWITCH")
				SWITCH++;			  
			else if (p_Participants[i]->getPreferred() == "STADIA(LOL)")
				STADIA++;

			if (p_Participants[i]->getAverageHours() == 3)
				threeGaming++;
			else if (p_Participants[i]->getAverageHours() == 5)
				fiveGaming++;
			else if (p_Participants[i]->getAverageHours() == 8)
				eightGaming++;
			else if (p_Participants[i]->getAverageHours() == 12)
				twelveGaming++;
		}
		else
		{
			lamers++;
			averageAgeLamer += p_Participants[i]->getAge();

			if (p_Participants[i]->getPreferred() == "TV")
				TV++;
			else if (p_Participants[i]->getPreferred() == "ANDROID TV")
				ANDROID_TV++;
			else if (p_Participants[i]->getPreferred() == "APPLE TV")
				APPLE_TV++;
			else if (p_Participants[i]->getPreferred() == "PC")
				PCInternet++;

			if (p_Participants[i]->getAverageHours() == 3)
				threeWatching++;
			else if (p_Participants[i]->getAverageHours() == 5)
				fiveWatching++;		  
			else if (p_Participants[i]->getAverageHours() == 8)
				eightWatching++;	  
			else if (p_Participants[i]->getAverageHours() == 12)
				twelveWatching++;
		}
	}

	if (PC > PS4 && PC > XBOX && PC > SWITCH && PC > STADIA)
		preferredGD = "PC";
	else if (PS4 > PC && PS4 > XBOX && PS4 > SWITCH && PS4 > STADIA)
		preferredGD = "PS4";
	else if (XBOX > PS4 && XBOX > PC && XBOX > SWITCH && XBOX > STADIA)
		preferredGD = "XBOX";
	else if (SWITCH > PS4 && SWITCH > XBOX && SWITCH > PC && SWITCH > STADIA)
		preferredGD = "Nintendo Switch";
	else if (STADIA > PS4 && STADIA > XBOX && STADIA > SWITCH && STADIA > PC)
		preferredGD = "Google Stadia... wait... for real?)..lol";

	if (TV > ANDROID_TV && TV > APPLE_TV && TV > PCInternet)
		preferredSD = "Television";
	else if (ANDROID_TV > TV && ANDROID_TV > APPLE_TV && ANDROID_TV > PCInternet)
		preferredSD = "Android TV";
	else if (APPLE_TV > ANDROID_TV && APPLE_TV > TV && APPLE_TV > PCInternet)
		preferredSD = "Apple TV";
	else if (PCInternet > ANDROID_TV && PCInternet > APPLE_TV && PCInternet > TV)
		preferredSD = "PC via Internet";

	if (threeGaming > fiveGaming && threeGaming > eightGaming && threeGaming > twelveGaming)
		averageHoursGaming = "less than three hours";
	else if (fiveGaming > threeGaming && fiveGaming > eightGaming && fiveGaming > twelveGaming)
		averageHoursGaming = "approximately five hours";
	else if (eightGaming > fiveGaming && eightGaming > threeGaming && eightGaming > twelveGaming)
		averageHoursGaming = "around eight hours a day";
	else if (twelveGaming > fiveGaming && twelveGaming > eightGaming && twelveGaming > threeGaming)
		averageHoursGaming = "more than twelve hours a day";

	if (threeWatching > fiveWatching && threeWatching > eightWatching && threeWatching > twelveWatching)
		averageHoursWatching = "less than three hours";
	else if (fiveWatching > threeWatching && fiveWatching > eightWatching && fiveWatching > twelveWatching)
		averageHoursWatching = "approximately five hours";
	else if (eightWatching > fiveWatching && eightWatching > threeWatching && eightWatching > twelveWatching)
		averageHoursWatching = "around eight hours a day";
	else if (twelveWatching > fiveWatching && twelveWatching > eightWatching && twelveWatching > threeWatching)
		averageHoursWatching = "more than twelve hours a day";

	cout << " Amount of Non Gaming Students: " << lamers << endl;
	cout << " Amount of Gaming Students: " << gamers << endl;

	cout << "\n Average age of Non Gaming Students: " << averageAgeLamer / lamers << endl;
	cout << " Average age of Gaming Students: " << averageAgeGamer / gamers << endl;

	cout << "\n Preffered Streaming device for Non Gaming Students: " << preferredSD << endl;
	cout << " Preffered Gaming device for Gaming Students: " << preferredGD << endl;

	cout << "\n Average amount of hours, spent consuming non-gaming entertainment: " << averageHoursWatching << endl;
	cout << " Average amount of hours, spent consuming gaming entertainment: " << averageHoursGaming << endl;
}

