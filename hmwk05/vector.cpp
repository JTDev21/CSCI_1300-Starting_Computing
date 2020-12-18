// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 5

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int userInput;
    bool empty = true;
    vector<int> memFunc;
    do
    {
        cout << "Please enter a number: " << endl;
        cin >> userInput;
        
        //Vectors are empty
        if(memFunc.size() == 0)
        {
            // cout << "Vectors are empty" << endl;
            memFunc.push_back(userInput);
            empty = false;
        }
        //If vectors are not empty and divisible by 5
        else if(!empty && (userInput % 5 == 0))
        {
            // cout << "Vector is not empty and divisible by 5" << endl;
            memFunc.erase(memFunc.begin() + 0);
        }
        //If vectors are not empty and divisible by 3
        else if(!empty && (userInput % 3 == 0))
        {
            // cout << "vectors are not empty and divisible by 3" << endl;
            memFunc.pop_back();
        }
        //Otherwise insert value at the end of vector
        else
        {
            if(userInput == -1){}
            else
            {
            // cout << "Otherwise insert value at end" << endl;
            memFunc.push_back(userInput);
            }
        }
    }while(userInput != -1);


    //These variables values have been arbitarily choosen from the vector
    int min = memFunc[0];
    int max = memFunc[0];
    for(int i = 0; i <= (memFunc.size() - 1); i++)
    {
        if(memFunc[i] >= max)
        {
            max = memFunc[i];
        }
        else if (memFunc[i] <= min)
        {
            min = memFunc[i];
        }

    }
   
    cout << "The elements in the vector are: ";
    for(int i = 0; i < memFunc.size(); i++)
    {
        if(i > 0){cout << " ";}
        cout << memFunc[i];
    }
    cout << endl; 

    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;


    return 0;
}