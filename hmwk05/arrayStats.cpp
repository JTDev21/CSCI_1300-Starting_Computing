// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 2

#include <iostream>
#include <iomanip>
using namespace std;

void stats(double iNum[], int element)
{
    //These variables values have been arbitarily choosen from the array
    double min = iNum[0];
    double max = iNum[0];
    double sum, avg;
    for(int i = 0; i <= (element - 1); i++)
    {
        if(iNum[i] >= max)
        {
            max = iNum[i];
        }
        else if (iNum[i] <= min)
        {
            min = iNum[i];
        }
        sum += iNum[i];
    }
    avg = sum / element;
    cout << "Min: " << fixed << setprecision(2) << min << endl;
    cout << "Max: " << max << endl;
    cout << "Avg: " << avg << endl;
}

int main()
{
    int element = 5;
    double iNum[element];
    cout << "Enter five numbers: " << endl;
    for(int i = 0; i <= (element - 1); i++)
    {
        cin >> iNum[i];
    }

    stats(iNum, element);
    return 0;
}
