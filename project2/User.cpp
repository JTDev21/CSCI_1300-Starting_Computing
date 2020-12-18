// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 2 - Problem # 2

#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
    for(int i = 0; i < 50; i++)
    {
        ratings[i] = 0;
    }
}

void User::setUsername(string username_)
{
    username = username_;
}

bool User::setRatingAt(int i_, int ratingValue_)
{
    if((0 <= i_ && i_ < 50) && (0 <= ratingValue_ && ratingValue_ <= 5))
    {
        ratings[i_] = ratingValue_;
        // cout << "ratings[" << i_ << "] = " << ratingValue_ << endl;
        return true;
    }
    else
    {
        return false;
    }
}

string User::getUsername() const
{
    return username;
}

int User::getRatingAt(int i_)
{
    if(0 <= i_ && i_ < 50)
    {
        return ratings[i_];
    }
    else
    {
        return -1;
    }
}