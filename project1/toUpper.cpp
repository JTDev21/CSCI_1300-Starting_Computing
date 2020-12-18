// CS1300 Spring 2020
// Author: Joshua Truong
// Recitation: 203 – Soumyajyoti Bhattacharya
// Project 1 - Problem # 3

// Second Version With ASCII table
#include <iostream>
#include <string>
using namespace std;

string toUpper(string user)
{
    
    //Iterates through user string
    for(int i = 0; i < user.length(); i++)
    {
        // 65-90 capitalcase Letters
        // 97-122 lowercase letters
        // The difference between these two letters is 32
        //97-65 = 32
        //search for lowercase letters in ACSII table 
        for(int j = 97; j <= 122; j++)
        {
            if(user[i] == char(j))
            {
                user[i] = char(j - 32);
            }
        }
    }
    return user;
}


int main()
{
    string user, newString;

    cout << "Enter the string: " << endl;
    getline(cin, user);

    newString = toUpper(user);
    cout << newString << endl;
    return 0;
}


// // First Version -- Without ASCII table
// #include <iostream>
// #include <string>
// using namespace std;

// string toUpper(string user)
// {
//     string concat = "";
//     string capAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     string lowAlpha = "abcdefghijklmnopqrstuvwxyz";
    
//     //Iterates through user string
//     for(int i = 0; i < user.length(); i++)
//     {
//         //Checks if a character in the user string is from a-z lowercase
//         if('a' <= user[i] && user[i] <= 'z')
//         {
//             //variable ls stands for lowercase search
//             for(int ls = 0; ls <= 25; ls++)
//             {
//                 //If user[i] (range of lowercases a-z) is equal to lowAlpha[ls]. The purpose of this loop is to determine the index number.
//                 // Since lowAlpha and capAlpha have 26 letters, when iterating I will know which index number will correspond to the capialize number.
//                 //example: a has an index of 0, thus A will have an index at 0
//                 //example: z has an index of 25, thus Z will have an index at 25
//                 if(user[i] == lowAlpha[ls])
//                 {
//                     //Replacing lower case with uppercase by concatenation
//                     concat += capAlpha[ls];
//                 }
//             }
//         }
//         else
//         {
//             //If letter in string is already capilizied then concatenate into concat
//             concat += user[i];
//         }
//     }
//     return concat;
// }


// int main()
// {
//     string user, newString;

//     cout << "Enter the string: " << endl;
//     getline(cin, user);

//     newString = toUpper(user);
//     cout << newString << endl;
//     return 0;
// }
