#include "Classes.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	cout << " *** Welcome to Nikolai's database of Platforms, Games and Achievments! ***" << endl;


	cout << " \n Please, enter the name of the platform. . . ";
	string name;
	getline(cin, name);

	cout << " \n Please, enter the manufacturer of the " << name << " platform. . . ";
	string manufacturer;
	getline(cin, manufacturer);

	Platform I(name, manufacturer);

	cout << "\n You have created a platform named " << I.GetName() << " manufactured by " << I.GetManufacturer() << "!" << endl;

	cout << "\n How many games would you like to add. . . ";
	int gameAmount;
	cin >> gameAmount;
	cin.ignore(100, '\n');

	I.ChangeSize(gameAmount);

	Game* pGPtr = nullptr;
	pGPtr = new Game();

	int i = 0;
	do
	{
		system("CLS");  //Sweep-sweep-sweep!

		cout << "\n\n What is game Number " << i+1 << " called. . . ";
		string name;
		getline(cin, name);

		cout << "\n\n Who is the publisher for " << name << ". . . ";
		string publisher;
		getline(cin, publisher);

		cout << "\n\n Who is the developer for " << name << " published by " << publisher << ". . . ";
		string developer;
		getline(cin, developer);

		pGPtr->CreateGameObj(name, publisher, developer); //Creating new Game object.
		I.AddToGameArray(i,pGPtr); //Adding it to the array

		i++;
	} while (i < gameAmount);

	for (int g = 0; g < gameAmount; g++)
	{
		system("CLS");  //Sweep-sweep-sweep!

		cout << "\n How many achievments do you want to input for " << I.AccessGameArray(g).GetName() << ". . .";
		int achievmentAmount;
		cin >> achievmentAmount;
		cin.ignore(100, '\n');

		Achievment* pAPtr = nullptr;
		pAPtr = new Achievment();

		int i = 0;
		do
		{
			system("CLS");  //Sweep-sweep-sweep!
			cin.ignore(100, '\n');

			cout << "\n\n What is achievment Number " << i + 1 << " called. . . ";
			string title;
			getline(cin, title);

			cout << "\n\n What is the description for the " << title << " achievment. . . ";
			string description;
			getline(cin, description);

			cout << "\n\n Amount of points you get for the " << title << " achievment is. . .";
			int score;
			cin >> score;

			pAPtr->CreateAchievmentObj(title, description,score); //Creating new Achievment object.
			I.AccessGameArray(i).AddToAchievmentArray(i, pAPtr); //Adding it to the array.

			i++;
		} while (i < achievmentAmount);

	}
	
	return 0;
}