// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 6 - Problem # 2
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// YESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYESYES
// HELL YA, THIS PROBLEM AND PROBLEM 4, TOOK ME MORE THAN 6 HOURS. I'M SUCH A DUMBASS. FOR READING "(the capacity of the string array or the number of
// rows in the 2D array" AND IGNORING.
int readSales(string fileName, string names[], int sales[][12], int SIZE)
{
    int numberOfLines;
    int numNames = 0;
    int nameLine = 0;
    string number, str_number;
    
    string line;

    ifstream myFile;
    myFile.open(fileName);
    if(myFile.fail())
    {
        return -1; 
    }
    else
    {

        while(getline(myFile, line))
        {
            if(nameLine % 2 == 0 && numNames < SIZE)
            {
                if(line != "")
                {
                    // cout << line << endl;
                    names[numNames] = line;
                    // cout << "numNames: " << numNames << endl;
                    // cout << names[numNames] << endl;
                    numNames++;
                }
            }
            if(nameLine % 2 != 0)
            {
                string concat;
                int current_size = 0;
                istringstream strm;
                strm.str(line);
                while(getline(strm, str_number, ','))
                {
                    for(int i = 0; i < str_number.length(); i++)
                    {
                        if(str_number[i] != ' ')
                        {
                            concat += str_number[i];
                        }
                    }
                    if(current_size < 12)
                    {
                        // cout << "numNames: " << numNames - 1 << " current_size: " << current_size << endl;
                        sales[numNames - 1][current_size] = stoi(concat);
                        // cout << "sales[" << numNames - 1 << "][" << current_size << "] = " << sales[numNames - 1][current_size] << endl; 
                        concat = "";
                        current_size++;
                    }
                    else
                    {
                        current_size = 0;
                    }
                }
                if(numNames == SIZE)
                {
                    return numNames;
                }
            }
            nameLine++;
        }
    }
    myFile.close();
    return numNames;
}
///////////////////////////////////////////////////////////////////////////////////////
//BONUS QUESTION
//Calculate average
double average(string names[], int sales[][12], int numNames)
{
    double sum = 0;
    double avg = 0;
    for(int x = 0; x < numNames; x++)
    {

        for(int y = 0; y < 12; y++)
        {
            sum += sales[x][y];
        }
        avg = sum / 12;
        cout << names[x] << ": " << fixed << setprecision(2) << avg << endl;
        sum = 0;
        avg = 0;
    }
    
    return avg;
}


int main()
{
    string fileName;
    int SIZE;

    cout << "Enter the file name: " << endl;
    cin >> fileName;

    cout << "Enter the Size: " << endl;
    cin >> SIZE;
    cout << endl;
    int numNames;
    string names[SIZE];
    int sales[SIZE][12];

    // cout << "Enter the file name: " << endl;
    // cin << fileName;

    numNames = readSales(fileName, names, sales, SIZE);
    average(names, sales, numNames);


    return 0;
}