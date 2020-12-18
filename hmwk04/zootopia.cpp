// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 4 - Problem # 3


#include <iostream>
using namespace std;

int main()
{
    int menuOption = 0;
    //Turns out if I used int instead of float cloud9 makes the while loop run forever, even though the next step is to get another input
    float agility, strength, speed;
    float hireScore;

    // Since menuOption is already given a value of 0 and it is not a 4
    while(menuOption != 4){
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. Fox" << endl << "2. Bunny" << endl << "3. Sloth" << endl << "4. Quit" << endl;
        cin >> menuOption;
        
        switch(menuOption){
            case 1:
                speed = 0;
                
                cout << "Enter agility: " << endl;
                cin >> agility;
                
                cout << "Enter strength:" << endl;
                cin >> strength;
                break;
            case 2:
                strength = 0;
                
                cout << "Enter agility: " << endl;
                cin >> agility;
                
                cout << "Enter speed: " << endl;
                cin >> speed;
                break;
            case 3:
                agility = 0;
                
                cout << "Enter strength:" << endl;
                cin >> strength;

                cout << "Enter speed: " << endl;
                cin >> speed;
                break;
            case 4:
                break;
            default:
                cout << "Invalid option" << endl;

        }
        if(menuOption == 1 || menuOption == 2 || menuOption == 3)            {
            hireScore = (1.8 * agility) + (2.16 * strength) + (3.24 * speed);
            cout << "Hire Score: " << hireScore << endl;
        }  

    }
    cout << "Good bye!" << endl;
    exit(-1);
    return 0;
}