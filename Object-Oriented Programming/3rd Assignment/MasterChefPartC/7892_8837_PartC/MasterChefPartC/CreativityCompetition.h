#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Competition.h"
#include "ExcursionAward.h"
#include "Team.h"

using namespace std;

class CreativityCompetition : public Competition {

	ExcursionAward* excursionAward;
	string ingredients[10] = { "oil","baked soda","sugar","salt","butter","milk","powder","water","eggs","buttermilk" };
public:
	CreativityCompetition() { ExcursionAward excursionAward; }
	CreativityCompetition(int _id, string name, ExcursionAward &_excursionAward) : Competition(_id, name) { excursionAward = &_excursionAward; }
	~CreativityCompetition() {cout << "Creativity Competition Class is destroyed" << endl; }

	ExcursionAward* getExcursionAward();

	void status();

	void compete(Team &r, Team &b);
};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
