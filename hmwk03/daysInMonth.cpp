// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 5

// OuT oF ALl tHEsE PrOBLemS, ThiS oNe gAVe mE SOMe AnEuRySM

#include <iostream>
using namespace std;

int main()
{
    int year, month, days;

    cout << "Enter a year:" << endl;
    cin >> year;


    bool error = false;
    bool afterGreg = (year >= 1582);
    bool divisBy4 = (year % 4 == 0);
    bool divisBy100 = (year % 100 == 0);
    bool divisBy400 = (year % 400 == 0);



    cout << "Enter a month:" << endl;
    cin >> month;


    switch(month) {
        case 1:
            // January
            days = 31;
            break;
        case 2:
        // February
            /* If the year is after 1582 determine if it is a leap year by seeing if the year is divisible by 4, 100, 400. 
            Else divide the year by 4 if remainder returns zero it is a leap year(Feb. has 29 days). Else Feb has 28 days*/
            if (afterGreg) {
                if (divisBy4) {
                    // If divisible by 4. We have a leap year
                    days = 29;
                    if (divisBy100) {
                        // (Except if) If year is divisible by 100. We do not have a leap year
                        days = 28;
                        if (divisBy400) {
                            // (Except if) If year is divisible by 400. We have a leap year
                            days = 29;

                        }
                    }
                }else {
                    days = 28;
                }


            }
            else if (divisBy4) {
                days = 29;
            }
            else {
                days = 28;
            }
            break;
        case 3:
            // March
            days = 31;
            break;
        case 4:
            // April
            days = 30;
            break;
        case 5:
            // May
            days = 31;
            break;
        case 6:
            // June
            days = 30;
            break;
        case 7:
            // July
            days = 31;
            break;
        case 8:
            // August
            days = 31;
            break;
        case 9:
            // September
            days = 30;
            break;
        case 10:
            // October
            days = 31;
            break;
        case 11:
            // November
            days = 30;
            break;
        case 12:
            // December
            days = 31;
            break;
        default:
            error = true;
    }


    if (error == true) {
        cout << "Invalid month" << endl;
    }
    else {
        cout << days << " days" << endl;
    }
    return 0;
}