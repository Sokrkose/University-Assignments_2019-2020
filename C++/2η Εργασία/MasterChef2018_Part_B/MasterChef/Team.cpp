#include "Player.h"
#include "Team.h"
#include <iostream>
#include <string>

using namespace std;

string checkColor(string _variable) {
	while(_variable != "red" && _variable != "blue") {
		cout << "\t\t\t\t\tYou entered FALSE color...please enter 'red' or 'blue'" << endl;
		cin >> _variable;
	}
	return _variable;
}

Team::Team() {
	playersNumber = 0;			  // it has initial value '0' since the user adds players in the first assignment!
	teamWinsCounter = 0;
}

Team::Team(string _color) {
	playersNumber = 0;            // it has initial value '0' since the user adds players in the first assignment!
	teamWinsCounter = 0;

	_color = checkColor(_color);
	color = _color;
}

Team::~Team() {
	//cout << "Class Team is destroyed!" << endl;
}

void Team::setPlayer(Team* team) {
	string name, sex, occupation;
	int age;
	cout << "\t\t\t\t\ttype Name, Age, Sex, Occupation of the player" << endl;
	cin >> name;
	cin >> age;
	cin >> sex;
	cin >> occupation;

	string _color = team->color;
	int i = team->playersNumber - 1;

	team->player[i].setName(name);
	team->player[i].setAge(age);
	team->player[i].setSex(sex);
	team->player[i].setOccupation(occupation);
	team->player[i].setColor(_color);
}

void Team::getPlayer(Team* team, int counter) {
	team->player[counter].playerStatus();
}

string Team::getPlayerName(Team* team, int counter) {
	return team->player[counter].getName();

}

void Team::teamWins() {
	teamWinsCounter++;
}
