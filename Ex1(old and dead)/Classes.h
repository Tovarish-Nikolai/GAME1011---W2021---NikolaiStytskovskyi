#pragma once
#include <iostream>
#include <string>

using namespace std;


class Platform
{
private:
	string m_name;
	string m_manufacturer;
public:
	
	Platform(string name, string manufacturer)
	{
		m_name = name;
		m_manufacturer = manufacturer;
	}

	Game* m_pGame = new Game();

	void CreatePlatformObj(string name, string manufacturer)
	{

	}


	string GetName()
	{
		return m_name;
	}

	string GetManufacturer()
	{
		return m_manufacturer;
	}




	Game *array = new Game[];

	void AddToGameArray(Game* obj, int pos)
	{
		array[pos] = *obj;
	}

	void DeleteGameArray(Game *pointer)
	{
		delete pointer;
		delete[] pointer;
	}
};

class Game
{
private:
	string m_name;
	string m_publisher;
	string m_developer;
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





	void CreateAchievmentArray(int amount)
	{
		Achievment* array;
		array = new Achievment[amount];
	}
	
	void DeleteAchievmentArray(int* pointer)
	{
		delete pointer;
		delete[] pointer;
	}
};

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
};