#include <iostream>
#include "Character.h"
#include "Human.h"

using namespace std;


int main()
{
	Weapon* Dagger = new Weapon("Dagger", "*stab*", "Pointy", 12, BACKSTAB, "a");
	const int numSaves = 5;
	Character* CharacterArray[numSaves] = {new Human("Niko", 100, Dagger) };

	CharacterArray[0]->DisplayInfo();

return 0;
}