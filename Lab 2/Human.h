#pragma once
#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Human : public Character
{
public:
	Human(string name, int hp, Weapon* item) : Character(name, hp, item) {};

	virtual void DisplayInfo()
	{
		cout << " This is " << getName() << ", who is a Human with " << getHealth() << " base HP, wielding " << getWeapon() << "." << endl;
	}


};