// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 2 - Problem # 6

#include <iostream>
using namespace std;

int main()
{
    int inputSeconds;
    int hours;
    int minutes;
    int seconds;
    
    //Request user input for seconds
    cout << "Enter a number of seconds:" << endl;
    cin >> inputSeconds;
    
    //Compute hour(s) (1 hour = 3600 sec)
    hours = inputSeconds / 3600;
    
    //Compute minutes (1 min = 60 sec)
    minutes = (inputSeconds - (hours * 3600)) / 60;
    
    //Compute seconds
    seconds = (inputSeconds - (hours * 3600) - (minutes * 60));
    
    //Output
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)" << endl;
    return 0;
}