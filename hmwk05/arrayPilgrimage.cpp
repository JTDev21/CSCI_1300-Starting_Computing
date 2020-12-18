// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 1

#include <iostream>
#include <string>
using namespace std;

int main()
{
    double temps[10];
    for(int i = 0; i <= 9; i++)
    {
        temps[i] = -459.67;
        cout << temps[i] << endl;
    }

    cout << endl;

    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    for(int i = 0; i <= 4; i++)
    {
        cout << colors[i] << endl;
    }

    cout << endl;

    int sequence[100];
    for(int i = 0; i <= 99; i++)
    {
        sequence[i] = i + 1;
        cout << sequence[i] << endl;
    }

    cout << endl;

    char letters[52];
    for(int i = 0; i <= 25; i++)
    {
        letters[i] = char(65 + i);
        cout << letters[i] << " ";

        letters[i + 1] = char(97 + i);
        cout << letters[i + 1] << endl;
    }
    return 0;
}
