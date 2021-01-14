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
	//Make a constructor you fucking idiot, for all of them
	//why do you even write in English if you're only writing it for yourself?
	//wait, why do you even talk to yourself
	//you need to see a doctor dude
	//да уж, мне реально очень нужно поспать, пожалуй пойду займусь этим 

	string GetName()
	{
		return m_name;
	}

	void GetManufacturer(string nameManu)
	{
		m_manufacturer = nameManu;
	}

	void CreateGameArray(int amount)
	{
		int* array;
		array = new int[amount];
	}

	void DeleteGameArray(int *pointer)
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
	

	void GetPublisher(string namePublish)
	{
		m_publisher = namePublish;
	}

	void GetDev(string nameDev)
	{
		m_developer = nameDev;
	}

	void CreateAchievmentArray(int amount)
	{
		int* array;
		array = new int[amount];
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
	

	void GetDescription(string descr)
	{
		m_description = descr;
	}

	void GetScore(int amount)
	{
		m_score = amount;
	}
};