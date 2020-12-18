// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 2 - Problem # 7


#include <iostream>
using namespace std;


// BTW lets increase the death rate, yeah? #coronavirus
int main()
{
    int inputPopulation, estimatedPopulation;
    int birth, death, immigrant;
    
    int birthRate = 8;
    int deathRate = 12;
    int immigrantRate = 27;
    int yearToSec = 1 * 365 * 24 * 3600;
    
    
    
    //Request input for current population
    cout << "Enter the current population: " << endl;
    cin >> inputPopulation;
    
    // Calculate the number of births, deaths, and immigrants
    birth = yearToSec / birthRate;
    death = yearToSec / deathRate;
    immigrant = yearToSec / immigrantRate;
    
    //Calculate the estimated population
    // "Oh yeah, it's all coming together" - Kronk
    estimatedPopulation = inputPopulation + birth + immigrant - death;
    
    cout << "The population in one year: " << estimatedPopulation;
    
    
    return 0;
}