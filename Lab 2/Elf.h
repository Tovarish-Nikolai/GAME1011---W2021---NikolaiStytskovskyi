#pragma once
#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Elf : public Character
{
public:
	Elf(string name, int hp, Weapon* item) : Character(name, hp, item) {};

	virtual void DisplayInfo()
	{
		cout << " This is " << getName() << ", who is a swift Elf with " << getHealth()-20 << " base HP, wielding " << getWeapon() << "." << endl;
	}


};