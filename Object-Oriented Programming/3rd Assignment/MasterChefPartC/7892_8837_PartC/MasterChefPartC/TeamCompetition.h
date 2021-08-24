#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Competition.h"
#include "FoodAward.h"
#include "Round.h"
#include "Team.h"

using namespace std;

class TeamCompetition : public Competition {
	FoodAward* foodAward;
	Round rounds[3];
public:
	TeamCompetition() { FoodAward foodAward; Round rounds[3]; }
	TeamCompetition(int _id, string _name, FoodAward &_foodAward) : Competition(_id, _name) { foodAward = &_foodAward; Round rounds[3]; }
	~TeamCompetition() { cout << "Team Competition Class is destroyed" << endl; }

	FoodAward* getFoodAward();
	Round* getRounds();

	void setRounds(int roundNumber);

	void status();

	int compete(Team &r, Team &b);      // we have to write ... compete(teams[0], teams[1]);
};

#endif // TEAMCOMPETITION_H_INCLUDED
