// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 2 - Problem # 2

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
    private:
        string username;
        int ratings[50];
    
    public:
        User();
        
        void setUsername(string username_);
        
        // Automatically checks for range bounds of books array and rating values
            //Bounds for books(0-49) and rating value(0-5)
        bool setRatingAt(int i, int ratingValue); 
        
        string getUsername() const;
        
        //Automatically checks for bounds of book array(0-49)
        int getRatingAt(int i); 
        
    
};

#endif
