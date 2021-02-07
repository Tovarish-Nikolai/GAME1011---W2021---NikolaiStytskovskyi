#pragma once
#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Orc : public Character
{
public:
	Orc(string name, int hp, Weapon* item) : Character(name, hp, item) {};

	virtual void DisplayInfo()
	{
		cout << " This is " << getName() << ", who is a bulky Orc with " << getHealth()+35 << " base HP, wielding " << getWeapon() << "." << endl;
	}


};