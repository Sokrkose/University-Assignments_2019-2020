#include <iostream>
#include <string>
#include <time.h>        //needed for time()
#include <stdlib.h>      //needed for srand()
#include "Player.h"
#include "Team.h"
#include "Team.h"

using namespace std;

int userInterface(void);
bool teamOverloadingCheck(int);
string selectTeam(void);
void warning(bool, int, string);


int main(void) {

	srand(time('\0'));

	Team blueTeam("blue"), redTeam("red");

	int sum = blueTeam.getPlayersNumber() + redTeam.getPlayersNumber();   // 'sum' is the number of all players! 


	while(true ) {
		
		int read = userInterface();                              // it prints 4 choices to the user

		string _team;

		if (read == 1) {
			bool flag = teamOverloadingCheck(sum);				 // teamOverloadingCheck() checks if the user exceeds player's number!
			if (flag == true)  break;

			_team = selectTeam();							     // selectTeam() asks the in which team he wants to add a player

			if (_team == "blue") {
				int number = blueTeam.getPlayersNumber() + 1;    // it increases the player's number of the 'team' by one.
				blueTeam.setPlayersNumber(number);

				blueTeam.setPlayer(&blueTeam);                   // the user sets the player's info!
			}
			else if (_team == "red") {
				int number = redTeam.getPlayersNumber() + 1;     // it increases the player's number of the 'team' by one.
				redTeam.setPlayersNumber(number);

				redTeam.setPlayer(&redTeam);                     // the user sets the player's info!
			}
		}
		else if (read == 2) {
			_team = selectTeam();
			
			bool playerFound = false;

			if (blueTeam.getColor() == _team) {
				for (int i = 0; i < blueTeam.getPlayersNumber(); i++) {
					blueTeam.getPlayer(&blueTeam, i);
					playerFound = true;
				}
			}
			else if (redTeam.getColor() == _team) {
				for (int i = 0; i < redTeam.getPlayersNumber(); i++) {
					redTeam.getPlayer(&redTeam, i);
					playerFound = true;
				}
			}

			warning(playerFound, read, _team);

		}
		else if (read == 3) {
			cout << "\t\t\t\t\tGive me the NAME of the Player" << endl;
			string name;
			cin >> name;

			bool playerFound = false;

			for (int i = 0; i < blueTeam.getPlayersNumber(); i++) {
				if (blueTeam.getPlayerName(&blueTeam, i) == name) {
					blueTeam.getPlayer(&blueTeam, i);
					playerFound = true;
				}
			}
			for (int i = 0; i < redTeam.getPlayersNumber(); i++) {
				if (redTeam.getPlayerName(&redTeam, i) == name) {
					redTeam.getPlayer(&redTeam, i);
					playerFound = true;
				}
			}

			warning(playerFound, read, _team);

		}
		else if (read == 4) {
			break;
		}
	}

	return 0;
}

int userInterface() {
	cout << "\t\t\t\t\tPress '1' to ADD a player in a team" << endl;
	cout << "\t\t\t\t\tPress '2' to show the elements of a TEAM" << endl;
	cout << "\t\t\t\t\tPress '3' to show the elements of a PLAYER" << endl;
	cout << "\t\t\t\t\tPress '4' to exit the program" << endl;
	
	int read;
	cin >> read;
	while (read != 1 && read != 2 && read != 3 && read != 4) {
		cout << "\t\t\t\t\tPlease Press Again!!!" << endl;
		cin >> read;
	}

	return read;
}

bool teamOverloadingCheck(int sum) {
	if (sum >= 22) {
		cout << "\t\t\t\t\tWarning!!!" << endl;
		cout << "\t\t\t\t\tYou cannot add more players" << endl << endl;
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

void warning(bool playerFound,int read, string _team) {
	if (playerFound == false && read == 2) {
		cout << "\t\t\t\t\tWarning!!!" << endl;
		cout << "\t\t\t\t\tSorry, the " << _team << " team has no players so far" << endl << endl;
	}
	else if (playerFound == false && read == 3) {
		cout << "\t\t\t\t\tWarrning!!!" << endl;
		cout << "\t\t\t\t\tSorry, there is no player with such name!" << endl;
		cout << "\t\t\t\t\tif you want to try again press '3'" << endl << endl;
	}
}