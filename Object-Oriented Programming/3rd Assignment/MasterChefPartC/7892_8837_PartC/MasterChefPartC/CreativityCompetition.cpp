#include "CreativityCompetition.h"

using namespace std;

ExcursionAward* CreativityCompetition::getExcursionAward() 
{
	return excursionAward;
}

void CreativityCompetition::status() 
{
	excursionAward->status();
}

void CreativityCompetition::compete(Team &r, Team &b)
{
	Player table[22];

	for (int i = 0; i < 22; i++) {
		if(i < 11)
			table[i] = r.getPlayers()[i];
		else
			table[i] = b.getPlayers()[i - 11];
	}
	
	float maxTechnique = -1.0;
	int maxIndex = -1;
	int playerIndex = 0;

	while (playerIndex < 22) {
		float technique = table[playerIndex].getTechnique();

		if (technique > maxTechnique) {
			maxTechnique = technique;
			maxIndex = playerIndex;
		}
		playerIndex++;
	}
	
	for (int i = 0; i < 22; i++) {
		if (i < 11) {
			if (table[maxIndex].getName() == r.getPlayers()[i].getName()) {
				float fat = r.getPlayers()[i].getTechnique() + (float)excursionAward->getTechniqueBonus();
				float pop = r.getPlayers()[i].getPopularity() + (float)excursionAward->getPopularityPenalty();
				r.getPlayers()[i].setFatigue(fat);
				r.getPlayers()[i].setPopularity(pop);

				r.getPlayers()[i].status();
				status();
			}
		}
		else {
			if (table[maxIndex].getName() == b.getPlayers()[i-11].getName()) {
				float fat = b.getPlayers()[i-11].getTechnique() + (float)excursionAward->getTechniqueBonus();
				float pop = b.getPlayers()[i-11].getPopularity() + (float)excursionAward->getPopularityPenalty();
				b.getPlayers()[i-11].setFatigue(fat);
				b.getPlayers()[i-11].setPopularity(pop);

				b.getPlayers()[i-11].status();
				status();
			}
		}
	}

	cout << "'Player table[22]' is gonna be destroyed...but 'Player* players' still exists !!!" << endl;
}

