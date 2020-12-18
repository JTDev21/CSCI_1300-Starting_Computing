// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 6 - Problem # 4
// Well there goes my sanity, 5 hr

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int n;
    bool UW = true;
    string line, word;
    int numUW = 0;
    int numWords = 0;
    string uniqueWords[200]; //There will be at most 200 unique words
    int lambda[200]; // Lambda = frequency, the most this array can hold is 200 words
    string fileName;

    cout << "Enter a filename:" << endl;
    cin >> fileName;

    ifstream myFile;
    myFile.open(fileName);
    if(myFile.fail())
    {
        cout << "Could not open the file." << endl;
    }
    else
    {
        cout << "Enter the value of n: " << endl;
        cin >> n;
        
        while(getline(myFile, line))
        {
            istringstream strm;
            strm.str(line);
            while(getline(strm, word, ' '))
            {
                if(numUW == 0)
                {
                    lambda[0] = -1;
                    uniqueWords[0] = word;
                    numUW++;
                }
                /////
                if(numUW != 0)
                {
                    for(int x = 0; x < numUW; x++)
                    {
                        if(lambda[x] == 0)
                        {
                            lambda[x] = 1;
                        }
                        if(word == uniqueWords[x])
                        {
                            //Add to frequency
                            // cout << word << " == " << uniqueWords[x] << endl;
                            lambda[x] += 1;
                            UW = false;
                        }
                    }
                    if(UW)
                    {
                        if(word != " ")
                        {
                            uniqueWords[numUW] = word;
                            // cout << "uniqueWords[" << numUW - 1 << "] = " << word << endl;
                            numUW++;
                            UW = false;
                        }
                    }
                    UW = true;
                }
                numWords++;
            }
        }
        cout << endl;
////////////////////////////////////////////////////////////////
        int max = 0;
        int max_Location = 0; // Do not change
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < numUW; y++)
            {
                if(lambda[y] > max)
                {
                    // cout << lambda[y] << " > " << max << endl;
                    max = lambda[y];
                    max_Location = y;
                }
            }
            cout << lambda[max_Location] << " - " << uniqueWords[max_Location] << endl;
            lambda[max_Location] = 0; // Removing the max number so I don't detect it after n rounds
            max = 0;            
        }
        cout << endl;
        cout << "Unique words: " << numUW << endl;
        cout << "Total words: " << numWords << endl;
    }
    myFile.close();
    return 0;
}