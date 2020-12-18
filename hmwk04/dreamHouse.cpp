// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 4 - Problem # 4


#include <iostream>
using namespace std;

int main()
{
    double salary, pSavings, homeCost, salarySavings;
    float pDownPay = 0.25;
    double currentSavings = 0;
    float investment;
    int months = 1;

    cout << "Enter your annual salary: " << endl;
    cin >> salary;

    cout << "Enter the percent of your salary to save, as a decimal: " << endl;
    cin >> pSavings;

    cout << "Enter the cost of your dream home: " << endl;
    cin >> homeCost;

    salarySavings = (salary * pSavings) / 12;
    currentSavings += salarySavings;
    homeCost = homeCost * pDownPay;

    while(currentSavings < homeCost){
        investment =  currentSavings * (0.04 / 12);
        currentSavings += investment + salarySavings;
        months++;
    }
    cout << "Number of months: " << months << endl;
    return 0;
}