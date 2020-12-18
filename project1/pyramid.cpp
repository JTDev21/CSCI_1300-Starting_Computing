// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 1 - Problem # 1
#include <iostream>
#include <cmath>
using namespace std;


double surfaceArea(double length, double height)
{
    if(length < 0 || height < 0)
    {
        return -1;
    }
    else
    {
        double triangle, square, SA;

        
        triangle = (1.0 / 2) * length * height;
        
        square = pow(length, 2);

        SA = square + (4 * triangle);
        return SA;
    }
}

int main()
{
    double height, length, SA;
    cout << "Enter the base length:" << endl;
    cin >> length;
    
    cout << "Enter the slant height:" << endl;
    cin >> height;
    
    SA = surfaceArea(length, height);
    if (SA != -1)
    {
        cout << "The surface area: " << SA << endl;
    }
    else
    {
        cout << "Invalid values" << endl;
    }
    return 0;
}