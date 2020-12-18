// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 2 - Problem # 1
#include <iostream>
#include "Book.h"

using namespace std;

Book::Book()
{
    //All private variables are string, c++ guarantees strings to be intilaized with empty string
}

Book::Book(string title_, string author_)
{
    title = title_;
    author = author_;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{   
    return author;
}

void Book::setTitle(string title_)
{
    title = title_;
}

void Book::setAuthor(string author_)
{
    author = author_;
}