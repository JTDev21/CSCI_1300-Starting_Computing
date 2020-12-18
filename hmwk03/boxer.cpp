// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 4

#include <iostream>
using namespace std;

int main()
{
    int weight1, weight2, weight3;
    
    // Request user input for weight
    cout << "Enter boxers' weights" << endl;
    cin >> weight1 >> weight2 >> weight3;
    
    //There are 2 things we must condition for before we use Neither, check if input is in ascending or descending order
    if (weight1 < weight2 && weight2 < weight3) {
        // weight 1 is less than weight2 and weight2 is less than weight3
        cout << "Ascending order" << endl;
    }
    else if (weight1 > weight2 && weight2 > weight3) {
        // weight 1 is greater than weight2 and weight2 is greater than weight3
        cout << "Descending order" << endl;
    }

    else {
        cout << "Neither" << endl;
    }
    return 0;
}