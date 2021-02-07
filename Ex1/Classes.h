#pragma once
#include <iostream>
#include <string>

using namespace std;

class Achievment
{
private:
	string m_title;
	string m_description;

	int m_score;
public:
	//constructor
	Achievment(string title = "Random Title", string description = "A random Description", int score = 10)
	{
		m_title = title;
		m_description = description;
		m_score = score;
	}

	void CreateAchievmentObj(string title, string description, int score)
	{
		m_title = title;
		m_description = description;
		m_score = score;
	}


	//getters
	string GetTitle()
	{
		return m_title;
	}

	string GetDescription()
	{
		return m_description;
	}

	int GetScore()
	{
		return m_score;
	}


	//~Achievment();
};

class Game
{
private:
	string m_name;
	string m_publisher;
	string m_developer;

	int m_AchievmentAmount = 0;
	int m_AchievmentArraySize = 200;
public:
	Game(string name = "RandomName", string publisher = "Random Publisher", string developer = "RandomDeveloper", int amount = 4)
	{
		m_name = name;
		m_publisher = publisher;
		m_developer = developer;
		m_AchievmentAmount = amount;
	}
	//for pointer creation
	void CreateGameObj(string name, string publisher, string developer)
	{
		m_name = name;
		m_publisher = publisher;
		m_developer = developer;
	}


	//getters
	string GetName()
	{
		return m_name;
	}

	string GetPublisher()
	{
		return m_publisher;
	}

	string GetDev()
	{
		return m_developer;
	}

								//Achievment part
	Achievment* pAPtr = new Achievment[m_AchievmentArraySize];

	//main glitch, don't know what to do
	void AddToAchievmentArray(int pos, Achievment* obj)
	{
		pAPtr[pos] = *obj;
	}

	Achievment* AccessAchievmentArray(int pos)
	{
		return &pAPtr[pos];
	}

	void DeleteAchievmentArray(Achievment* ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}

	//does work apparently
	void SetAchievmentAmount(int amount)
	{
		m_AchievmentAmount = amount;
	}

	int GetAchievmentAmount()
	{
		return m_AchievmentAmount;
	}

	//~Game();
};

class Platform
{
private:
	string m_name;
	string m_manufacturer;

	int m_GameArraySize = 200; //I gave up.
	//Game* pGPtr = nullptr;
public:
	//constructor
	Platform(string name, string manufacturer)
	{
		m_name = name;
		m_manufacturer = manufacturer;
	}

	//getters
	string GetName()
	{
		return m_name;
	}

	string GetManufacturer()
	{
		return m_manufacturer;
	}

									//Game part
	
	void ChangeSize(int size) //I tried.
	{
		m_GameArraySize = size;
	}

	//creating a Game array
	Game* pGPtr = new Game[m_GameArraySize];

	void AddToGameArray(int pos,Game* obj)
	{
		pGPtr[pos] = *obj;
	}
	//accessing it
	Game* AccessGameArray(int pos)
	{
		return &pGPtr[pos];
	}

	//just for show, crashes the system
	void DeleteGameArray(Game* ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}


	//~Platform();
};