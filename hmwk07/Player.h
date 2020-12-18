// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 1
#ifndef PLAYER_H
#define PLAYER_H 

#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        double points;
    public:
        //Constructors
        Player();
        //Set anme and points
        Player(string name_, double points_);
        
        //Accessors
        string getName() const; //Get name
        double getPoints() const;

        //Modifiers
        void setName(string name_);
        void setPoints(double points_);


};

#endif