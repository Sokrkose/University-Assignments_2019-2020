#include <iostream>
#include "Player.h"
#include "Team.h"

using namespace std;

Team::Team(){
    playersNumber = 11;
    teamWinsCounter = 0;
    mealsPerDay = 14;
}

Team::Team(string _color){
    setColor(_color);
}

Team::~Team(){

}

Team::teamWins(){
    teamWinsCounter++;
}
