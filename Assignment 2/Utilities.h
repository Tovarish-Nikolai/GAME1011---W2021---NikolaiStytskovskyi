#pragma once
#include "Classes.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>

enum OBJECTS 
{ 
	// Objects
	BUTTON, BED, BOWL, BOX, DRAWER, DOOR, DESKTOP, COMPUTER, COUNTERTOP, CABINET, CUTTING_BOARD, WARDROBE, 
	W_BLOWER, W_SPOON, W_KNIFEK, W_KNIFEB, W_BREADKNIFE, W_ROLLING, W_KEY, PAINTING, PADLOCK, TOILET, MIRROR, SHOWER, FRIDGE,
	// "Enemies"
	BUTTER, BREAD, SAUSAGE,
	// Directions
	BATHROOM, BEDROOM, KITCHEN,
	// Basic Interface
	BACK, INVENTORY,
	// Final
	SANDWICH
};

int stage;
bool running,
storyRoom = false,
storyHallway = false,
storyBathroom = false,
storyKitchen = false;

std::string 
action,
object,
storyDialog;

// Puzzle piece booleans
bool spoonTaken = false,
spoonUsed = false,
dryerTaken = false,
dryerUsed = false,
kitchenTaken = false,
kitchenUsed = false,
butterTaken = false,
butterUsed = false,
breadTaken = false,
breadUsed = false,
rollingTaken = false,
rollingUsed = false,
pictureMoved = false,
pictureUsed = false,
keyTaken = false,
keyUsed = false;

int code = 9510,
attempt;

std::string butter,
bread,
sausage;

void changeStage(int num)
{
	stage = num;
}

void ExecuteCommand(std::string command, OBJECTS object)
{
	if (command == "ACCESS" && object == INVENTORY)
	{
		system("CLS");
		Pockets.displayInventory(Pockets.getTop());
	}

	else if (stage == 0 && object == BUTTON && command == "PRESS")
	{
		changeStage(1);
	}

	// STAGE 2 START
	//Drawer
	else if (stage == 2 && object == DRAWER && (command == "OPEN" || command == "USE"))
	{
		if (!butterTaken)
		{
			std::cout << " You open the drawer and look inside." << std::endl;
			changeStage(5);
		}
		else 
			std::cout << " You open the drawer and close it back in, as there's nothing of use in it." << std::endl;
	}
	else if (stage == 2 && object == DRAWER && command == "INSPECT")
	{
		std::cout << " A drawer with a lot of not so useful things in it.." << std::endl;
	}

	//Desktop
	else if (stage == 2 && object == DESKTOP && command == "INSPECT")
	{
		std::cout << " You look at your cluttered desk.." << std::endl;

		changeStage(3);
	}
	//Warderobe
	else if (stage == 2 && object == WARDROBE && (command == "OPEN" || command == "USE"))
	{
		std::cout << " You open the wardrobe and see a skeleton costume from the last time you actually went out of your house during Hallowen, among your other clothing.." << std::endl;
	}
	else if (stage == 2 && object == WARDROBE && command == "INSPECT")
	{
		std::cout << " Your old and trustful wardrobe with a mirror on one of the doors."
			"\n You look on yourself through the mirror, and don't regret spending even a cent on theese pajams.." << std::endl;
	}

	//Bed
	else if (stage == 2 && object == BED && command == "USE")
	{
		std::cout << " Not sleepy right now.." << std::endl;
	}
	else if (stage == 2 && object == BED && command == "INSPECT")
	{
		std::cout << " A double bed that saw too many lonely nights.." << std::endl;
	}

	//Door
	else if (stage == 2 && object == DOOR && (command == "USE" || command == "OPEN"))
	{
		std::cout << " You walk out of your room.." << std::endl;

		if(!storyHallway)
			changeStage(6);
		else
			changeStage(7);
	}
	else if (stage == 2 && object == DOOR && command == "INSPECT")
	{
		std::cout << " Wow! It's actually... Unbelievable!... Oh.. my godd.. A DOOR IN A ROOM?!"
			"\n Wait, no, no it's actually normal to have a door in a room.." << std::endl;
	}
	// STAGE 2 END

	// STAGE 3 START
	//Computer
	else if (stage == 3 && object == COMPUTER && command == "USE")
	{
		std::cout << " A loud gurgle in your belly reminds you why did you stand up in the first place.." << std::endl;
	}
	else if (stage == 3 && object == COMPUTER && command == "INSPECT")
	{
		std::cout << " It's your PC that you use for work, entertainment and shopping. What would you do without it?" << std::endl;
	}

	//Bowl
	else if (stage == 3 && object == BOWL && command == "INSPECT")
	{
		if (!spoonTaken)
			stage = 4;
		else
			std::cout << " You already took the spoon. What? You want the whole bowl? You can't stuff it into your pocket.." << std::endl;
	}
	else if (stage == 3 && object == BOWL && command == "USE")
	{
			std::cout << " It has no cereal left in it.." << std::endl;
	}
	//GO BACK
	else if (stage == 3 && command == "GO" && object == BACK)
	{
		changeStage(2);
	}
	// STAGE 3 END

	// STAGE 4 START
	//Spoon
	else if (stage == 4 && object == W_SPOON && command == "INSPECT")
	{
		std::cout << " It's a medium-sized table spoon.." << std::endl;
	}
	else if (stage == 4 && object == W_SPOON && command == "TAKE")
	{
		std::cout << " You take the spoon and place it in your pocket." << std::endl;

		Pockets.push(Spoon);

		spoonTaken = true;

		changeStage(3);
	}
	// STAGE 4 END

	// STAGE 5 START
	//Butter knife
	else if (stage == 5 && object == W_KNIFEB && command == "INSPECT")
	{
		std::cout << " A butter knife you used to open letters that you receive back when... you had friends.." << std::endl;
	}
	else if (stage == 5 && object == W_KNIFEB && command == "TAKE")
	{
		std::cout << " You take the butter knife and put it in your pocket." << std::endl;
		Pockets.push(ButterKnife);
		butterTaken = true;
	}
	//GO BACK
	else if (stage == 5 && command == "GO" && object == BACK)
	{
		changeStage(2);
	}
	// STAGE 5 END

	// STAGE 7 START
	//Bathroom
	else if (stage == 7 && object == BATHROOM && command == "WALK")
	{
		std::cout << " You walk to the bathroom.." << std::endl;

		if (!storyBathroom)
			changeStage(9);
		else
			changeStage(10);
    }
	//Kitchen
	else if (stage == 7 && object == KITCHEN && command == "WALK")
	{
		std::cout << " You walk to the kitchen.." << std::endl;

		if (!storyKitchen)
			changeStage(12);
		else
			changeStage(13);
	}
	//Bedroom
	else if (stage == 7 && object == BEDROOM && command == "WALK")
	{
		std::cout << " You walk to the bedroom.." << std::endl;

		changeStage(2);
	}
	//Painting
	else if (stage == 7 && object == PAINTING && command == "INSPECT")
	{
		if (!pictureMoved)
		{
			std::cout << " You start to admire the painting.." << std::endl;

			changeStage(8);
		}
		else
			std::cout << " The painting sits on the floor, you look at the numbers on the wall instead: 9510" << std::endl;
	}
	//Door
	else if (stage == 7 && object == DOOR && command == "INSPECT")
	{
		std::cout << " Your way of getting food, as you don't remember last time someone walked through it.." << std::endl;
	}
	else if (stage == 7 && object == DOOR && command == "WALK")
	{
		std::cout << " Food delivery doesn't come till Monday, why would you go to the entrance?" << std::endl;
	}
	// STAGE 7 END
	
	// STAGE 8 START
	//Painting
	else if (!pictureMoved && stage == 8 && object == PAINTING && command == "MOVE")
	{
		std::cout << " You take the painting and put it on the floor."
			" When you look at the spot it was on, you notice four numbers: 9510" << std::endl;
		pictureMoved = true;

		changeStage(7);
	}
	else if (stage == 8 && command == "GO" && object == BACK)
	{
		changeStage(7);
	}
	// STAGE 8 END

	// STAGE 10 START
	//Door
	else if (stage == 10 && object == DOOR && (command == "USE" || command == "OPEN"))
	{
		std::cout << " You walk out of bathroom.." << std::endl;
		changeStage(7);
	}
	//Toilet
	else if (stage == 10 && object == TOILET && command == "USE")
	{
		std::cout << " \"It's not the time yet..\" you think and then correct yourself \n \"I mean, I don't want to go yet... Why am I talking to myself so much today?\" " << std::endl;
	}
	else if (stage == 10 && object == TOILET && command == "INSPECT")
	{
	if (!kitchenTaken)
	{
		std::cout << " You move closer to the toilet.." << std::endl;
		changeStage(11);
	}
	else
		std::cout << " Ye old white throne.." << std::endl;
	}
	//Mirror
	else if (stage == 10 && object == MIRROR && command == "USE")
	{
		std::cout << " You look at yourself in the mirror... Yep, still looking good. " << std::endl;
	}
	else if (stage == 10 && object == MIRROR && command == "INSPECT")
	{
		std::cout << " A standard-issue Mirror&Cabinet for all your bathroom utensils. " << std::endl;
	}
	else if (stage == 10 && object == MIRROR && command == "OPEN")
	{
			std::cout << " You open the mirror cabinet and don't see anything that you would need.." << std::endl;
	}
	// STAGE 10 END

	// STAGE 11 START
	//Knife
	else if (stage == 11 && object == W_KNIFEK && command == "TAKE")
	{
		std::cout << " You take the knife, wipe it with a towel and put it in a pocket, furthest away from your groin." << std::endl;

		Pockets.push(KitchenKnife);
		kitchenTaken = true;

		changeStage(10);
	}
	// STAGE 11 END

	// STAGE 13 START
	//Countertop
	else if (stage == 13 && object == COUNTERTOP && command == "INSPECT")
	{
		std::cout << " You move closer to the countertop.." << std::endl;
		changeStage(14);
	}
	//Fridge
	else if (stage == 13 && object == FRIDGE && command == "OPEN")
	{
		if (!keyUsed)
			std::cout << " The fridge door won't budge.." << std::endl;
		else
		{
			std::cout << " You open the fridge door and look inside.." << std::endl;
			changeStage(15);
		}
	}
	else if (stage == 13 && object == FRIDGE && command == "INSPECT")
	{
		std::cout << " You move closer to the fridge.." << std::endl;
		changeStage(15);
	}
	//Drawer
	else if (stage == 13 && object == DRAWER && command == "OPEN")
	{
		if (!breadTaken)
		{
			std::cout << " You open the drawer and find a bread knife inside.\n \"That will come in handy\" - you think, and put it in your pocket." << std::endl;
			Pockets.push(BreadKnife);
			breadTaken = true;
		}
		else
			std::cout << " You open the drawer and close it back, as there's nothing of use left in it." << std::endl;
	}
	else if (stage == 13 && object == DRAWER && command == "INSPECT")
	{
		std::cout << " A kitchen drawer used for storing utensils in it.." << std::endl;
	}
	//Cabinet
	else if (stage == 13 && object == CABINET && command == "OPEN")
	{
		if (!spoonUsed)
		{
			std::cout << " It doesn't open fully, like something holding it. Maybe if you stick something in the opening you can pry it open?"
				"\n Wouldn't want to break my britle knives however.." << std::endl;
		}
		else
		{
			std::cout << " You open the cabinet and look inside." << std::endl;
			changeStage(18);
		}
	}
	else if (stage == 13 && object == CABINET && command == "INSPECT")
	{
		std::cout << " You walk up to the cabinet." << std::endl;
		changeStage(18);
	}
	//Door
	else if (stage == 13 && object == DOOR && command == "OPEN")
	{
		std::cout << " You walk out of the kitchen.." << std::endl;

		changeStage(7);
	}
	else if (stage == 13 && object == DOOR && command == "INSPECT")
	{
		std::cout << " A door that leads back to the hallway... Yep, no open plan.." << std::endl;
	}
	// STAGE 13 END

	// STAGE 14 START
	//Rolling Pin
	else if (stage == 14 && object == W_ROLLING && command == "INSPECT")
	{
		std::cout << " A wooden rolling pin." << std::endl;
	}
	else if (stage == 14 && object == W_ROLLING && command == "TAKE" && !rollingTaken)
	{
		std::cout << " You take the rolling pin and put in the largest pocket you have." << std::endl;
		Pockets.push(RollingPin);
		rollingTaken = true;
	}
	//Cutting Board
	else if (stage == 14 && object == CUTTING_BOARD && command == "INSPECT")
	{
		if (butterUsed || kitchenUsed || breadUsed)
		{
			std::cout << " For a sandwich you need three things, out of those three things on the board you can see: " << butter << bread << sausage << std::endl;
		}
		else
		std::cout << " A wooden cutting board with nothing on it. Perfect workbench for a sandwich." << std::endl;
	}
	else if (stage == 14 && object == CUTTING_BOARD && command == "TAKE")
	{
		std::cout << " Pockets have their limits, come on." << std::endl;
	}
	//GO BACK
	else if (stage == 14 && object == BACK && command == "GO")
	{
		std::cout << " You walk away from the countertop.." << std::endl;
		changeStage(13);
	}
	//Final
	else if ((butterUsed && breadUsed && kitchenUsed) && stage == 14 && object == SANDWICH && command == "MAKE")
	{
		std::cout << " You combine the ingridients.." << std::endl;
		changeStage(20);
	}
	// STAGE 14 END

	// STAGE 15 START
	//Padlock
	else if (!keyUsed && stage == 15 && object == PADLOCK && command == "INSPECT")
	{
		std::cout << " Metal padlock with a keyhole in it.." << std::endl;
	}
	else if ((!keyUsed && keyTaken) && stage == 15 && object == W_KEY && command == "USE")
	{
		std::cout << " You unlock the padlock with the key.." << std::endl;

		keyUsed = true;
	}
	//Butter
	else if (keyUsed && stage == 15 && object == BUTTER && command == "INSPECT")
	{
		std::cout << " You focus on the stick of butter.." << std::endl;
		changeStage(17);
	}
	//Box
	else if (keyUsed && stage == 15 && object == BOX && command == "INSPECT")
	{
		std::cout << " You take the box into your hands.." << std::endl;
		changeStage(16);
	}
	// STAGE 15 END

	// STAGE 16 START
	//Kitchen knife
	else if (stage == 16 && object == W_KNIFEK && command == "USE")
	{
		std::cout << " You take the sausage to the cutting board and cut it up in nice slices." << std::endl;

		sausage = "  /Sausage/  ";

		//Pockets.pop(KitchenKnife);
		kitchenUsed = true;
		changeStage(13);
	}
	//GO BACK
	else if (stage == 16 && object == BACK && command == "GO")
	{
		std::cout << " You put the box back on the fridge shelf." << std::endl;
		changeStage(15);
	}
	// STAGE 16 END
	
	// STAGE 17 START
	//Butter knife
	else if ((!butterUsed && butterTaken) && stage == 17 && object == W_KNIFEB && command == "USE")
	{
		if (!rollingUsed)
			std::cout << " The butter slips out of your hands and goes back to it's corner...\n Maybe you could stun it with something? " << std::endl;
		else
		{
			std::cout << " You start slicing the butter while it's stunned and when the deed is done, you place it on the cutting board. " << std::endl;

			butterUsed = true;
			//Pockets.pop(ButterKnife);

			butter = "  /Butter/  ";

			changeStage(13);
		}
	}
	//Rolling pin
	else if ((!rollingUsed && rollingTaken) && stage == 17 && object == W_ROLLING && command == "USE")
	{
		std::cout << " You wait for the right moment... And strike the butter with the rolling pin!\n It let's a out a quiet moan and rests stunned. " << std::endl;
		
		rollingUsed = true;
		//Pockets.pop(RollingPin);
		changeStage(17);
	}
	// STAGE 17 END

	// STAGE 18 START
	//Cabinet
	else if (stage == 18 && object == CABINET && command == "INSPECT")
	{
		if (!spoonUsed)
			std::cout << " A wooden kitchen cabinet.\n Doors don't fully open, as if something doesn't let them.." << std::endl;
		else
			std::cout << " A wooden kitchen cabinet that was once served as a lair for the bread." << std::endl;
	}
	//Spoon
	else if ((!spoonUsed && spoonTaken) && stage == 18 && object == W_SPOON && command == "USE")
	{
		std::cout << " You stick the spoon in the opening and use it like a crowbar, opening the doors. " << std::endl;

		spoonUsed = true;
		//Pockets.pop(Spoon);
	}
	else if ((spoonUsed && !breadUsed) && stage == 18 && object == W_BREADKNIFE && command == "USE")
	{
		std::cout << " You firmly grab the bread and start cutting it on the board...\n While cutting you hit something hard inside.. It's a key?\n You put it in your pocket. " << std::endl;
		//Pockets.pop(BreadKnife);
		breadUsed = true;

		bread = "  /Bread/  ";

		Pockets.push(Key);
		keyTaken = true;

		changeStage(14);
	}
	else if ((spoonUsed && spoonTaken) && stage == 18 && object == BREAD && command == "INSPECT")
	{
		std::cout << " A loaf of bread. Snarling at you.\n Nothing out of the ordinary, except the snarling. " << std::endl;
	}
	//GO BACK
	else if (stage == 18 && object == BACK && command == "GO")
	{
		std::cout << " You move back. " << std::endl;

		changeStage(13);
	}
	// STAGE 18 END

	else
	{
		std::cout << " Nah, that doesn't make much sense..." << std::endl;
	}
}

OBJECTS strToObject(std::string word)
{
	if (word == "INVENTORY")
		return INVENTORY;
	if (word == "BACK")
		return BACK;
	else if (word == "BED")
		return BED;
	else if (word == "BUTTON")
		return BUTTON;
	else if (word == "BOWL")
		return BOWL;
	else if (word == "BOX")
		return BOX;
	else if (word == "BUTTER KNIFE")
		return W_KNIFEB;
	else if (word == "BREAD KNIFE")
		return W_BREADKNIFE;
	else if (word == "BATHROOM")
		return BATHROOM;
	else if (word == "BEDROOM")
		return BEDROOM;
	else if (word == "BUTTER")
		return BUTTER;
	else if (word == "BREAD")
		return BREAD;
	else if (word == "DRAWER")
		return DRAWER;
	else if (word == "DOOR")
		return DOOR;
	if (word == "DESKTOP")
		return DESKTOP;
	else if (word == "COMPUTER")
		return COMPUTER;
	else if (word == "COUNTERTOP")
		return COUNTERTOP;
	else if (word == "CABINET")
		return CABINET;
	else if (word == "CUTTING BOARD")
		return CUTTING_BOARD;
	else if (word == "WARDROBE")
		return WARDROBE;
	else if (word == "SPOON")
		return W_SPOON;
	else if (word == "PAINTING")
		return PAINTING;
	else if (word == "PADLOCK")
		return PADLOCK;
	else if (word == "KITCHEN")
		return KITCHEN;
	else if (word == "KITCHEN KNIFE")
		return W_KNIFEK;
	else if (word == "KEY")
		return W_KEY;
	else if (word == "TOILET")
		return TOILET;
	else if (word == "MIRROR")
		return MIRROR;
	else if (word == "SHOWER")
		return SHOWER;
	else if (word == "SAUSAGE")
		return SAUSAGE;
	else if (word == "SANDWICH")
		return SANDWICH;
	else if (word == "ROLLING PIN")
		return W_ROLLING;
	else if (word == "FRIDGE")
		return FRIDGE;
}