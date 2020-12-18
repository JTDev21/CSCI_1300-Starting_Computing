// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 4
#include <iostream>
using namespace std;

int maxSum(int D2Arr[][10], int rows)
{
    int sum = 0;

    //D2Arr[x][y]
    for(int x = 0; x < rows; x++)
    {
        //Max value at the beginning of each row
        int max = D2Arr[x][0];
        for(int y = 0; y <= 9; y++)
        {
            //if a value is bigger than the max reassign it so it is the max
            if(D2Arr[x][y] > max)
            {
                max = D2Arr[x][y];
            }
        }
        sum += max;
    }

    return sum;
}


int main()
{
    int rows = 10;
    int D2Arr[][10] = {
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1,  4, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    };

    int sum;
    sum = maxSum(D2Arr, rows);

    cout << "max sum: " << sum << endl;
    return 0;
}