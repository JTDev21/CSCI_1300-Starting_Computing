// // Homework 4
// // EXTRA CREDIT: 10 pt


//Third Version with 3 less FOR loop
#include <iostream>
using namespace std;

int main()
{
    int space;
    int asterisk;
    int length;

    cout << "Enter the length: " << endl;
    cin >> length;

    int doubleLength = (2 * length) - 1;

    for(int i = 0; i < doubleLength; i++){
        
        if(i >= length)
        {
            asterisk += -2;
            space = space + 1;
        }
        else
        {
            asterisk = 1 + (2 * i);
            space = length - i - 2;  
        }

        // Prints out spaces and asterisks
        for(int spaceCounter = space; spaceCounter >= 0; spaceCounter--)
        {
            cout << " ";
        }
        for(int asteriskCounter = 1; asteriskCounter <= asterisk; asteriskCounter++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


// #include <iostream>
// using namespace std;

// int main()
// {
//     int space;
//     int asterisk;
//     int length;

//     cout << "Enter the length: " << endl;
//     cin >> length;

//     //Lines Top
//     // In this 1st nested for loop, Spaces decreases while asterisks increases
//     for(int i = 0; i < length; i++){
//         /*i must start at zero so that #asterisk in the first line is one.
//         Calculates the number of spaces and asterisk (or convient purposes: dashes represent spaces)
//         ---*            
//         --***
//         -*****
//         --***
//         ---* 
//         !!! Notice that the asterisk in each line is increased by 2. Thus the number of asterisk is 1 + (2 * i)
//             f(i) = 1 + (2 * i)
//                 ex) f(0) = 1
//                     f(1) = 3
//                     f(2) = 5
//                     f(3) = 7
        
//         !!! Notice the number of space decreases by 1
//             g(i) = length - 1 - i
//             since i starts at zero, the space length will equal to that of what the userInputted so we must subtract 1 from it. 
//             In addition, it must decrease by 1 so we can subtract the length by -i
//                 ex) Assume length = 4 
//                 g(0) = 3
//                 g(1) = 2
//                 g(2) = 1
//                 g(1) = 0
        
//         */
//         asterisk = 1 + (2 * i);
//         space = length - i - 2;

//         /*Loop for space --> Since we know how much space we need for each line we need to iterate it
//             spaceCounter will decrease by 1, condition is that the spaceCounter needs to be bigger than or equal to zero. In order to make loop true
//         */
//         for(int spaceCounter = space; spaceCounter >= 0; spaceCounter--){
//             cout << " ";
//         }

//         /*Loop for asterisk --> We know how many asterisk is needed
//             If asteriskCounter started at 0, it would loop more than neccessary. Since the first line has one asterisk, we need to start there.
//             Since our condition states the number of asterisk we know we need needs to be greater than the asterisk counter

//         */
//         for(int asteriskCounter = 1; asteriskCounter <= asterisk; asteriskCounter++){
//             cout << "*";
//         }
//         cout << endl;
//     }

//     //Everything here is basically the same; however in reverse
//     //Lines Bottom
//     // In this 2nd nested for loop, Spaces increases while asterisks decreases.
//     for(int i = length; i > 0; i--){
//         asterisk = (2 * i) - 3;
//         space = space + 1;

//         for(int spaceCounter = space; spaceCounter >= 0; spaceCounter--){
//             cout << " ";
//         }

//         for(int asteriskCounter = 1; asteriskCounter <= asterisk; asteriskCounter++){
//             cout << "*";
//         }
//         cout << endl;
//     }
    
//     return 0;
// }

// Homework 4
// EXTRA CREDIT: 10 pt




// Homework 4
// EXTRA CREDIT: 10 pt

// //Second Version with one less FOR loop
// #include <iostream>
// using namespace std;

// int main()
// {
//     int space;
//     int asterisk;
//     int length;

//     cout << "Enter the length: " << endl;
//     cin >> length;

//     int doubleLength = (2 * length) - 1;


//     for(int i = 0; i < doubleLength; i++){
        
//         if(i >= length)
//         {
//             asterisk += -2;
//             space = space + 1;

//             for(int spaceCounter = space; spaceCounter >= 0; spaceCounter--){
//                 cout << " ";
//             }

//             for(int asteriskCounter = 1; asteriskCounter <= asterisk; asteriskCounter++){
//                 cout << "*";
//             }
//         }
//         else
//         {
//             asterisk = 1 + (2 * i);
//             space = length - i - 2;
//             for(int spaceCounter = space; spaceCounter >= 0; spaceCounter--)
//             {
//                 cout << " ";
//             }
//             for(int asteriskCounter = 1; asteriskCounter <= asterisk; asteriskCounter++)
//             {
//             cout << "*";
//             }
            
//         }
//         cout << endl;
//     }

//     return 0;
// }