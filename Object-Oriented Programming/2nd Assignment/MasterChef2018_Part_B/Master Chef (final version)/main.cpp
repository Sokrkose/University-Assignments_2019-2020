//Karakostas Konstantinos    7892      karakosk@ece.auth.gr
//Koseoglou Sokratis         8837      Sokrkose@ece.auth.gr

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Player.h"
#include "Team.h"
#include <string>
using namespace std;

//Adds a player in a team
void addPlayer(Team* team);

//Prints the elements of a team
void teamPrinter(Team* team);

//Prints the players either by alphabetical order, or by position in the matrix
void PlayersPrinter(Team* team);

//Helps function PlayersPrinter to order the players with alphabetical order
void bubbleSort(Team* team, string arr[]);

int main() {
	/* Main. Basic user menu is here. Press play and follow instructions

	*/
	Team* Blue = new Team("Blue");
	Team* Red = new Team("Red");

	int choice;
	int chosenTeam = 0;

	while (1) {
		cout << "Press 1 to add player to a team" << endl;
		cout << "Press 2 to show team's elements" << endl;
		cout << "Press 3 to show player's elements" << endl;
		cout << "Press 4 to exit" << endl;
		cin >> choice;
		if (choice == 4) {
			cout << "exit" << endl;
			break;
		}
		if (choice == 1) {
			cout << " CHOICE 1: Player creation" << endl;
			while (chosenTeam != 1 && chosenTeam != 2) {
				cout << "           Press 1 to enter the player to team Blue or 2 to team Red" << endl;
				cin >> chosenTeam;
					if (chosenTeam == 1) {
						addPlayer(Blue);
					}
					else if (chosenTeam == 2) {
						addPlayer(Red);
					}
			}
			chosenTeam = 0;
		}
		else if (choice == 2) {
			cout << " CHOICE 2: Team printing" << endl;
			while (chosenTeam != 1 && chosenTeam != 2) {
				cout << "           Press 1 for Blue team or 2 for Red team" << endl;
				cin >> chosenTeam;
				if (chosenTeam == 1) {
					teamPrinter(Blue);
				}
				else if (chosenTeam == 2) {
					teamPrinter(Red);
				}
			}
			chosenTeam = 0;
		}
		else if (choice == 3) {
			cout << " CHOICE 3: Players printing" << endl;
			while (chosenTeam != 1 && chosenTeam != 2) {
				cout << "           Press 1 for Blue team or 2 for Red team" << endl;
				cin >> chosenTeam;
				if (chosenTeam == 1) {
					PlayersPrinter(Blue);
				}
				else if (chosenTeam == 2) {
					PlayersPrinter(Red);
				}
			}
			chosenTeam = 0;
		}
		else cout << "ATTENTION" << endl;
		}
	return 0;

	system("pause");
}

void addPlayer(Team* team) {
	/* Add a player in a team. User adds the personal values.
	   Number of players in the team increases by one.
	   The number of meals for this player sets to 14.

	*/
	cout << "Please enter name" << endl;
	string name;
	cin >> name;
	cout << "Please enter age" << endl;
	int age;
	cin >> age;

	cout << "Please enter sex" << endl;
	string sex;
	cin >> sex;

	cout << "Please enter occupation" << endl;
	string occupation;
	cin >> occupation;

	Player* temp = new Player(name, age, sex, occupation);

	team->setPlayers(temp, team->getPlayersNumber());
	team->setPlayersNumber(team->getPlayersNumber() + 1);
}

void teamPrinter(Team* team) {
	/* Printer of a team. Prints also the player since they are
	   basic elements of the team

	   Example form:
		------ Team Blue ------------
		Number of players: X
		Number of victories: X
		Number of supplies: X

		PLAYER NO K (where k=0,1,2,..., length of team)
		Name: X
		Gender: X
		Age: X
		Occupation: X
		Technical Experience: X
		Fatigue: X
		Popularity: X
		Personal wins: X
		Meals: X
		-----------------------
	*/
	cout << "------ Team " << team->getColor() << " ------" << endl;
	cout << "Number of players: " << team->getPlayersNumber() << endl;
	cout << "Number of victories: " << team->getTeamsWinsCounter() << endl;
	cout << "Number of supplies: " << team->getNumberOfSupplies() << endl;
	for (int i = 0; i < team->getPlayersNumber(); i++) {
		cout << endl;
		cout << " PLAYER NO" << i + 1 << endl;
		cout << "  Name: " << team->getPlayers(i)->getName() << endl;
		cout << "  Gender: " << team->getPlayers(i)->getSex() << endl;
		cout << "  Age: " << team->getPlayers(i)->getAge() << endl;
		cout << "  Occupation: " << team->getPlayers(i)->getOccupation() << endl;
		cout << "  Technical Experience: " << team->getPlayers(i)->getTechnicalExperience() << endl;
		cout << "  Fatigue: " << team->getPlayers(i)->getFatigue() << endl;
		cout << "  Popularity: " << team->getPlayers(i)->getPopularity() << endl;
		cout << "  Personal wins: " << team->getPlayers(i)->getWinsNumber() << endl;
		cout << "  Meals: " << team->getNumberOfSupplies() << endl;
	}
	cout << "-----------------------" << endl;
}

void PlayersPrinter(Team* team) {
	/* Prints the player either according to their position in array,
	   or alphabetically, with the help of the bubblesort function.

	   How it works:
	    1) Copies all the names to a new string array (NameList).
		2) The Namelist array orders inside the bubblesort function.
		3) Compares the name of each player with the ordered nameS in the NameList.
		4) Whether there is a match, prints the variables of this player.
		It is assumed that there are no players with same name. Everyone is a special snowflake.

	   User chooses inside this function, which choice to use.

	   The printing has the same form as teamPrinter output.

	*/
	int userChoice = 0;
	while (userChoice != 1 && userChoice != 2) {
		cout << "Press 1 to print the players of team" << team->getColor() << "according in their position in matrix" << endl;
		cout << "or press 2 to print the players of team" << team->getColor() << "alphabetically" << endl;
		cin >> userChoice;
	}
	if (userChoice == 1) {
		cout << "You choose to see the players of team" << team->getColor() << "according in their position in matrix" << endl;
		for (int i = 0; i < team->getPlayersNumber(); i++) {
			cout << endl;
			cout << " PLAYER NO" << i + 1 << endl;
			cout << "  Name: " << team->getPlayers(i)->getName() << endl;
			cout << "  Gender: " << team->getPlayers(i)->getSex() << endl;
			cout << "  Age: " << team->getPlayers(i)->getAge() << endl;
			cout << "  Occupation: " << team->getPlayers(i)->getOccupation() << endl;
			cout << "  Technical Experience: " << team->getPlayers(i)->getTechnicalExperience() << endl;
			cout << "  Fatigue: " << team->getPlayers(i)->getFatigue() << endl;
			cout << "  Popularity: " << team->getPlayers(i)->getPopularity() << endl;
			cout << "  Personal wins: " << team->getPlayers(i)->getWinsNumber() << endl;
		}
	}
	else if (userChoice == 2) {
		cout << "You choose to see the players of team" << team->getColor() << "alphabetically" << endl;

		//NameList needs an initialization, so the string "zzzz" was chosen to maximize the
		//effectiveness of bubblesort, since z is the last letter in alphabet.
		string NameList[11];
		for (int i = 0; i < 11; i++) {
			NameList[i] = "zzzz";
		}

		for (int i = 0; i < team->getPlayersNumber(); i++) {
			NameList[i] = team->getPlayers(i)->getName();
		}

		bubbleSort(team, NameList);

		int index = 0;

		//Index increases only when the name in NameList matches the name in the Team's Players array
		while(index < team->getPlayersNumber()){
			for (int i = 0; i < team->getPlayersNumber(); i++) {
				//If NameList name and Players name is the same, print the variables of the player.
				if (NameList[index].compare(team->getPlayers(i)->getName())==0){
					index++;
					cout << " PLAYER NO" << index << endl;
					cout << "  Name: " << team->getPlayers(i)->getName() << endl;
					cout << "  Gender: " << team->getPlayers(i)->getSex() << endl;
					cout << "  Age: " << team->getPlayers(i)->getAge() << endl;
					cout << "  Occupation: " << team->getPlayers(i)->getOccupation() << endl;
					cout << "  Technical Experience: " << team->getPlayers(i)->getTechnicalExperience() << endl;
					cout << "  Fatigue: " << team->getPlayers(i)->getFatigue() << endl;
					cout << "  Popularity: " << team->getPlayers(i)->getPopularity() << endl;
					cout << "  Personal wins: " << team->getPlayers(i)->getWinsNumber() << endl;
				}
			}
		}
	}
}

void bubbleSort(Team* team, string NameList[])
{
	/* Classic bubblesort algorithm, but the implementation is for strings. Sorts the strings
	in the NameList alphabetically

	    compare function returns:  0    if strings are the same
								  <0	Either the value of the first character that does
										not match is lower in the compared string, or all compared
										characters match but the compared string is shorter.
								  >0	Either the value of the first character that does not match
										is greater in the compared string, or all compared characters
										match but the compared string is longer.
		(source: http://www.cplusplus.com/reference/string/string/compare/ )
	*/
	string tmp;

	for (int i = 0; i < team->getPlayersNumber() - 1; i++) {
		for (int j = i + 1; j < team->getPlayersNumber(); j++) {
			if (NameList[i].compare(NameList[i + 1])> 0 )
			{
				tmp = NameList[i];
				NameList[i] = NameList[i + 1];
				NameList[i + 1] = tmp;
			}
		}
	}
}

