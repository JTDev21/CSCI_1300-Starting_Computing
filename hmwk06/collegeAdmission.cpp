// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 6 - Problem # 3
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void process(string temp[])
{
    // for(int i = 0; i < 9; i++)
    // {
    //     cout << "temp[" << i << "]: " << temp[i] << endl;
    // }
    if(temp[0] != "")//Without this I will read the firstline which should have empty spaces
    {
        string criteria;

        double normalizedGPA = stod(temp[2]) * 2;
        double normalizedSAT = stod(temp[1]) / 160;

        string student = temp[0];
        double sat = normalizedSAT * 0.3;
        double gpa = normalizedGPA * 0.4;
        double interest = stod(temp[3]) * 0.1;
        double HSQuality = stod(temp[4]) * 0.2;
        double sem1 = stod(temp[5]);
        double sem2 = stod(temp[6]);
        double sem3 = stod(temp[7]);
        double sem4 = stod(temp[8]);

        double algorithm = gpa + sat + interest + HSQuality; //One line to rule them all

        if(algorithm >= 6)
        {
            criteria = ",score";
        }
        else
        {
            //Outliers
            if((interest == 0 || normalizedGPA - normalizedSAT > 2) && (algorithm >= 5))
            {
                criteria = ",outlier";
            }
            //Grade Improvement
            if((sem1 < sem2 && sem2 < sem3 && sem3 < sem4) && algorithm >= 5)
            {
                criteria = ",grade improvement";
                // cout << sem1 << " < " << sem2 << " < " << sem3 << " < " << sem4 << endl;
            }
        }
        cout << student << ',' << algorithm << criteria << endl;
    }
}

int main()
{
    string fileName;
    cout << "Enter the file name: " << endl;
    cin >> fileName;

    ifstream myFile;
    myFile.open(fileName);
    if(myFile.fail())
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "\nResults: " << endl;
        // Student,SAT,GPA,Interest,High School Quality,Sem1,Sem2,Sem3,Sem4
        int skip = 0;
        string line;
        string data;
        string temp[9];
        int spot = 0;

        while(getline(myFile, line, '\n'))
        {
            istringstream column;
            column.str(line);
            while(getline(column, data, ','))
            {
                if(skip > 8)
                {
                    temp[spot] = data;
                    spot++;
                }
                skip++; 
            }
            spot = 0;
            process(temp);
        }
    }
    myFile.close();
    return 0;
}