// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Extra Credit

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string uI;
    vector<int> alphaCount(26);

    cout << "Enter a word: " << endl;
    cin >> uI;

    //Iterate string
    for(int x = 0; x < uI.length(); x++)
    {
        //Iterate alphabet using ASCII values
        for(int y = 0; y <= 25; y++)
        {
            // If letter equals ACII table add one to vector
            if(uI[x] == char(97 + y))
            {
                alphaCount[y] += 1;
            }
        }
    }

    //Print 
    //Iterate through vector
    for(int i = 0; i <= 25; i++)
    {
        //If value at a certain index is not zero then do the following
        if(alphaCount[i] != 0)
        {
            cout << char(97 + i) << ": " << alphaCount[i] << endl;
        }
    }
    return 0;
}