// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 3
#include <iostream>
#include "Player.h"
#include "Team.h"

using namespace std;

//I did not user the Player class, just the Team class.

string game(Team team1_, Team team2_)
{
    string winner;
    /////Analysis for Team1
    int numPlayers_team1_ = team1_.getNumPlayers();
    int numPlayers_team2_ = team2_.getNumPlayers();
    
    double sum_T1 = 0;
    double sum_T2 = 0;
    //Checks for all these conditions if false then forfeit
    if(!(numPlayers_team1_ < 4 || numPlayers_team2_ < 4) && !(numPlayers_team1_ == 0 && numPlayers_team2_ == 0))
    {
        //the number 4 stands for the number of players to count
        for(int i = 0; i < 4; i++)
        {
            sum_T1 += team1_.getPlayerPoints(i);
            sum_T2 += team2_.getPlayerPoints(i);
        }
        if(sum_T1 > sum_T2)
        {
            // cout << "sum_T1: " << sum_T1 << " > " << "sum_T2: " << sum_T2 << endl;
            winner = team1_.getTeamName();
        }
        else if(sum_T1 < sum_T2)
        {
            // cout << "sum_T1: " << sum_T1 << " < " << "sum_T2: " << sum_T2 << endl;
            winner = team2_.getTeamName();
        }
        else
        {
            return "draw";
        }
    }
    else
    {
        return "forfeit";
    }

    return winner;
}


int main()
{
    Team team1("Seg Faultline");
    team1.readRoster("roster1.txt");
    
    Team team2("Team Maim");
    team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;
    return 0;
}