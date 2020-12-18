// CS1300 Spring 2020
// Author: Punith Sandhu
// Recitation: 123 – Favorite TA
// Homework 7 - Problem 101

#include <iostream>
#include "Rectangle.h"
using namespace std; 

int main(){
    
    // unit tests for constructors
    Rectangle r1; 
    cout << r1.getWidth() << endl;      // expected: 0 
    cout << r1.getLength() << endl;     // expected: 0 
    
    // unit tests for parameterized constructor
    Rectangle r3(2, 3); 
    cout << r3.getWidth() << endl;      // expected: 2
    cout << r3.getLength() << endl;     // expected: 3 
    cout << r3.getArea() << endl;       // expected: 6  
    
    // unit tests for setters 
    Rectangle r2; 
    r2.setWidth(5);
    r2.setLength(10);
    cout << r2.getWidth() << endl;      // expected: 5
    cout << r2.getLength() << endl;     // expected: 10 
    cout << r2.getArea() << endl;       // expected: 50 

}




