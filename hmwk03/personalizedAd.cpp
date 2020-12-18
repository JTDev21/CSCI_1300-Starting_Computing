// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 3 - Problem # 6



// I know where you live ( ͡° ͜ʖ ͡°) 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int personalized;
    string userInputString;
    int userInputNum;
    int age;


    cout << "How personalized should the ad be? (1-3)" << endl;
    cin >> personalized;


    switch(personalized) {
            ///////////////////// Personalize 1
        case 1:
            cout << "Do you own a dog?" << endl;
            cin >> userInputString;
            
            if (userInputString == "Yes" || userInputString == "yes") {
                cout << "Meat's the need of dogs like yours!" << endl;
            }
            else {
                cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint." << endl;
            }
            break;
            ////////////////////// Personalize 2
        case 2:
            cout << "How many Facebook friends do you have?" << endl;
            cin >> userInputNum;

            if (userInputNum >= 500) {
                cout << "Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service." << endl;
            }
            else {
                cout << "Who doesn't need another cat? Adopt a shelter pet right meow." << endl;
            }
            break;
            ////////////////////// Personalize 3
        case 3:
            cout << "What is your zip code?" << endl;
            cin >> userInputNum;

            cout << "What is your age?" << endl;
            cin >> age;

            if ((80301 <= userInputNum && userInputNum <= 80310) && (age >= 25)) {
                cout << "You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike." << endl;
            }
            else if ((80301 <= userInputNum && userInputNum <= 80310) && (age <= 25)) {
                cout << "Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen." << endl;
            }
            else {
                cout << "Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO." << endl;
            }
            break;
            //////////////////////
        default:
            cout << "Invalid option." << endl;

    }
    return 0;
}