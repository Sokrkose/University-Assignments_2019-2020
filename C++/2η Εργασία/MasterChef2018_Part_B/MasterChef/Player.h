#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

using namespace std;

class Player {

	string name;              //given by user
	int age;				  //given by user
	string sex;               //given by user
	string occupation;        //given by user
	int technicalExperience;  //initial value = 0 to 100 (randomly)
	int fatigue;              //initial value = 0
	int popularity;           //initial value = 50
	int winsNumber;           //initial value = 0

	string color;			  //in which team/color the player is
	bool candidate;           //TRUE if player is about to leave!

public:
	Player(string ,int ,string ,string );
	Player();
	~Player();

	void playerStatus();      // It prints all information about the player
	
	/* Inline Setters */

	void setName(string _name) { name = _name; }
	void setAge(int _age) { age = _age; }
	void setSex(string _sex) { sex = _sex; }
	void setOccupation(string _occupation) { occupation = _occupation; }
	void setTechnicalExperience(int _technicalExperience) { technicalExperience = _technicalExperience; }
	void setFatigue(int _fatigue) { fatigue = _fatigue; }
	void setPopularity(int _popularity) { popularity = _popularity; }
	void setWinsNumber(int _winsNumber) { winsNumber = _winsNumber; }
	void setColor(string _color) { color = _color; }

	/* Inline Getters */

	string getName() { return name; }
	int getAge() { return age; }
	string getSex() { return sex; }
	string getOccupation() { return occupation; }
	int getTechnicalExperience() { return technicalExperience; }
	int getFatigue() { return fatigue; }
	int getPopularity() { return popularity; }
	int getWinsNumber() { return winsNumber; }
	string getColor() { return color; }

	/* Public Functions */

	void work();
	void eat();
	void sleep();
	void socialize();
	void playerWins();
	void compete();
	void lastDayOfTheWeek();
};

#endif // PLAYER_H_INCLUDED
