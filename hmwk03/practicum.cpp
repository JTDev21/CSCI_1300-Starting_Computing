// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float prac1, prac2, prac3;
    float averageScore;
    
    //Request user input
    cout << "Enter practicum 1 score: " << endl;
    cin >> prac1;
    
    cout << "Enter practicum 2 score: " << endl;
    cin >> prac2;
    
    cout << "Enter practicum 3 score: " << endl;
    cin >> prac3;
    
    //Calculate average score
    averageScore = (prac1 + prac2 + prac3) / 3;
    
    // Display average score
    cout << "Practicum average: " << fixed << setprecision(2) << averageScore << endl;
    
    
    //Determine if student has a passing/failing grade
    if (averageScore >= 67) {
        cout << "You have a passing practicum average.";
    }
    else {
     cout << "You can retake practicums during the final.";    
    }

    
    return 0;
}