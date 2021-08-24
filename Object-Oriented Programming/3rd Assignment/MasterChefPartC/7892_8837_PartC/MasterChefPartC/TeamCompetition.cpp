#include "TeamCompetition.h"

using namespace std;

string RoundWinner(Team &r, Team &b, int round);

FoodAward* TeamCompetition::getFoodAward() {
	return foodAward;
}

Round* TeamCompetition::getRounds() {
	return rounds;
}

void TeamCompetition::setRounds(int roundNumber) {
	int _id, _duration;
	string _winner;
	cout << "Type round's ID" << endl;
	cin >> _id;
	cout << "Type round's Duration" << endl;
	cin >> _duration;
	cout << "Type round's Winner" << endl;
	cin >> _winner;
	rounds[roundNumber].setId(_id);
	rounds[roundNumber].setDuration(_duration);
	rounds[roundNumber].setWinner(_winner);
}

void TeamCompetition::status() {
	foodAward->status();
	rounds->status();
}

int TeamCompetition::compete(Team &r, Team &b) {
	int wins1 = 0, wins2 = 0, round = 1;

	// <------------- Team Competition Rounds start ------------------------------------->

	while (round < 4) {

		rounds[round].setDuration(3600);            //Every round is 1 hours -> 3600 seconds !

		string winner = RoundWinner(r, b, round);

		if (winner == "red") {
			rounds[round-1].setWinner("Red");
			cout << "Round " << round << " Winner is " << rounds[round - 1].getWinner() << " TEAM" << endl << endl;
			wins1++;
		}
		else {
			rounds[round-1].setWinner("Blue");
			cout << "Round " << round << " Winner is " << rounds[round - 1].getWinner() << " TEAM" << endl << endl;
			wins2++;
		}

		round++;
	}

	// <-------------- 3 Rounds finished...we have a winner!!! ------------------------->

	if (wins1 > wins2) {
		r.teamWins();
		setWinner("Red");
		cout << "Team Competition winner is Team " << getWinner() << endl;
		
		int var = r.getSupplies() + foodAward->getBonusSupplies();
		r.setSupplies(var);

		return 1;
	}
	else {
		b.teamWins();
		setWinner("Blue");
		cout << "Team Competition winner is Team " << getWinner() << endl;
		
		int var = b.getSupplies() + foodAward->getBonusSupplies();
		b.setSupplies(var);

		return 0;
	}

}

string RoundWinner(Team &r, Team &b, int round) {

	int chosenPlayersIndex = 0;
	int table[5];                        // table[5] will have 5 DIFFERENT numbers from 0 to 11

	while (chosenPlayersIndex < 5) {

		int var = (int)rand() % 11;      // var will have values from 0 to 11

		switch (chosenPlayersIndex)
		{
		case 0:
			table[0] = var;
			chosenPlayersIndex++;
		case 1:
			if (var != table[0]) { table[1] = var; chosenPlayersIndex++; }
		case 2:
			if (var != table[0] && var != table[1]) { table[2] = var; chosenPlayersIndex++; }
		case 3:
			if (var != table[0] && var != table[1] && var != table[2]) { table[3] = var; chosenPlayersIndex++; }
		case 4:
			if (var != table[0] && var != table[1] && var != table[2] && var != table[3]) { table[4] = var; chosenPlayersIndex++; }
		default:
			break;
		}
	}

	for (int i = 0; i < 5; i++) {
		r.getPlayers()[table[i]].compete();
		b.getPlayers()[table[i]].compete();
	}

	cout << "\t\tRound " << round << endl << endl;

	cout << "Red Team Players:    ";
	for (int i = 0; i < 5; i++) {
		cout << r.getPlayers()[table[i]].getName() << "  ";
	}
	cout << endl << endl;
	cout << "Blue Team Players:   ";
	for (int i = 0; i < 5; i++) {
		cout << b.getPlayers()[table[i]].getName() << "  ";
	}
	cout << endl << endl;

	float redAverage = 0, blueAverage = 0;

	for (int i = 0; i < 5; i++) {
		redAverage += r.getPlayers()[table[i]].getTechnique();
		blueAverage += b.getPlayers()[table[i]].getTechnique();
	}

	if (redAverage > blueAverage)
		return "red";
	if (redAverage < blueAverage)
		return "blue";
	else {
		for (int i = 0; i < 5; i++) {
			redAverage += r.getPlayers()[table[i]].getFatigue();
			blueAverage += b.getPlayers()[table[i]].getFatigue();
		}
		if (redAverage > blueAverage)
			return "blue";
		if (redAverage < blueAverage)
			return "red";
	}

}