// // CS1300 Spring 2020
// // Author: Joshua Truong
// // Recitation: 203 – Soumyajyoti Bhattacharya
// // Homework 4 - Problem # 6

//THIRD VERSION OF ALGORITHM -- BEST AND FINAL VERSION  -- Thanks to Murray Cox
#include <iostream>
using namespace std;


int main()
{
    char letter = 'a';
    int userInput;

    cout << "Enter the height: " << endl;
    cin >> userInput;

    //This FOR loop is for the height
    for(int height = userInput; height >= 0; height--)
    {
        //This For loop is for the length
        for(int length = 0; length < height; length++)
        {
            cout << letter;
            if(letter == 'z')
            {
                letter -= 26;
            }
            letter += 1;
        }
        cout << endl;
    }
    return 0;
}



// SECOND VERSION OF ALGORITHM -- Error for height at 33 or above
// #include <iostream>
// #include <string>
// using namespace std;


// int main()
// {
//     double height;
//     int start = 0;
//     const string alpha = "abcdefghijklmnopqrstuvwxyz";

    
//     cout << "Enter the height:" << endl;
//     cin >> height;

//     for(int length = height; length >= 0; length--)
//     {
//         cout << alpha.substr(start, length);
//         start += length;


//         if(start >= 26)
//         {
//             int newLength = 0;
//             newLength = start - 26;
//             start = 0;
//             cout << alpha.substr(start, newLength);
//             start += newLength;

//         }
//         cout << endl;
//     }


//     return 0;
// }
//--------------------------------------------------------------------------------------------------------------------------------------------
// // FIRST VERSION OF ALGORITHM
// #include <iostream>
// #include <string>
// using namespace std;


// int main()
// {
//     double height;
//     const string alpha = "abcdefghijklmnopqrstuvwxyz";
    
//     cout << "Enter the height:" << endl;
//     cin >> height;

//     double summation = 0;
//     double numLength = height;
//     //Finds the number of times that alpha will need to be reused.
//     /* the idea is if we have a height of 10. The first line will use 10 characters, the second line 9 characters. 
//     Adding all the number of characters used will give an exact amount used. So 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 55
//     */
//     while(numLength >= 1)
//     {
//         summation += numLength;
//         numLength--;
//     }

//     // Since we know how many characters will be used given a certain height we need to know how many times to repeat alpha string.
//     // The alphabet has 26 letter so take the sum of characters going to be used and divide it by 26

//     //Concatenate alpha. (rep times )
//     //ex) concatenate alpha 3 times so it is: "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
//     string concat = "";
//     for(int rep = (summation / 26); rep >= 0; rep--){
//         concat += alpha;
//     }


//     double start = 0;
//     for(double length = height; length >= 1; length--)
//     {
//         cout << concat.substr(start, length) << endl;
//         start += length;
//     }



//     return 0;
// }