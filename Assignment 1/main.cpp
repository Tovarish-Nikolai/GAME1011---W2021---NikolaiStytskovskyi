#include <iostream>
#include <string>
#include <ctime>
#include "Person.h"
#include "Survey.h"

using namespace std;

int main()
{
	srand(time(NULL));

	cout << "*************************************************" << endl;
	cout << "* Welcome to Nikolai's simple survey genarator! *" << endl;
	cout << "*************************************************" << endl;

	int amount = 0;
	do
	{
		cout << "\n Please, how many participants would you want to generate? (max 500) ";
		cin >> amount;
		if (amount > 500)
			cout << "\n That's too many, im afraid." << endl;
		else break;
	} while (amount > 500);
	
	Survey Leisure(amount);

	system("CLS");
	cout << "\n Generating participants... ... ... ... ...\n" << endl;

	for (int i = 0; i < amount; i++)
	{
		int type = (rand() % 2) + 1;
		if (type == 1)
		{
			int randomGD = (rand() % 5);		
			GamingDevice GD;					
			
			if (randomGD == 0)					
				GD = PC_Gaming;					
			else if (randomGD == 1)				
				GD = PS4;						
			else if (randomGD == 2)
				GD = XBOX;
			else if (randomGD == 3)
				GD = SWITCH;
			else
				GD = STADIALOL;

			int ranHours = (rand() % 13) + 1;
			int ranAge = (rand() % 20) + 17;
			int ranSem = (rand() % 4) + 1;

			Leisure.putInArray( Gamer(GD, ranHours, ranAge, "Anon", "GBC", GAMEDEV, ranSem), i);
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

			Leisure.putInArray( Lamer(SD, ranHours, ranAge, "Anon", "GBC", FINANCE, ranSem), i);
		}
	}

	system("pause");
	system("CLS");
	
	cout << " Are you ready to process the survey? [Y/N]";
	char answer; cin >> answer;

	while (answer != 'Y' && answer != 'y')
	{
		if (answer == 'N' || answer == 'n')
			cout << " And now?";
		cin >> answer;
	}

	system("CLS");
	//Leisure.processInfo();

	return 0;
}