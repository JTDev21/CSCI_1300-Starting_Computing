// CS1300 Spring 2020
// Author: Punith Sandhu
// Recitation: 123 – Favorite TA
// Homework 7 - Problem 101

#include <iostream> 
#include "Rectangle.h"
using namespace std; 


Rectangle::Rectangle(){
    width = 0; 
    length = 0; 
    
}
Rectangle::Rectangle(double width_, double length_){
    width = width_; 
    length = length_; 
    
}

void Rectangle::setWidth(double width_){
    width = width_; 
}

void Rectangle::setLength(double length_){
    length = length_; 
}

double Rectangle::getWidth(){
    return width; 
}
double Rectangle::getLength(){
    return length; 
}

// calculate the area of this rectangle
// returns the area as double 
double Rectangle::getArea(){
    return width * length; 
}