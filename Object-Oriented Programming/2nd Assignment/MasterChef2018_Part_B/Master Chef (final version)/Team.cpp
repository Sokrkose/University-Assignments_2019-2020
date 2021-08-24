//Karakostas Konstantinos    7892      karakosk@ece.auth.gr
//Koseoglou Sokratis         8837      Sokrkose@ece.auth.gr

#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Team.h"
#include <string>

using namespace std;

//Constructors
Team::Team() {
	playersNumber = 0;
	teamsWinsCounter = 0;
	numberOfSupplies = 0;
	for (int i = 0; i < 11; i++) {
		players[i] = new Player();
	}
	color = "Blue";
}

Team::Team(string color) :Team(){
	//This constructor calls the other constructor
	this->color = checkColor(color);
}

// Destructor
Team::~Team(){
}

//------Getters and setters------------------

//PlayersNumber
int Team::getPlayersNumber() {
	return playersNumber;
};
void Team::setPlayersNumber(int playersNumber) {
	this->playersNumber = playersNumber;
}

//TeamsWinsCounter
int Team::getTeamsWinsCounter() {
	return teamsWinsCounter;
};
void Team::setTeamsWinsCounter(int teamsWinsCounter) {
	this->teamsWinsCounter = teamsWinsCounter;
}

//Color
string Team::getColor() {
	return color;
};
void Team::setColor(string color) {
	this->color = color;
};

//NumberOfSupplies
int Team::getNumberOfSupplies() {
    return numberOfSupplies;
};
void Team::setNumberOfSupplies(int numberOfSupplies) {
		this->numberOfSupplies = numberOfSupplies;
};

//Players array
Player* Team::getPlayers(int index) {
	if (checkNumber(index)) {
		return players[index];
	}
	else return NULL;
};
void Team::setPlayers(Player* player, int index) {
	if (checkNumber(index)) {
		players[index] = player;
	}
};

//----End of Getters/Setters.------

// Some limitations-check methods

bool Team::checkNumber(int number) {
	/* Checks if number of players doesn't exceed 11.
	   Returns false if they do exceed.
	*/
	if (number < 0 || number > 11) {
		return false;
	}
	else {
		return true;
	}
}

string Team::checkColor(string color) {
	/* Checks if color is only Blue or Red. Returns blue
	   if otherwise*/

	if (color == "Blue" || color == "Red") {
		return color;
	}
	else {
		return "Blue";
	}
}

void Team::teamsWins() {
	/* Increases the team's wins counter*/
	teamsWinsCounter++;
};

//End of "some" limitations-check methods
