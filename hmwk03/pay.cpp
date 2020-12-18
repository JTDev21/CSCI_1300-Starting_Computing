// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 2

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Vairables for hours worked, hourly pay, and total pay
    float hoursWorked, hourlyPayRate, pay;
    
    // Variables for overtime (These are resevered spaces for numerical storage)
    float currentOvertimeHour = 40; // This variable stores the number of hours that is considered the max hours before overtime
    float overtimeRate = 1.5;
    float overtimeHour, overtimePay;
    
    // Request user input for hours worked
    cout << "Enter the number of hours worked" << endl;
    cin >> hoursWorked;
    
    // Request user input for their hourly pay rate
    cout << "Enter an hourly pay rate" << endl;
    cin >> hourlyPayRate;
    
    // Control statement (Determine whether user has worked overtime (over currentOvertimeHour), as well as to check over invalid inputs)
    if (hoursWorked < 0 || hourlyPayRate < 0) {
        // Condition checks if there are negative inputs from user. If either hoursWorked or hourlyPayRate is negative the if statement will print "Invalid Input"
        cout << "Invalid input";
    }
    // if conditions are false, move to else statement for pay calculations
    else {
        //Checks whether user has worked over time
        if (hoursWorked >= currentOvertimeHour) {
            //User has worked overtime
            
            //Calculate how many overtime hours has been work 
            overtimeHour = hoursWorked - currentOvertimeHour;
            
            //Calculate overtime pay with current overtime pay rate and overtime hours
            overtimePay = overtimeHour * overtimeRate * hourlyPayRate;
            
            //Total Pay
            pay = (currentOvertimeHour * hourlyPayRate) + overtimePay;
            
        }
        
        else {
            // Calculate hours worked with hourly pay rate
            pay = hoursWorked * hourlyPayRate;
        }
        
        // Display Pay
        cout << "Paycheck: " << fixed << setprecision(2) << pay;
        
        }
        
        
    
    return 0;
}