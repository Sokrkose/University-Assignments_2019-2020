#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Competition {
	
protected:
	int id;
	string competitionName;
	string winner;

public:
	Competition();
	Competition(int _id, string n);
	~Competition();

	int getId();
	string getCompetitionName();
	string getWinner();

	void setId(int val);
	void setCompetitionName(string val);
	void setWinner(string val);

	void status();
};

#endif // COMPETITION_H_INCLUDED
