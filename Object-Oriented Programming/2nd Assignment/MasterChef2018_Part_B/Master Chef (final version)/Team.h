#pragma once
//Karakostas Konstantinos    7892      karakosk@ece.auth.gr
//Koseoglou Sokratis         8837      Sokrkose@ece.auth.gr

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <string>
#include "Player.h"

using namespace std;

class Team {

private:
	int playersNumber;
	int teamsWinsCounter;
	Player* players[11];
	string color;
	int numberOfSupplies;

public:
	//Constructors
	Team();
	Team(string color);

	//Destructor
	~Team();

	//-----Getters and Setters----------------
	//playersNumber
	int getPlayersNumber();
	void setPlayersNumber(int playersNumber);

	//teamsWinsCounter
	int getTeamsWinsCounter();
	void setTeamsWinsCounter(int teamsWinsCounter);

	//players
	Player* getPlayers(int index);
	void setPlayers(Player* player, int index);

	//color
	string getColor();
	void setColor(string color);

	//numberOfSupplies
	int getNumberOfSupplies();
	void setNumberOfSupplies(int numberOfSupplies);
	//----End of Getters/Setters.

	//Some limitation-check methods
	bool checkNumber(int number);
	string checkColor(string color);
	void teamsWins();
};

#endif // TEAM_H_INCLUDED
