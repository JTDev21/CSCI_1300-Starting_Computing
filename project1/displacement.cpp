// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 1 - Problem # 2
#include <iostream>
using namespace std;

// I -- Inital velocity
// F -- Final Velocity
//A -- Accleration

double displacement(double I, double F, double A)
{
    double displacement;
    if(I < 0 || A == 0 || A < 0 || F > I || F < 0)
    {
        if(I < 0 || F < 0)
        {
            cout << "Velocity should be greater than zero." << endl;
        }
        if(A == 0)
        {
            cout << "No brakes were applied." << endl;
        }
        if(A < 0)
        {
            cout << "The vehicle is speeding up." << endl;
        }
        if(F > I)
        {
            cout << "Error in acceleration values." << endl;
        }
        return 0;
    }
    else
    {
        displacement = ((F * F) - (I * I)) / (-2 * A);
        return displacement;
    }
}

int main()
{
    double I, F, A, dis;
    cout << "Enter initial velocity: " << endl;
    cin >> I;

    cout << "Enter final velocity: " << endl;
    cin >> F;
    
    cout << "Enter deceleration: " << endl;
    cin >> A;
    
    dis = displacement(I, F , A);
    cout << "Displacement is " << dis << endl;
    return 0;
}