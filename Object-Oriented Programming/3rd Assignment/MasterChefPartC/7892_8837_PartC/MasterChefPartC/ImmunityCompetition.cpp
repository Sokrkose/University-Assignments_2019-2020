#include "ImmunityCompetition.h"

using namespace std;

ImmunityAward* ImmunityCompetition::getImmunityAward() 
{
	return immunityAward;
}

void ImmunityCompetition::status() 
{
	immunityAward->status();
}

void ImmunityCompetition::compete(Team &team)
{	
	float table[11];

	for (int i = 0; i < 11; i++) {
		float t = team.getPlayers()[i].getTechnique();
		float f = team.getPlayers()[i].getFatigue();

		table[i] = t*0.75 + (100 - f)*0.25;
	}
	int MAX = 0;
	for (int i = 1; i < 11; i++)
		if (table[i] > table[MAX])	MAX = i;

	cout << endl << "Player " << team.getPlayers()[MAX].getName() << " of " << team.getColor() << " team won the Immunity Competition" << endl << endl;

	int wins = team.getPlayers()[MAX].getWins() + 1;
	team.getPlayers()[MAX].setWins(wins);
}