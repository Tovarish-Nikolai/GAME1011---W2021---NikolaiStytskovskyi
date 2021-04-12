#pragma once
#include "Utilities.h"

using namespace std;

void PlayStage(int stage)
{
	if (stage == 0)
	{
			system("CLS");

			cout << "     ##################" << endl;
			cout << "     # SANDWICH QUEST #" << endl;
			cout << "     ##################" << endl;

			cout << "\n\n";
			cout << "     All operations are performed by entering" << endl;
			cout << "             two word commands in upper case." << endl;
			cout << "     First the action then the object." << endl;
			cout << " \n    Type in ACCESS and INVENTORY to view what you have on yourself." << endl;

			cout << "\n\n\n";
			cout << "           _______" << endl;
			cout << "          |       |" << endl;
			cout << "          | START |" << endl;
			cout << "          |       |" << endl;
			cout << "          |_______|" << endl;


			cout << "\n\n";
			cout << "     Hint:" << endl;
			cout << "         try \"PRESS BUTTON\"" << endl;

			getline(cin, action);
			getline(cin, object);

			ExecuteCommand(action, strToObject(object));

			system("pause");
	}


	else if (stage == 1)
	{
			system("CLS");

			fstream story;

			story.open("Story/Story_0.txt");

			cout << "\n\n";

			while (!story.eof())
			{
				getline(story, storyDialog);

				cout << "\n" << storyDialog;
				this_thread::sleep_for(chrono::milliseconds(2000));

			}
			cout << "\n\n";
			system("pause");

			story.close();
			story.open("Story/Story_1.txt");

			system("CLS");
			cout << "\n\n";

			while (!story.eof())
			{
				getline(story, storyDialog);
				
				cout << "\n" << storyDialog;
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
			
			story.close();

			cout << "\n\n";
			system("pause");

			changeStage(2);
	}


	else if (stage == 2)
	{
			system("CLS");

			if (!storyRoom)
				cout << "  And there you are, standing in the middle of your room." << endl;
			else
				cout << "  You're standing in the middle of your room." << endl;

			storyRoom = true;

			cout << "\n\n * In your vicinity are: DRAWER, DESKTOP, WARDROBE, BED, DOOR *" << endl;

			cout << "\n\n # KEYWOPRDS : OPEN, USE, INSPECT # \n" << endl;

			getline(cin, action);
			getline(cin, object);

			ExecuteCommand(action, strToObject(object));

			system("pause");

	}

	else if (stage == 3)
	{
			system("CLS");

			cout << " You look at all the chaos happening on your table." 
				"\n Pens and pencils everywere, random pieces of paper, wrappers from candybars and other rubbish.." << endl;

			cout << "\n\n * DIRECTIONS: BACK *" << endl;

			cout << "\n\n * You see: COMPUTER, BOWL *" << endl;

			cout << "\n\n # KEYWOPRDS : GO, USE, INSPECT # \n" << endl;

			getline(cin, action);
			getline(cin, object);

			ExecuteCommand(action, strToObject(object));

			system("pause");
	}

	else if (stage == 4)
	{
			if (!spoonTaken)
			{
				system("CLS");

				cout << "  You see a cereal bowl left from yesterday. There's a spoon in it." << endl;

				cout << "\n\n * You see: SPOON *" << endl;

				cout << "\n\n # KEYWOPRDS : TAKE, INSPECT # \n" << endl;

				getline(cin, action);
				getline(cin, object);

				ExecuteCommand(action, strToObject(object));

				system("pause");
			}
			else
				changeStage(3);
	}

	else if (stage == 5)
	{
		if (!butterTaken)
		{
			system("CLS");

			cout << "  There's a lot of mess on your desk, but even more in your drawer.." << endl;

			cout << "\n\n * DIRECTIONS: BACK *" << endl;

			cout << "\n\n * You see: BUTTER KNIFE *" << endl;

			cout << "\n\n # KEYWOPRDS : GO, TAKE, INSPECT # \n" << endl;

			getline(cin, action);
			getline(cin, object);

			ExecuteCommand(action, strToObject(object));

			system("pause");
		}
		else
			changeStage(2);
	}

	else if (stage == 6)
	{
		system("CLS");

		fstream story;

		story.open("Story/Story_2.txt");

		cout << "\n\n";

		while (!story.eof())
		{
			getline(story, storyDialog);

			cout << "\n" << storyDialog;
			this_thread::sleep_for(chrono::milliseconds(2000));

		}
		cout << "\n\n";

		story.close();

		system("pause");

		storyHallway = true;

		changeStage(7);
	}

	else if (stage == 7)
	{
		system("CLS");

		cout << "  You're standing in the hallway.." << endl;

		cout << "\n\n * DIRECTIONS: BATHROOM, KITCHEN, BEDROOM *" << endl;

		cout << "\n\n * You see: PAINTING, DOOR *" << endl;

		cout << "\n\n # KEYWOPRDS : WALK, INSPECT # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 8)
	{
		system("CLS");

		cout << " A painting that came with the flat, has some abstract something on it,"
			"\n which is oddly satisfying to look at." << endl;

		cout << "\n\n * DIRECTION: BACK *" << endl;

		cout << "\n\n * You see: PAINTING *" << endl;

		cout << "\n\n # KEYWOPRDS : GO, MOVE # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 9)
	{
		system("CLS");

		fstream story;

		story.open("Story/Story_3.txt");

		cout << "\n\n";

		while (!story.eof())
		{
			getline(story, storyDialog);

			cout << "\n" << storyDialog;
			this_thread::sleep_for(chrono::milliseconds(2000));

		}
		cout << "\n\n";

		story.close();

		system("pause");

		storyBathroom = true;
		changeStage(10);
	}

	else if (stage == 10)
	{
		system("CLS");

		cout << " You are standing in your bathroom.." << endl;

		cout << "\n\n * You see: TOILET, MIRROR, DOOR *" << endl;

		cout << "\n\n # KEYWOPRDS : OPEN, USE, INSPECT # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 11)
	{
		system("CLS");

		cout << " Ye old white throne.. But it appears there's a.. Kitchen knife in the bowl. Did someone-or-thing tried to flush it? " << endl;

		cout << "\n\n * You see: KNIFE *" << endl;

		cout << "\n\n # KEYWOPRDS : TAKE # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 12)
	{
		system("CLS");

		fstream story;

		story.open("Story/Story_4.txt");

		cout << "\n\n";

		while (!story.eof())
		{
			getline(story, storyDialog);

			cout << "\n" << storyDialog;
			this_thread::sleep_for(chrono::milliseconds(2000));

		}
		cout << "\n\n";

		story.close();

		system("pause");

		storyKitchen = true;

		changeStage(13);
	}

	else if (stage == 13)
	{
		system("CLS");

		cout << " You are in the kitchen.. " << endl;

		cout << "\n\n * You see: DOOR, COUNTERTOP, FRIDGE, DRAWER, CABINET *" << endl;

		cout << "\n\n # KEYWOPRDS : OPEN, INSPECT # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 14)
	{
		system("CLS");

		if (butterUsed && breadUsed && kitchenUsed)
			cout << " You are looking at all the ingridients for the sandwich, laying on the cutting board... It's time. " << std::endl;
		else
			cout << " You are looking at the countertop.. " << endl;

		cout << "\n\n * DIRECTIONS: BACK *" << endl;

		if (!rollingTaken)
			cout << "\n\n * You see: ROLLING PIN, CUTTING BOARD *" << endl;
		else
			cout << "\n\n * You see: CUTTING BOARD *" << endl;

		cout << "\n\n # KEYWOPRDS : GO, TAKE, INSPECT # \n" << endl;

		if (butterUsed && breadUsed && kitchenUsed)
			cout << "\n\n # Final : MAKE SANDWICH # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 15)
	{
		system("CLS");

		if (!keyUsed)
			cout << " You are looking at the fridge. \"Where did this padlock come from?\" - you think.\n It seems you will need to find a key for it. " << endl;
		else 
			cout << " You're looking inside your fridge. " << std::endl;

	
		cout << "\n\n * DIRECTIONS: BACK *" << endl;

		if (!keyUsed)
			cout << "\n\n * You see: PADLOCK *" << endl;
		else if (!butterUsed && !kitchenUsed)
			cout << "\n\n * You see: BUTTER, BOX *" << endl;
		else if (!butterUsed && kitchenUsed)
			cout << "\n\n * You see: BUTTER *" << endl;
		else if (butterUsed && !kitchenUsed)
			cout << "\n\n * You see: BOX *" << endl;

		if (!butterUsed || !kitchenUsed)
			cout << "\n\n # KEYWOPRDS : GO, INSPECT # \n" << endl;
		else if (butterUsed || kitchenUsed)
			cout << "\n\n # KEYWOPRDS : GO # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 16)
	{
		system("CLS");
		if (!pictureUsed)
		{
			cout << " You are holding a sturdy plastic box with dial on it. Should you enter a code? " << endl;

			cout << "\n\n # ENTER CODE # \n" << endl;

			cin >> attempt;

			if (attempt == code)
			{
				cout << " The lid opens and you see a snoring sausage in it. Interesting..." << endl;
				pictureUsed = true;
			}
			else
			{
				cout << " No luck.. Better look for the code, maybe it's somewhere around here." << endl;
				changeStage(15);
			}
		}
		else
		{
			cout << " You are holding a sturdy plastic box with a sausage in it.. " << endl;

			cout << "\n\n * DIRECTIONS: BACK *" << endl;

			cout << "\n\n # KEYWOPRDS : GO, USE # \n" << endl;

			getline(cin, action);
			getline(cin, object);

			ExecuteCommand(action, strToObject(object));
		}
		system("pause");
	}

	else if (stage == 17)
	{
		system("CLS");

		cout << " You are looking at a completely normal stick of butter hiding in the corner...\n Except the fact that it hisses like a cat at you... " << endl;
		
		cout << "\n\n * You see: BUTTER *" << endl;

		cout << "\n\n # KEYWOPRDS : USE # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 18)
	{
		system("CLS");

		if (!spoonUsed)
			cout << " You're looking at the closed cabinet. Do you hear snarling behind the doors? " << endl;
		else if (spoonUsed && !breadUsed)
			cout << " You're looking inside the cabinet and see a loaf of bread snarling at you. " << std::endl;
		else if (spoonUsed && breadUsed)
			cout << " You're looking inside the cabinet and admire the nothingness inside. " << std::endl;


		cout << "\n\n * DIRECTIONS: BACK *" << endl;

		if (!spoonUsed)
			cout << "\n\n * You see: CABINET *" << endl;
		else if (spoonUsed && !breadUsed)
			cout << "\n\n * You see: BREAD *" << endl;

		if (!spoonUsed || !breadUsed)
			cout << "\n\n # KEYWOPRDS : GO, INSPECT, USE # \n" << endl;
		else if (spoonUsed && breadUsed)
			cout << "\n\n # KEYWOPRDS : GO # \n" << endl;

		getline(cin, action);
		getline(cin, object);

		ExecuteCommand(action, strToObject(object));

		system("pause");
	}

	else if (stage == 20)
	{
		system("CLS");

		fstream story;

		story.open("Story/Story_5.txt");

		cout << "\n\n";

		while (!story.eof())
		{
			getline(story, storyDialog);

			cout << "\n" << storyDialog;
			this_thread::sleep_for(chrono::milliseconds(2000));

		}
		cout << "\n\n";

		story.close();

		system("pause");

		running = false;
	}
}