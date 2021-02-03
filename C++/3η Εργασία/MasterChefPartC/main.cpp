#include "Team.h"
#include "FoodAward.h"
#include "ImmunityAward.h"
#include "ExcursionAward.h"
#include "TeamCompetition.h"
#include "ImmunityCompetition.h"
#include "CreativityCompetition.h"
#include <time.h>

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue") };

int competitionId = 0;
string competitionName;

void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

void MorningRoutine();
void NightRoutine();

int teamCompetitionWinner = -1;

int main()
{
	srand(time(NULL));

	menu();

	return 0;
}

void menu()
{
	int choice = -1;

	while (choice != 0)
	{
		cout << endl << "1.Normal Day." << endl;
		cout << "2.Team Competition Day." << endl;
		cout << "3.Immunity Competition Day." << endl;
		cout << "4.Creativity Competition Day." << endl;
		cout << "0.Quit" << endl;

		cin >> choice;

		switch (choice)
		{

		case 1:
			normalDay();
			break;
		case 2:
			teamCompetitionDay();
			break;
		case 3:
			immunityCompetitionDay();
			break;
		case 4:
			creativityCompetitionDay();
			break;
		case 0:
			break;
		default:
			cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

		}
	}
}

void normalDay()
{
	cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;

	MorningRoutine();
	NightRoutine();
}

void teamCompetitionDay()
{
	cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;
	
	cout << "Type competition's name...";
	cin >> competitionName;
	MorningRoutine();

	FoodAward* foodAward = new FoodAward("Food Award", false);
	TeamCompetition teamCompetition(competitionId, competitionName, *foodAward);

	teamCompetitionWinner = teamCompetition.compete(teams[0], teams[1]);

	NightRoutine();

	delete foodAward;
}

void immunityCompetitionDay()
{
	if (teamCompetitionWinner == -1) { cout << "First press '2' to run Team Competition..." << endl; return; }


	cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;
	
	cout << "Type competition's name...";
	cin >> competitionName;
	MorningRoutine();

	ImmunityAward immunityAward("Player Immunity Award", true);
	ImmunityCompetition immunityCompetition(competitionId, competitionName, immunityAward);

	if (!teamCompetitionWinner) immunityCompetition.compete(teams[0]);
	else if (teamCompetitionWinner) immunityCompetition.compete(teams[1]);

	NightRoutine();
}

void creativityCompetitionDay()
{

	cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;

	cout << "Type competition's name...";
	cin >> competitionName;
	MorningRoutine();

	ExcursionAward excursionAward("Excursion Award", true);
	CreativityCompetition creativityCompetition(competitionId, competitionName, excursionAward);

	creativityCompetition.compete(teams[0], teams[1]);

	NightRoutine();
}

void MorningRoutine() 
{	
	//Morning Work
	for (int j = 0; j < 2; j++) {
		teams[j].teamEats();
		teams[j].teamWorks();
	}
}

void NightRoutine()
{
	//Night eat and sleep
	for (int j = 0; j < 2; j++) {
		teams[j].teamEats();
		teams[j].teamSleeps();
	}

	//End of a normal day
	for (int j = 0; j < 2; j++)
		teams[j].teamSocializes();
		
}