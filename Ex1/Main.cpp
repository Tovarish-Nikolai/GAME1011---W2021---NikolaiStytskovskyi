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

	cout << "\n You have added a platform named " << I.GetName() << " manufactured by " << I.GetManufacturer() << "!" << endl;

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

		cout << "\n How many achievments do you want to input for " << I.AccessGameArray(g)->GetName() << ". . .";
		int achievmentAmount;
		cin >> achievmentAmount;

		I.AccessGameArray(g)->SetAchievmentAmount(achievmentAmount);
		
		Achievment* pAPtr = nullptr;
		pAPtr = new Achievment();

		for (int i = 0; i < achievmentAmount; i++)
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

			pAPtr->CreateAchievmentObj(title, description, score); //Creating new Achievment object.
			I.AccessGameArray(g)->AddToAchievmentArray(i, pAPtr); //Adding it to the array. Breaks stuff...
		}
	}
	
	system("CLS");  //Sweep-sweep-sweep!


	//Displaying the results.
	cout << "\n\n Platform : \t" << I.GetName() << endl;
	for (int g = 0; g < gameAmount; g++)
	{
		cout << "\n Game : \t" << I.AccessGameArray(g)->GetName() << endl;
		cout << "\n Developed by : \t" << I.AccessGameArray(g)->GetDev() << endl;
		cout << "\n Published by : \t" << I.AccessGameArray(g)->GetPublisher() << endl;

		for (int a = 0; a < I.AccessGameArray(g)->GetAchievmentAmount(); a++)
		{
			cout << "\n Achievment : \t" << I.AccessGameArray(g)->AccessAchievmentArray(a)->GetTitle() << endl;
			cout << "\n Description : \t" << I.AccessGameArray(g)->AccessAchievmentArray(a)->GetDescription() << endl;
			cout << "\n Score : \t" << I.AccessGameArray(g)->AccessAchievmentArray(a)->GetScore() << endl;
		}
	}

	return 0;
}

// i feel worthless and depressed :(

//Nikolai signing out.