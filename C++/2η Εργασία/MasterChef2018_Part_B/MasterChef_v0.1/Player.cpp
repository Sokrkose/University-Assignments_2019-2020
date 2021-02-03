#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Player.h"
#include <string>

using namespace std;

void checkRange(int _variable){
    if(_variable < 0){
        _variable = 0;
    }else if(_variable > 100){
        _variable = 100;
    }
}

Player::Player(){
    srand(time('\0'));

	technicalExperience = rand()%100;
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;

}

Player::Player(string _name, int _age, string _sex, string _occupation){
	srand(time('\0'));

	technicalExperience = rand()%101;
	fatigue = 0;
	popularity = 50;
	winsNumber = 0;
	setName(_name);
	setAge(_age);
	setSex(_sex);
	setOccupation(_occupation);
}

Player::~Player(){
    // deletes every variable!
}

void Player::work(){
    technicalExperience += 5;
    fatigue += 20 + rand()%21;

}

void Player::eat(){

}

void Player::sleep(){
	fatigue = 0;
}

void Player::socialize(){
    popularity += -10 + rand()%21;
}

void Player::playerWins(){
	winsNumber++;
}

void Player::compete(){

}

void Player::lastDayOfTheWeek(){
	//there is a 50-50 posibility of either sleep or work
	int var = rand()%2;

	if(var == 0)
		work();
	}else{
		sleep();
	}
}
