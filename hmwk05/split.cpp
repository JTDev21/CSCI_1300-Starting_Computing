// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 6

#include <iostream>
#include <string>
using namespace std;


//The gratification 
int split(string uI, char delimiter, string arr[], int size)
{
    int currentSize = 0;
    char sArr[1000];

    //Split string into characters and store it into an array sArr
    for(int i = 0; i < uI.length(); i++)
    {
        sArr[i] = uI[i];
    }

    //Concatnate char sArr if char does not equal delimiter
    string concat = "";
    for(int i = 0; i <= uI.length(); i++)
    {
        if(sArr[i] != delimiter && i != uI.length())
        {
            concat += sArr[i];
        }
        else
        {
            //Checks if there's more than one delimiter, if there was then it would have an empty string which is something we do not want. So we will ignore it and not store it into the final array
            if(concat != "")
            {
                arr[currentSize] = concat;
                currentSize++;
            }
            //Reset concatenated char
            concat = "";
        }
    }

    //Checks avaiable size
    if(currentSize >= size)
    {
        return -1;
    }

    for(int i = 0; i < currentSize; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl; 
    }

    return currentSize;
}

int main()
{
    string uI;
    char delimiter;
    int size;

    cout << "Enter the text: ";
    getline(cin, uI);

    cout << "Enter the separator: ";
    cin >> delimiter;

    cout << "Enter Size: ";
    cin >> size;

    string arr[size];
    int returnedValue;
    returnedValue = split(uI, delimiter, arr, size);
    cout << "Returned Value: " << returnedValue << endl;
    return 0;
}