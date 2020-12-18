// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 2 - Problem # 5


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double fahrenheit;
    double celsius;
    
    // Request user input in fahrenheit
    cout << "Enter a temperature in Fahrenheit: " << endl;
    cin >> fahrenheit;
    
    // Convert fahrenheit to celsius
    celsius = (5.0 / 9) * (fahrenheit - 32);
    

    cout << "The temperature " << fahrenheit << " degrees Fahrenheit is " << fixed << setprecision(2) << celsius <<  " degrees Celsius." << endl;

    return 0;
}