// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 2 - Problem # 1

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;


class Book
{
    private:
        string title;
        string author;
    
    public:
        Book();
        Book(string title, string author);
        
        string getTitle() const;
        string getAuthor() const;
        
        void setTitle(string title_);
        void setAuthor(string author_);
    
};

#endif