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

	Achievment* pAPtr = nullptr;
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
	void CreateAchievmentArray(int size)
	{
		pAPtr = new Achievment[size];
	}

	void DeleteAchievmentArray(Achievment* ptr)
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

	Game* pGPtr = nullptr;
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

	void CreateGameArray(int size)
	{
		pGPtr = new Game[size];
	}

	void AddToGameArray(Game array[], int pos,Game obj)
	{
		array[pos] = obj;
	}

	void DeleteGameArray(Game* ptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}


	//~Platform();
};