// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 2 - Problem # 4


#include <iostream>
#include <cmath>       // Call cmath library
using namespace std;

int main()
{
    double inputRadius;
    double sphereVolume;
    double sphereSurfaceArea;

    //Request user input 
    cout << "Enter a radius: " << endl;
    cin >> inputRadius;

    //Calculate volume of a sphere
    sphereVolume = (4.0 / 3.0) * M_PI * pow(inputRadius, 3);
    cout << "Volume: " << sphereVolume << endl;
    
    //Calculate surface area of a sphere
    sphereSurfaceArea = 4 * M_PI * pow(inputRadius, 2);
    cout << "Surface area: " << sphereSurfaceArea << endl;


    return 0;
}