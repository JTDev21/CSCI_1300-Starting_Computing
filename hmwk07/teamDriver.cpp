// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 2
#include <iostream>
#include "Team.h"

using namespace std;

int main()
{
    Team team1("Seg Faultline");
    cout << team1.getTeamName() << endl;
    team1.readRoster("roster1.txt");
    int n1 = team1.getNumPlayers();
    cout << n1 << endl;
    for (int i = 0; i < n1; i++) 
    {
    cout << team1.getPlayerName(i) << " ";
    cout << team1.getPlayerPoints(i) << endl;
    
    }
    return 0;
}