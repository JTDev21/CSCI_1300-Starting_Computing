// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 6 - Problem # 1
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

////////////////

int main()
{   
    string fileName;
    cout << "Enter the file name: " << endl;
    cin >> fileName;


    // Creating a stream called pf
    ifstream pf;
    string line;

    vector<string> temp;
    int i = 0;
    pf.open(fileName);

    if(pf.fail())
    {
        cout << "Could not open file." << endl; 
    }
    else
    {
        while(getline(pf, line))
        {
            for(int x = 0; x < line.length(); x++)
            {
                if(line[x] == ',' && line[x] != ' ')
                {
                    temp.push_back(line.substr(0, x));
                    temp.push_back(line.substr(x + 2, line.length() - x - 1));
                }
            }
            
        }
        pf.close();

        //COnvert string to double
        double productPrice;
        double mostExpensive = 0;
        int locationOfMEProduct = 0;
        double leastExpensive = stod(temp[1]);
        int locationOfLEProduct = 0;

        istringstream sToNprice;
        for(int i = 0; i < temp.size(); i++)
        {
            if(i % 2 != 0)
            {
                productPrice = stod(temp[i]);

                // Determine which is the most expensive product
                if(productPrice > mostExpensive)
                {
                    mostExpensive = productPrice;
                    locationOfMEProduct = i - 1;
                }
                if(productPrice < leastExpensive)
                {
                    leastExpensive = productPrice;
                    locationOfLEProduct = i - 1;
                }
                // cout << "productPrice: " << productPrice << " leastExpensive: " << leastExpensive << endl;

            }
        }

        cout << "The number of lines: " << temp.size() / 2 << endl; 
        cout << "The most expensive product: " << temp[locationOfMEProduct] << endl;
        cout << "The least expensive product: " << temp[locationOfLEProduct] << endl;
    }
    return 0;
}