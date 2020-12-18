// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 2 - Problem # 3

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
using namespace std;

class Library
{
    private:
        string books[50];
        string users[100];
        int numBooks;
        int numUsers;
        
    public:
    //Constructor
        Library();
    
    //Accessor
        int getNumBooks() const;
        int getNumUsers() const;
        
    //Modifiers
        int readBooks(string fileName);
        int readRatings(string fileName);
        void viewRatings(string username, int min_rating);
        void printAllBooks() const;
        void addUser(string username);
        void updateRating(string username, string title, int rating);
        void getRecommendations(string username);
        
    //Extra Credit
        //Finds the average rating from a user
        void averageRating(string username);
        // Which book has been read by most users
        void bestSeller() const;
        //This finds if someone reads a lot of books(Those who rate 40-50 books)
        // void bookWorm() const;
};
#endif