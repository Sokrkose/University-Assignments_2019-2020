#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class Team : public Player {

	int playersNumber;
	int teamWinsCounter;
	Player player[11];
	string color;

public:
	Team();
	Team(string _color);
	~Team();

	/* Inline Setters */

	void setPlayersNumber(int _playersNumber) { playersNumber = _playersNumber; }
	void setTeamWinsCounter(int _teamWinsCounter) { teamWinsCounter = _teamWinsCounter; }
	void setColor(string _color) { color = _color; }
	void setPlayer(Team* team);

	/* Inline Getters */

	int getPlayersNumber(void ) { return playersNumber; }
	int getTeamWinsCounter(void ) { return teamWinsCounter; }
	string getColor(void ) { return color; }
	void getPlayer(Team* ,int );
	string getPlayerName(Team*, int);

	/* Public Finctions */

	void teamWins();

};

#endif // TEAM_H_INCLUDED
