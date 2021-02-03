#include "Competition.h"

using namespace std;

Competition::Competition() {
	id = 0;
	competitionName = "";
	winner = "";
}

Competition::Competition(int _id, string n) {
	id = _id;
	competitionName = n;
	winner = "";
}

Competition::~Competition() {
	cout << "Competition " << competitionName << " is destroyed" << endl;
}

int Competition::getId() {
	return id;
}

string Competition::getCompetitionName() {
	return competitionName;
}

string Competition::getWinner() {
	return winner;
}

void Competition::setId(int val) {
	id = val;
}

void Competition::setCompetitionName(string val) {
	competitionName = val;
}

void Competition::setWinner(string val) {
	winner = val;
}

void Competition::status() {
	cout << "\t\tCompetition Status" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << competitionName << endl;
	cout << "Winner: " << winner << endl << endl;
}