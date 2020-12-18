// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sushi;
    float itemCost = 1.99;
    float discountRate = 1;
    float pay;
    
    cout << "Enter the number of sushi: " << endl;
    cin >> sushi;
    
    
    if (sushi <= 0) {
        // Condition checks if there are negative inputs from user. If true will print "Invalid Input"
        cout << "Invalid input";
    }
    
    else{
        if (10 <= sushi && sushi <= 19) {
            //Range: [10,19]
            discountRate = 0.9;
        }
        else if (20 <= sushi && sushi <= 49) {
            //Range: [20,49]
            discountRate = 0.85;
        }
        else if (50 <= sushi && sushi <= 99) {
            //Range: [50,99]
            discountRate = 0.8;
        }
        else if (100 <= sushi) {
            //Range: [100,inf]
            discountRate = 0.75;
        }
        
        // Calculate Pay
        pay = sushi * itemCost * discountRate;
        cout << "Total price: $" << fixed << setprecision(2) << pay;
    }

    return 0;
}