// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 4 - Problem # 1


#include <iostream>
using namespace std;

int main()
{
    int userInput;
    int summation = 0;
    
    //User Input
    cout << "Enter a positive number: " << endl;
    cin >> userInput;
    
    // For loop, counter starts at zero, if counter is less than userInput continue loop and increment counter by 1
    for(int counter = 0; counter <= userInput; counter++) {
        // Even Test, modulo will return a remainder, even numbers return a remainder of zero
        if(counter % 2 == 0) {
            // Same as summation = summation + counter
            summation += counter;
        }
    }
    cout << "Sum: " << summation << endl;
    return 0;
}