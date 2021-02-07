#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Ability {BLEED , STUN , POISON , BACKSTAB};
const string aName[] = { "cause Bleeding", "Stun", "Poison", "Backstab" };

class Weapon
{
public:
	Weapon(string n, string soun, string desc, int dmg, Ability spec, string pre);
	~Weapon();
	void setName(string n);
	string getName();
	void setSound(string s);
	string getSound();
	void setDesc(string d);
	string getDesc();
	void setDmg(int d);
	int getDmg();

	void setPrefix(string a);
	string getPrefix();

	friend ostream& operator<<(ostream& out,const Weapon& right);
private:
	string name;
	string sound;
	string description;
	int damage;
	
	Ability special;

	string prefix;
};

inline Weapon::Weapon(string name, string sound, string desc, int dmg, Ability spec, string pre)
{
	setName(name);
	setSound(sound);
	setDesc(desc);
	setDmg(dmg);
	
	special = spec;

	setPrefix (pre);
}

inline Weapon::~Weapon()
{
}

inline void Weapon::setName(string n)
{
	name = n;
}

inline string Weapon::getName()
{
	return name;
}

inline void Weapon::setSound(string s)
{
	sound = s;
}

inline string Weapon::getSound()
{
	return sound;
}

inline void Weapon::setDesc(string d)
{
	description = d;
}

inline string Weapon::getDesc()
{
	return description;
}

inline void Weapon::setDmg(int d)
{
	damage = d;
}

inline int Weapon::getDmg()
{
	return damage;
}

inline void Weapon::setPrefix(string pre) { prefix = pre; }
inline string Weapon::getPrefix()
{
	return prefix;
}

inline ostream& operator<<(ostream& out,const Weapon& item)
{
	//cout << item.getPrefix() << " " << item.getDesc() << " " << item.getName() << " that does " << item.getDmg() << " damage, has the ability to " << Weapon::special << " and sound like \"" << item.getSound() << "\"" << endl;
	cout << item.prefix << " " << item.description << " " << item.name << " that does " << item.damage << " damage, has the ability to " << aName[item.special] << " and sounds like \"" << item.sound << "\"";
	return out;
}
