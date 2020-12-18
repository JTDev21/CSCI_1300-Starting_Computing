// CS1300 Spring 2020
// Author: Punith Sandhu
// Recitation: 123 – Favorite TA
// Project 101 - Problem X


#include <iostream> 
#include <iomanip>  	// setprecision	
using namespace std; 


/*
 * This function converts a temperature in fahrenheit to celsius
 * and prints the equivalence.
 * Parameters: fahrenheit - degrees fahrenheit
 * Return: equivalent temperature in celsius
*/

double fahrenheit_to_celsius(double fahrenheit){
	double celsius = (fahrenheit - 32) * (5/9.0);
	return celsius; 
}



int main(int argc, char const *argv[])
{
	//----------------------------------------------
	// unit tests: 
	//----------------------------------------------
	
	// cout << fahrenheit_to_celsius(32) << endl; 	
	// expected output: 0  
	// cout << fahrenheit_to_celsius(72) << endl; 	
	// expected output:: 22.22


	// take a temperature in Fahrenheit
	double fahrenheit; 
	cout << "Enter a temperature in Fahrenheit:" << endl; 
	cin >> fahrenheit; 

	double celsius = fahrenheit_to_celsius(fahrenheit); 

	// output the reuslts with a two-digit precision
	cout << "The temperature " << fahrenheit << " degrees Fahrenheit is "; 
	cout << fixed << setprecision(2) << celsius << " degrees Celsius." << endl;
    return 0;
}

