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
	playersNumber = 11;
	teamWinsCounter = 0;
}

Team::Team(string _color) {
	playersNumber = 11;
	teamWinsCounter = 0;

	_color = checkColor(_color);
	color = _color;

	Player player[11];
}

Team::~Team() {
	//cout << "Class Team is destroyed!" << endl;
}

void Team::setPlayer(Player* player, int counter, string _team) {
	string name, sex, occupation;
	int age;
	cout << "\t\t\t\t\ttype Name, Age, Sex, Occupation of the player" << endl;
	cin >> name;
	cin >> age;
	cin >> sex;
	cin >> occupation;

	player[counter].setName(name);
	player[counter].setAge(age);
	player[counter].setSex(sex);
	player[counter].setOccupation(occupation);
	player[counter].setColor(_team);
}

void Team::getPlayer(Player* player, int counter) {
	player[counter].playerStatus();
}

void Team::teamWins() {
	teamWinsCounter++;
}
