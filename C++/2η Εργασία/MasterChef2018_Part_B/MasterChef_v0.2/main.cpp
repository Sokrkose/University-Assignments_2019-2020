#include <iostream>
#include <string>
#include <time.h>        //needed for time()
#include <stdlib.h>      //needed for srand()
#include "Player.h"
#include "Team.h"

using namespace std;

int counter = 0;

bool teamOverloadingCheck(void);
string selectTeam(void);
void addPlayer(Team, Player*,string);

int main(void) {

	srand(time('\0'));

	Team blueTeam("blue"), redTeam("red");
	Player player[22];

	while(true ) {
		cout << "\t\t\t\t\tPress '1' to ADD a player in a team" << endl;
		cout << "\t\t\t\t\tPress '2' to show the elements of a TEAM" << endl;
		cout << "\t\t\t\t\tPress '3' to show the elements of a PLAYER" << endl;
		cout << "\t\t\t\t\tPress '4' to exit the program" << endl;
		int read;
		cin >> read;
		while (read != 1 && read != 2 && read != 3 && read != 4) {
			cout << "You pressed malakia...press again malaka" << endl;
			cin >> read;
		}

		string _team;

		if (read == 1) {
			bool flag = teamOverloadingCheck();
			if (flag == true) break;

			_team = selectTeam();

			if (_team == "blue") {
				addPlayer(blueTeam, player, _team);
			}
			else if (_team == "red") {
				addPlayer(redTeam, player, _team);
			}
			counter++;
		}
		else if (read == 2) {
			_team = selectTeam();
			
			for (int i = 0; i < counter; i++) {
				if (player[i].getColor() == _team) {
					player[i].playerStatus();
				}
			}
		}
		else if (read == 3) {
			cout << "\t\t\t\t\tGive me the NAME of the Player" << endl;
			string name;
			cin >> name;

			bool playerFound = false;

			for (int i = 0; i < counter; i++) {
				if (player[i].getName() == name) {
					player[i].playerStatus();
					playerFound = true;
				}
			}

			if (playerFound == false) {
				cout << "\t\t\t\t\tSorry, there is no player with such name!" << endl;
				cout << "\t\t\t\t\tif you want to try again press '3'" << endl << endl;
			}
		}
		else if (read == 4) {
			break;
		}
	}

	system("pause");
	return 0;
}

bool teamOverloadingCheck(void) {
	if (counter >= 22) {
		cout << "You cannot add more players" << endl;
		return true;
	}
		return false;
}

string selectTeam() {
	cout << "\t\t\t\t\tSelect Team... 'blue' OR 'red' ?" << endl;
	string _team;
	cin >> _team;
	while (_team != "blue" && _team != "red") {
		cout << "\t\t\t\t\tPlease enter 'blue' OR 'red'..." << endl;
		cin >> _team;
	}

	return _team;
}

void addPlayer(Team team, Player* player, string _team) {
	team.setPlayer(player, counter, _team);
}