// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 4 - Problem # 2

#include <iostream>
using namespace std;

int main()
{
    int collatzConjec;
    
    //collatzConjec variable will serve as a temporary storage for userInput and will store value if collatzConjec does not equal 1 
    cout << "Enter a positive number: " << endl;
    cin >> collatzConjec;
    cout << collatzConjec << endl;
    
    //while loop will run if collatzConjec does not equal 1
    while(collatzConjec != 1){
        //even test
        if(collatzConjec % 2 == 0){
            //collatzConjec = n/2
            collatzConjec = (collatzConjec / 2);
        }
        // Odd number
        else {
            //collatzConjec = 3n + 1
            collatzConjec = ((3 * collatzConjec) + 1);
        }
        cout << collatzConjec << endl;
        
    }
    
    return 0;
}