#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

using namespace std;

class Team : public Player{

    int playersNumber;
    int teamWinsCounter;
    Player players;
    string color;
    int mealsPerDay;
public:
    Team();
    Team(string _color);
    ~Team();
    void teamWins(void );

};

#endif // TEAM_H_INCLUDED
