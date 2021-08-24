#pragma once
//Karakostas Konstantinos    7892      karakosk@ece.auth.gr
//Koseoglou Sokratis         8837      Sokrkose@ece.auth.gr

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>

using namespace std;

class Player {

private:
	string name;              //given by user
	int age;				  //given by user
	string sex;               //given by user
	string occupation;        //given by user
	float technicalExperience;  //initial value = 0 to 100 (randomly)
	float fatigue;              //initial value = 0
	float popularity;           //initial value = 50
	int winsNumber;           //initial value = 0
public:
	//Constructors
	Player(string name, int age, string sex, string occupation);
	Player();
	//Destructor
    ~Player();

	//-----Getters and Setters----------------
	//Name
	void setName(string name);
	string getName();

	//Age
	void setAge(int age);
	int getAge();

	//Sex
	void setSex(string sex);
	string getSex();

	//Occupation
	void setOccupation(string occupation);
	string getOccupation();

	//TechnicalExperience
	void setTechnicalExperience(float technicalExperience);
	float getTechnicalExperience();

	//Fatigue
	void setFatigue(float fatigue);
	float getFatigue();

	//Popularity
	void setPopularity(float popularity);
	float getPopularity();

	//WinsNumber
	void setWinsNumber(int winsNumber);
	int getWinsNumber();
	//----End of Getters/Setters.


	//Player's activities
	void work();
	void eat();
	void sleep();
	void socialize();
	void playerWins();
	void compete();
	void lastDayOfTheWeek();
	float checkRange(float variable);
	string checkSex(string sex);
	int checkAge(int age);
};


#endif // PLAYER_H_INCLUDED
