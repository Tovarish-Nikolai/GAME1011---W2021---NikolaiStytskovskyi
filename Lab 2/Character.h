#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;


class Character
{
public:
	Character(string n, int hp, Weapon* item);
	~Character();

	void setName(string n);
	string getName();
	void setHealth(int hp);
	int getHealth();

	void setWeapon(Weapon* item);
	Weapon getWeapon();

	virtual void DisplayInfo() = 0;
protected:
	string name;
	int health;
	Weapon* item;
};

Character::Character(string n,int hp, Weapon* item)
{
	setName(n);
	setHealth(hp);

	setWeapon(item);
}

Character::~Character()
{
}

void Character::setName(string n)
{
	name = n;
}

string Character::getName()
{
	return name;
}

void Character::setHealth(int hp)
{
	health = hp;
}

int Character::getHealth()
{
	return health;
}

void Character::setWeapon(Weapon* item)
{
	this->item = item;
}

Weapon Character::getWeapon()
{
	return *item;
}