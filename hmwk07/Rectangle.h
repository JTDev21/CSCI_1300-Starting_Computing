// CS1300 Spring 2020
// Author: Punith Sandhu
// Recitation: 123 – Favorite TA
// Homework 7 - Problem 101

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream> 
using namespace std; 

class Rectangle{
    private: 
        double width; 
        double length; 
    public: 
        Rectangle(); 
        Rectangle(double width_, double length_); 
        
        void setWidth(double width_); 
        void setLength(double length_); 
        
        double getWidth(); 
        double getLength(); 
        
        double getArea(); 
}; 

#endif










