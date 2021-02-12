#pragma once
#include "Person.h"
#include "Gamer.h"
#include "Lamer.h"


class Survey
{
private:
	friend Gamer;
	friend Lamer;

	Person* p_Participants = new Person[m_amount];

	int m_amount;
public:
	Survey(int amount);
	~Survey();

	void setAmount(int amount);
	void processInfo(Person* participants[],int amount);
};


inline Survey::Survey(int amount)
{
	setAmount(amount);
}

inline Survey::~Survey()
{
}

inline void Survey::setAmount(int amount)
{
	m_amount = amount;
}

inline void Survey::processInfo(Person* participants[], int amount)
{
	int gamers, lamers;
	int averageAgeGamer, averageAgeLamer;

	int TV, ANDROID_TV, APPLE_TV, PCInternet;
	int PC, PS4, XBOX, SWITCH, STADIA = -4;
	string preferredGD, preferredSD;

	int threeWatching, fiveWatching, eightWatching, twelveWatching = -4;
	int threeGaming, fiveGaming, eightGaming, twelveGaming = -4;
	string averageHoursWatching, averageHoursGaming;

	for (int i = 0; i < amount; i++)
	{
		if (participants[i]->getType() == "gamer")
		{
			gamers++;
			averageAgeGamer += participants[i]->getAge();

			if (participants[i]->getPreferred() == "PC")
				PC++;
			else if (participants[i]->getPreferred() == "PS4")
				PS4++;
			else if (participants[i]->getPreferred() == "XBOX")
				XBOX++;
			else if (participants[i]->getPreferred() == "SWITCH")
				SWITCH++;
			else if (participants[i]->getPreferred() == "STADIA(LOL)")
				STADIA++;

			if (participants[i]->getAverageHours() == 3)
				threeGaming++;
			else if (participants[i]->getAverageHours() == 5)
				fiveGaming++;
			else if (participants[i]->getAverageHours() == 8)
				eightGaming++;
			else if (participants[i]->getAverageHours() == 12)
				twelveGaming++;
		}
		else
		{
			lamers++;
			averageAgeLamer += participants[i]->getAge();

			if (participants[i]->getPreferred() == "TV")
				TV++;
			else if (participants[i]->getPreferred() == "ANDROID TV")
				ANDROID_TV++;
			else if (participants[i]->getPreferred() == "APPLE TV")
				APPLE_TV++;
			else if (participants[i]->getPreferred() == "PC")
				PCInternet++;

			if (participants[i]->getAverageHours() == 3)
				threeWatching++;
			else if (participants[i]->getAverageHours() == 5)
				fiveWatching++;
			else if (participants[i]->getAverageHours() == 8)
				eightWatching++;
			else if (participants[i]->getAverageHours() == 12)
				twelveWatching++;
		}
	}

	if (PC > PS4 + XBOX + SWITCH + STADIA)
		preferredGD = "PC";
	else if (PS4 > PC + XBOX + SWITCH + STADIA)
		preferredGD = "PS4";
	else if (XBOX > PS4 + PC + SWITCH + STADIA)
		preferredGD = "XBOX";
	else if (SWITCH > PS4 + XBOX + PC + STADIA)
		preferredGD = "Nintendo Switch";
	else if (STADIA > PS4 + XBOX + SWITCH + PC)
		preferredGD = "Google Stadia... wait... for real?)..lol";

	if (TV > ANDROID_TV + APPLE_TV + PCInternet)
		preferredSD = "Television";
	else if (ANDROID_TV > TV + APPLE_TV + PCInternet)
		preferredSD = "Android TV";
	else if (APPLE_TV > ANDROID_TV + TV + PCInternet)
		preferredSD = "Apple TV";
	else if (PCInternet > ANDROID_TV + APPLE_TV + TV)
		preferredSD = "PC via Internet";

	if (threeGaming > fiveGaming + eightGaming + twelveGaming)
		averageHoursGaming = "less than three hours";
	else if (fiveGaming > threeGaming + eightGaming + twelveGaming)
		averageHoursGaming = "approximately five hours";
	else if (eightGaming > fiveGaming + threeGaming + twelveGaming)
		averageHoursGaming = "around eight hours a day";
	else if (twelveGaming > fiveGaming + eightGaming + threeGaming)
		averageHoursGaming = "more than twelve hours a day";

	if (threeWatching> fiveWatching + eightWatching + twelveWatching)
		averageHoursWatching = "less than three hours";
	else if (fiveWatching > threeWatching + eightWatching + twelveWatching)
		averageHoursWatching = "approximately five hours";
	else if (eightWatching > fiveWatching + threeWatching + twelveWatching)
		averageHoursWatching = "around eight hours a day";
	else if (twelveWatching > fiveWatching + eightWatching + threeWatching)
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

