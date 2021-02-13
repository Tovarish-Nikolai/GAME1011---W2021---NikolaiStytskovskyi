#include <iostream>
#include <string>
#include <ctime>
#include "Person.h"
#include "Survey.h"

using namespace std;

int main()
{
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

	Leisure.generateParticipants();

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
	Leisure.processInfo();

	return 0;
}