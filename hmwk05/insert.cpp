// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Homework 5 - Problem # 3
#include <iostream>
using namespace std;

int insert(int after[], int elements, int arrSize, int newElement)
{   
    int numElements;
    if(elements >= arrSize)
    {
        numElements = elements;
    }
    else
    {
        numElements = elements + 1;
        //Find the max value in an array

        for(int i = 0; i < elements; i++)
        {
            if(newElement > after[i])
            {
                after[elements] = newElement;
            }
        }
        
        for(int x = 0; x <= elements; x++)
        {
            if(after[x] >= newElement)
            {
                // cout << "after[" << x << "]: " << after[x] << " > newElement: " << newElement << endl;
                for(int y = elements - 1; y >= x; y--)
                {
                    after[y + 1] = after[y];
                }
                after[x] = newElement;
                x = elements;
            }
        }

    }



    return numElements;
}


int main()
{
    const int arrSize = 6;
    int elements = 5;
    int newElement = 10;
    int before[arrSize] = {1,1,3,4,5};
    int numElements;

    numElements = insert(before, elements, arrSize, newElement);

    
/////////////////////////////////////
    for(int i = 0; i < numElements; i++)
    {
        if(i > 0)
        {
            cout << ",";
        }
        cout << before[i];
    }
    cout << endl;
    return 0;
}


