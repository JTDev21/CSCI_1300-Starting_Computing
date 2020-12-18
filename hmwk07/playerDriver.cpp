// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 7 - Problem # 1
#include <iostream>
#include "Player.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Parameterized constructor
    Player hector("Hector", 6.2);
    cout << hector.getName() << endl;
    cout << hector.getPoints() << endl;

    return 0;
}