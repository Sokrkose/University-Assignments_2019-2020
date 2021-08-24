#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Competition.h"
#include "ImmunityAward.h"
#include "Team.h"

using namespace std;

class ImmunityCompetition : public Competition {

	ImmunityAward* immunityAward;
public:
	ImmunityCompetition() { ImmunityAward immunityAward; }
	ImmunityCompetition(int _id, string name, ImmunityAward &_immunityAward) : Competition(_id, name) { this->immunityAward = &_immunityAward; }
	~ImmunityCompetition() { cout << "Immunity Competition Class is destroyed" << endl; }

	ImmunityAward* getImmunityAward();

	void status();

	void compete(Team &team);
};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
