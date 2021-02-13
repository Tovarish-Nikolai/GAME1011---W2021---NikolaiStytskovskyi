#pragma once
#include "Person.h"
#include "Gamer.h"
#include "Lamer.h"
#include <ctime>

class Survey
{
private:
	friend Gamer;		//for utilising GamingDevices
	friend Lamer;		//for utilising StreamingDevices
	
	Person** p_Participants;	//pointer for later created dynamic array.
	int m_amount;
public:
	Survey(int amount);
	~Survey();

	void setAmount(int amount);
	int getAmount();

	void generateParticipants();

	void processInfo();
};


inline Survey::Survey(int amount)
{
	setAmount(amount);
	p_Participants = new Person * [amount];
}

inline Survey::~Survey()
{
	//delete p_Participants;			//Heap error if un-commented (maybe double delete?)
	//delete [] p_Participants;			
}

inline void Survey::setAmount(int amount)
{
	m_amount = amount;
}

inline int Survey::getAmount()
{
	return m_amount;
}

inline void Survey::generateParticipants()
{
	srand(time(NULL));	//for proper RNG

	for (int i = 0; i < m_amount; i++)
	{
		int type = (rand() % 2) + 1;		//Gaming - Non Gaming rng
		if (type == 1)
		{
			int randomGD = (rand() % 5);
			GamingDevice GD;

			if (randomGD == 0)
				GD = PC_Gaming;
			else if (randomGD == 1)				//random GamingDevice generation
				GD = PS4;
			else if (randomGD == 2)
				GD = XBOX;
			else if (randomGD == 3)
				GD = SWITCH;
			else
				GD = STADIALOL;

			int ranHours = (rand() % 13) + 1;		//self-explanatory rng
			int ranAge = (rand() % 20) + 17;
			int ranSem = (rand() % 4) + 1;

			p_Participants[i] = new Gamer(GD, ranHours, ranAge, "Anon", "GBC", GAMEDEV, ranSem);
		}
		else
		{
			int randomSD = (rand() % 4);	
			StreamingDevice SD;

			if (randomSD == 0)
				SD = TV;
			else if (randomSD == 1)
				SD = ANDROID_TV;
			else if (randomSD == 2)
				SD = APPLE_TV;
			else
				SD = PC_Internet;

			int ranHours = (rand() % 13) + 1;
			int ranAge = (rand() % 20) + 17;
			int ranSem = (rand() % 4) + 1;

			p_Participants[i] = new Lamer(SD, ranHours, ranAge, "Anon", "GBC", FINANCE, ranSem);
		}
	}
}

inline void Survey::processInfo()
{
	int gamers = 0, lamers = 0;
	int averageAgeGamer = 0, averageAgeLamer = 0;

	int TV = 0, ANDROID_TV = 0, APPLE_TV = 0, PCInternet = 0;
	int PC = 0, PS4 = 0, XBOX = 0, SWITCH = 0, STADIA = 0;								//all of these are needed for processing.
	string preferredGD, preferredSD;

	int threeWatching = 0, fiveWatching = 0, eightWatching = 0, twelveWatching = 0;
	int threeGaming = 0, fiveGaming = 0, eightGaming = 0, twelveGaming = 0;
	string averageHoursWatching, averageHoursGaming;

	for (int i = 0; i < m_amount; i++)
	{
		if (p_Participants[i]->getType() == GAMER)
		{
			gamers++; //people amount counter
			averageAgeGamer += p_Participants[i]->getAge(); //used for average age calculation down the line

			if (p_Participants[i]->getPreferred() == "PC")
				PC++;
			else if (p_Participants[i]->getPreferred() == "PS4")
				PS4++;				  
			else if (p_Participants[i]->getPreferred() == "XBOX")			//used for finding preferred GamingDevice
				XBOX++;				  
			else if (p_Participants[i]->getPreferred() == "SWITCH")
				SWITCH++;			  
			else if (p_Participants[i]->getPreferred() == "STADIA(LOL)")
				STADIA++;

			if (p_Participants[i]->getAverageHours() == 3)
				threeGaming++;
			else if (p_Participants[i]->getAverageHours() == 5)
				fiveGaming++;												//used for getting average hours spent consuming Gaming entertainment
			else if (p_Participants[i]->getAverageHours() == 8)
				eightGaming++;
			else if (p_Participants[i]->getAverageHours() == 12)
				twelveGaming++;
		}
		else if ( p_Participants[i]->getType() == LAMER)
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
	else if (XBOX > PS4 && XBOX > PC && XBOX > SWITCH && XBOX > STADIA)				//finding preferred GD.
		preferredGD = "XBOX";
	else if (SWITCH > PS4 && SWITCH > XBOX && SWITCH > PC && SWITCH > STADIA)
		preferredGD = "Nintendo Switch";
	else //if (STADIA > PS4 && STADIA > XBOX && STADIA > SWITCH && STADIA > PC)
		preferredGD = "Google Stadia... wait... for real?)..lol";

	if (TV > ANDROID_TV && TV > APPLE_TV && TV > PCInternet)
		preferredSD = "Television";
	else if (ANDROID_TV > TV && ANDROID_TV > APPLE_TV && ANDROID_TV > PCInternet)		//preferred SD.
		preferredSD = "Android TV";
	else if (APPLE_TV > ANDROID_TV && APPLE_TV > TV && APPLE_TV > PCInternet)
		preferredSD = "Apple TV";
	else //if (PCInternet > ANDROID_TV && PCInternet > APPLE_TV && PCInternet > TV)
		preferredSD = "PC via Internet";

	if (threeGaming > fiveGaming && threeGaming > eightGaming && threeGaming > twelveGaming)
		averageHoursGaming = "less than three hours";
	else if (fiveGaming > threeGaming && fiveGaming > eightGaming && fiveGaming > twelveGaming)		//average gaming hours
		averageHoursGaming = "approximately five hours";
	else if (eightGaming > fiveGaming && eightGaming > threeGaming && eightGaming > twelveGaming)
		averageHoursGaming = "around eight hours a day";
	else //if (twelveGaming > fiveGaming && twelveGaming > eightGaming && twelveGaming > threeGaming)
		averageHoursGaming = "more than twelve hours a day";

	if (threeWatching > fiveWatching && threeWatching > eightWatching && threeWatching > twelveWatching)
		averageHoursWatching = "less than three hours";
	else if (fiveWatching > threeWatching && fiveWatching > eightWatching && fiveWatching > twelveWatching)		//average non-gaming hours
		averageHoursWatching = "approximately five hours";		
	else if (eightWatching > fiveWatching && eightWatching > threeWatching && eightWatching > twelveWatching)
		averageHoursWatching = "around eight hours a day";
	else //if (twelveWatching > fiveWatching && twelveWatching > eightWatching && twelveWatching > threeWatching)
		averageHoursWatching = "more than twelve hours a day";

	cout << " Amount of Non Gaming Students: " << lamers << endl;		//amount of people
	cout << " Amount of Gaming Students: " << gamers << endl;

	cout << "\n Average age of Non Gaming Students: " << averageAgeLamer / lamers << endl;	//average age
	cout << " Average age of Gaming Students: " << averageAgeGamer / gamers << endl;

	cout << "\n Preffered Streaming device for Non Gaming Students: " << preferredSD << endl;	//self-explanatory
	cout << " Preffered Gaming device for Gaming Students: " << preferredGD << endl;

	cout << "\n Average amount of hours, spent consuming non-gaming entertainment: " << averageHoursWatching << endl; //same^^
	cout << " Average amount of hours, spent consuming gaming entertainment: " << averageHoursGaming << endl;
}

