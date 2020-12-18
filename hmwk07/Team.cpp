// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 2
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Team.h"

using namespace std;

///////////////////////////////////////////////
//Constructor
Team::Team()
{
    teamName = "";
    numPlayers = 0;
}

Team::Team(string teamName_)
{
    teamName = teamName_;
    numPlayers = 0;
}

///////////////////////////////////////////////
void Team::setTeamName(string teamName_)
{
    teamName = teamName_;
}

///////////////////////////////////////////////
int Team::readRoster(string fileName_)
{
    ifstream myfile;
    myfile.open(fileName_);
    if(myfile.fail())
    {
        return -1;
    }
    else
    {
        int location = 0;
        string line;
        string data;
        while(getline(myfile, line))
        {
            istringstream strm;
            strm.str(line);
            while(getline(strm, data, ','))
            {
                if(location > 99) //Determines if the size of the file is smaller than the allocated size for an array
                {
                    return numPlayers;
                }
                else if(location % 2 == 0) //Finds how many players for every other line
                {
                    numPlayers++;
                }
                players[location] = data; // Adds all data(name and points) to the array
                location++;
                
            }
        }
        // for(int i = 0; i < location; i++)
        // {
        //     cout << players[i] << endl;
        // }
    }
    myfile.close();
    return numPlayers;
}

///////////////////////////////////////////////
string Team::getPlayerName(int i_)
{
    if(i_ < 0 || i_ > 49 || i_ > numPlayers - 1) //Determines if the index required is within arr size
    {
        return "ERROR";
    }
    else
    {
        return players[i_ * 2];//Math
    }
}

///////////////////////////////////////////////
double Team::getPlayerPoints(int i_)
{
    if(i_ < 0 || i_ > 49 || i_ > numPlayers - 1)
    {
        return -1;
    }
    else
    {
        return stod(players[(i_ * 2) + 1]);
        
    }
}

///////////////////////////////////////////////
int Team::getNumPlayers() const
{
    return numPlayers;
}

///////////////////////////////////////////////
string Team::getTeamName() const
{
    return teamName;
}