// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 4 - Problem # 5


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sString, subString, algor;
    int sLength, subLength;
    int matchCase = 0;


    cout << "Enter the search string: " << endl;
    cin >> sString;

    cout << "Enter the substring to be searched: " << endl;
    cin >> subString;

    sLength = sString.length();
    subLength = subString.length();

    for(int start = 0; start <= sLength; start++)
    {
        algor = sString.substr(start, subLength);
        if (algor == subString)
        {
            matchCase++;
        }
    }
    cout << "Number of occurrences: " << matchCase << endl;
    return 0;
}