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

	int m_AchievmentArraySize = 200;
public:
	Game(string name = "RandomName", string publisher = "Random Publisher", string developer = "RandomDeveloper")
	{
		m_name = name;
		m_publisher = publisher;
		m_developer = developer;
	}

	void CreateGameObj(string name, string publisher, string developer)
	{
		m_name = name;
		m_publisher = publisher;
		m_developer = developer;
	}



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

	void AddToAchievmentArray(int pos, Achievment* obj)
	{
		pAPtr[pos] = *obj;
	}

	Achievment AccessGameArray(int pos)
	{
		return pAPtr[pos];
	}

	void DeleteGameArray(Achievment* ptr)
	{
		delete[] ptr;
		ptr = nullptr;
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

	Platform(string name, string manufacturer)
	{
		m_name = name;
		m_manufacturer = manufacturer;
	}


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


	Game* pGPtr = new Game[m_GameArraySize];

	void AddToGameArray(int pos,Game* obj)
	{
		pGPtr[pos] = *obj;
	}

	Game AccessGameArray(int pos)
	{
		return pGPtr[pos];
	}
	void DeleteGameArray(Game* ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}


	//~Platform();
};