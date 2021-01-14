#pragma once
#include <iostream>
#include <string>

using namespace std;


class Platforms
{
private:
	string m_name;
	string m_manufacturer;
public:
	void GetName(string namePlatform)
	{
		m_name = namePlatform;
	}

	void GetManufacturer(string nameManu)
	{
		m_manufacturer = nameManu;
	}

	void CreateGameArray(int amount)
	{


	}
};

class Games
{
private:
	string m_name;
	string m_publisher;
	string m_developer;
public:
	void GetName(string nameGame)
	{
		m_name = nameGame;
	}

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



	}
};

class Achievments
{
private:
	string m_title;
	string m_description;
	int m_score;
public:
	void GetTitle(string nameTitle)
	{
		m_title = nameTitle;
	}

	void GetDescription(string descr)
	{
		m_description = descr;
	}

	void GetScore(int amount)
	{
		m_score = amount;
	}
};