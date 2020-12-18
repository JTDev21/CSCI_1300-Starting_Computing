// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 2 - Problem # 3

#include <iostream>
using namespace std;

int main(){
    int coldTemp;
    int hotTemp;
    float carnotEff;
    
    //request cold temperature input
    cout << "Enter cold reservoir temperature: " << endl;
    cin >> coldTemp;
    
    //request hot temperature input
    cout << "Enter hot reservoir temperature: " << endl;
    cin >> hotTemp;
    
    /*Calculate carnot's efficiency (Notice hotTemp * 1.0. The 1.0 is necessary 
    in order to tell c++ we want it to calculate the equation and return a float and not an integer)*/
    carnotEff = 1 - (coldTemp / (hotTemp * 1.0));
    cout << "Carnot efficiency: " << carnotEff;
    
    return 0;
}