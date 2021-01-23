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

	I.ChangeSize(gameAmount);

	Game* pGPtr = nullptr;
	pGPtr = new Game();

	int i = 0;
	do
	{
		cin.ignore();
		cout << "\n\n What is game Number " << i+1 << " called. . . ";
		string name;
		getline(cin, name);

		cout << "\n\n Who is the publisher for " << name << ". . . ";
		string publisher;
		getline(cin, publisher);

		cout << "\n\n Who is the developer for " << name << " published by " << publisher << ". . . ";
		string developer;
		getline(cin, developer);

		pGPtr->CreateGameObj(name, publisher, developer);
		I.AddToGameArray(i,pGPtr);

		i++;
	} while (i < gameAmount);

	cout << I.AccessGameArray(0).GetName() << " " << I.AccessGameArray(1).GetName(); 
	
	return 0;
}