#include <iostream>
#include "Character.h"
#include "Human.h"
#include "Orc.h"
#include "Elf.h"

using namespace std;


Weapon* Dagger = new Weapon("Dagger", "*stab*", "Pointy", 12, BACKSTAB, "a");
Weapon* Sabre = new Weapon("Sabre", "*slash*", "Elegant", 15, BLEED, "an");
Weapon* Mace = new Weapon("Mace", "*thonk*", "Sturdy", 20, STUN, "a");
Weapon* Ivy = new Weapon("Ivy imbued Spear", "*poke*", "Lush", 17, POISON, "a");

Weapon* Arsenal[4] = { Dagger, Sabre, Mace, Ivy };

const int numSaves = 5;
Character* CharacterArray[numSaves] = { NULL, NULL, NULL, NULL ,NULL };

int main()
{
	int option;
	do
	{
		cout << "************************************************************************" << endl;
		cout << "*	       Welcome to Nikolai's character editor!                  *" << endl;
		cout << "************************************************************************" << endl;

		cout << " [ 1 ] CREATE NEW     [ 2 ] VIEW ALL    [ 3 ] DELETE SAVE     [ 4 ] QUIT" << endl;
		cin >> option;

		if (option == 1)
		{
			system("CLS");

			cout << "***************************************" << endl;
			cout << "*           Choose a Race             *" << endl;
			cout << "***************************************" << endl;

			cout << " [ 1 ] HUMAN     [ 2 ] ORC    [ 3 ] ELF" << endl;
			int race; cin >> race;

			system("CLS");

			cout << "*****************" << endl;
			cout << "* Set your Name *" << endl;
			cout << "*****************" << endl;
			string name; cin.ignore(); getline(cin, name);

			system("CLS");

			cout << "****************************************************************************************" << endl;
			cout << "*					Choose a weapon:                               *" << endl;
			cout << "****************************************************************************************" << endl;

			cout << " [ 1 ] " << *Dagger << "\n [ 2 ] " << *Sabre << "\n [ 3 ] " << *Mace << "\n [ 4 ] " << *Ivy << endl;
			int choice; cin >> choice;

			int position;
			if (race == 1)
			{
				for (int i = 0; i < numSaves; i++)
				{
					if (CharacterArray[i] == NULL)
					{
						CharacterArray[i] = new Human(name, 100, Arsenal[choice - 1]);
						position = i;
						break;
					}
				}
			}
			else if (race == 2)
			{
				for (int i = 0; i < numSaves; i++)
				{
					if (CharacterArray[i] == NULL)
					{
						CharacterArray[i] = new Orc(name, 100, Arsenal[choice - 1]);
						position = i;
						break;
					}
				}
			}
			else if (race == 3)
			{
				for (int i = 0; i < numSaves; i++)
				{
					if (CharacterArray[i] == NULL)
					{
						CharacterArray[i] = new Elf(name, 100, Arsenal[choice - 1]);
						position = i;
						break;
					}
				}
			}

			system("CLS");

			cout << "*******************" << endl;
			cout << "* Your character: *" << endl;
			cout << "*******************" << endl;

			CharacterArray[position]->DisplayInfo();
			system("pause");
			system("CLS");
		}
		else if (option == 2)
		{
			system("CLS");

			cout << "**************************" << endl;
			cout << "* Displaying save files: *" << endl;
			cout << "**************************" << endl;

			for (int i = 0; i < numSaves; i++)
			{
				if (CharacterArray[i] != NULL)
				{
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
					CharacterArray[i]->DisplayInfo();
				}
				else
					cout << " File N [ " << i + 1 << " ] is empty." << endl;
			}
			system("pause");
			system("CLS");
		}
		else if (option == 3)
		{
			system("CLS");

			cout << "**************************************" << endl;
			cout << "* Which file do you want to destroy? *" << endl;
			cout << "**************************************" << endl;

			cout << " [ 1 ]     [ 2 ]     [ 3 ]     [ 4 ]     [ 5 ]" << endl;
			int file; cin >> file;

			CharacterArray[file - 1] = NULL;

			cout << " . . ." << endl;
			cout << " File destroyed succesfully." << endl;

			system("pause");
			system("CLS");
		}
	} while (option != 4);

	system("CLS");

	cout << "*****************" << endl;
	cout << "* !!!GOODBYE!!! *" << endl;
	cout << "*****************" << endl;

return 0;
}