// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 2
#ifndef TEAM_H
#define TEAM_H

#include <iostream>
using namespace std;


class Team
{
    private:
        string teamName;
        string players[100];
        int numPlayers;
        
    
    public:
        Team(); //Set name and points to empty and 0
        Team(string teamName_); //Set team name and points to 0

        void setTeamName(string teamName_);  //Will set team name
        int readRoster(string fileName);  //Read file and place players and points into an arr called players[100]
        string getPlayerName(int i); //Get a player name in the respective index number
        double getPlayerPoints(int i); //Get a player point score in the respective index number
        int getNumPlayers() const; //Gets the number of players from a given file
        string getTeamName() const; //Gets team name


};
#endif