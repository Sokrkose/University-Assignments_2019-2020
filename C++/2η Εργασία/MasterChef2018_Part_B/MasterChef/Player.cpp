#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>        //needed for time()
#include <stdlib.h>      //needed for srand()

using namespace std;

int checkRange(int _variable) {
	if (_variable < 0) {
		_variable = 0;
	}
	else if (_variable > 100) {
		_variable = 100;
	}

	return _variable;
}

Player::Player() {
	technicalExperience = rand() % 101;
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;
}

Player::Player(string _name, int _age, string _sex, string _occupation) {
	technicalExperience = rand() % 101;
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;
	name = _name;
	age = _age;
	sex = _sex;
	occupation = _occupation;
}

Player::~Player() {
	//cout << "Class Player is destroyed!" << endl;
}

void Player::playerStatus() {
	cout << "\t\tPlayer's Info:" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Sex: " << sex << endl;
	cout << "Occupation: " << occupation << endl;
	cout << "Technical Experience: " << technicalExperience << endl;
	cout << "Fatigue: " << fatigue << endl;
	cout << "Popularity: " << popularity << endl;
	cout << "Wins Number: " << winsNumber << endl;
	cout << "Team:" << color << endl << endl;
}

void Player::work() {
	technicalExperience += 5;
	fatigue += 20 + rand() % 21;

	technicalExperience = checkRange(technicalExperience);
	fatigue = checkRange(fatigue);
}

void Player::eat() {
	// we do nothing so far...
}

void Player::sleep() {
	fatigue = 0;
}

void Player::socialize() {
	popularity += -10 + rand() % 21;

	popularity = checkRange(popularity);
}

void Player::playerWins() {
	winsNumber++;
}

void Player::compete() {
	// we do nothing so far...
}

void Player::lastDayOfTheWeek() {
	//there is a 50-50 posibility of either sleep or work
	int dice = rand() % 2;

	if (dice == 0){
		work();
	}else{
		sleep();
	}
}