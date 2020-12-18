// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 1
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
    name = "";
    points = 0;
}

Player::Player(string name_, double points_)
{
    name = name_;
    points = points_;
}

string Player::getName()  const
{
    return name;
}

double Player::getPoints() const
{
    return points;
}

void Player::setName(string name_)
{
    name = name_;
}

void Player::setPoints(double points_)
{
    points = points_;
}