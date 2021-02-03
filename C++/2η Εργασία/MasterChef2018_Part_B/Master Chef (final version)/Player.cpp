//Karakostas Konstantinos    7892      karakosk@ece.auth.gr
//Koseoglou Sokratis         8837      Sokrkose@ece.auth.gr

#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include <string>

using namespace std;

//Constructors
Player::Player() {
	name = " ";
	age = -1;
	sex = "";
	occupation = "";
	technicalExperience = ((float)rand() / (float)(RAND_MAX)) * 100;
	technicalExperience = checkRange(technicalExperience);
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;

}
//constructor
Player::Player(string name, int age, string sex, string occupation) {
	technicalExperience = ((float)rand() / (float)(RAND_MAX)) * 100;
	technicalExperience = checkRange(technicalExperience);
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;
	this->name= name;

	age = checkAge(age);
	this->age = age;

	sex = checkSex(sex);
	this->sex = sex;

	this->occupation = occupation;
}

//Destructor
Player::~Player(){
}

//------Getters and setters------------------

//Name
void Player::setName(string name){
	this->name = name;
}
string Player::getName() {
	return name;
}

//Age (Setter checks for correct value)
void Player::setAge(int age) {
	age = checkAge(age);
	this->age = age;
}
int Player::getAge() {
	return age;
}

//Sex (Setter checks for correct value)
void Player::setSex(string sex) {
	sex = checkSex(sex);
	this->sex = sex;
}
string Player::getSex() {
	return sex;
}

//Occupation
void Player::setOccupation(string occupation) {
	this->occupation = occupation;
}
string Player::getOccupation() {
	return occupation;
}

//TechnicalExperience (Setter checks for correct value)
void Player::setTechnicalExperience(float technicalExperience) {
	technicalExperience = checkRange(technicalExperience);
	this->technicalExperience = technicalExperience;
}
float Player::getTechnicalExperience() {
	return technicalExperience;
}

//Fatigue (Setter checks for correct value)
void Player::setFatigue(float fatigue) {
	fatigue = checkRange(fatigue);
	this->fatigue = fatigue;
}
float Player::getFatigue() {
	return fatigue;
}

//Popularity (Setter checks for correct value)
void Player::setPopularity(float popularity) {
	popularity = checkRange(popularity);
	this->popularity = popularity;
}
float Player::getPopularity() {
	return popularity;
}

//WinsNumber
void Player::setWinsNumber(int winsNumber) {
	this->winsNumber = winsNumber;
}
int Player::getWinsNumber() {
	return winsNumber;
}

//----End of Getters/Setters.------


//----Player's activities------

void Player::work() {
	/* Simulation of the "work" activity

		Sets the new fatihue and technicalExperience values and
		checks for invalid values (<0 OR >100)
	*/

	//Technical experience increases 5% (relative increase)
	technicalExperience += 0.05*technicalExperience;
	//Fatigue increases between 20% and 40% percent (absolute increase)
	fatigue += 20 + (((float)rand()) / (float)RAND_MAX * (40 - 20));

	//Checks in order not to cross the 0 to 100 range
	technicalExperience = checkRange(technicalExperience);
	fatigue = checkRange(fatigue);

}

void Player::eat() {
	/*  Simulation of the "eat" activity

		Does nothing. Man must eat at peace.
	*/
}

void Player::sleep() {
	/*	Ssshhhh! Read this quietly!

		Simulation of the "sleep" activity

		Fatigue falls to zero
	*/
	fatigue = 0;
}

void Player::socialize() {
	/* Simulation of the "socialize" activity

	Sets the new popularity value and
	checks for invalid values (<0 OR >100)
	*/
	popularity += -10 + (((float)rand()) / (float)RAND_MAX * 20);
	popularity = checkRange(popularity);
}

void Player::playerWins() {
	/* Adds Player's new victory to value winsNumber*/
	winsNumber++;
}

void Player::compete() {
  /*	Simulation of the "compete" activity

		No code (of honor) here. Everybody wants the money.
  */
}

void Player::lastDayOfTheWeek() {
	/*  Simulation of Sunday.

		Random selection between work and sleep (with 50 possibility for each choice
	*/

	int SundayActivity = rand() % 2;

	if (SundayActivity == 0) {
		//ABSOLUTE increase in technical Experience. Different than the one in work() method
		technicalExperience += 0.05*technicalExperience;
	}
	else {
		sleep();
	}
}

float Player::checkRange(float variable) {
	/* Checks if variable is between 0 and 100.
	   Cases:  1) if variable < 0 sets to 0
			   2) if variable > 100 sets to 100
	*/
	if (variable < 0) {
		variable = 0;
	}
	else if (variable > 100) {
		variable = 100;
	}
	return variable;
}

string Player::checkSex(string sex) {
	/* Checks if sex is Male or Female.

	   If it isn't, sets to "Male". Are you offended? Nobody cares!

	*/
	if (sex == "Male" || sex == "Female") {
		return sex;
	}
	else {
		return "Male";
	}
}

int Player:: checkAge(int age) {
	/* Checks if age is below 18.

	If yes, it sets to 18. Obviously, that's what the user meant.

	*/
	if (age < 18) {
		age = 18;
	}

	return age;
}
//----End of Player's activities---------
