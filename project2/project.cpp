#include <iostream>
#include "Book.h"
#include "User.h"
#include "Library.h"

using namespace std;

int main()
{
    Library library;
    int uI;
    
    do
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. View ratings" << endl;
        cout << "4. Print all books" << endl;
        cout << "5. Update a rating" << endl;
        cout << "6. Add a user" << endl;
        cout << "7. Get recommendations" << endl;
        cout << "8. Get average rating" << endl;
        cout << "9. Quit" << endl;

        if(!(cin >> uI))
        {
            cout << "Enter only integers!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            int numBooks, numUsers, min_rating, new_rating;
            string bookFileName, userFileName, username, title;
            switch(uI)
            {
                case 1:
                    cout << "Enter a book file name:" << endl;
                    cin >> bookFileName;
                    numBooks = library.readBooks(bookFileName);
                    if(numBooks == -1)
                    {
                        cout << "No books saved to the library." << endl;
                    }
                    else
                    {
                        cout << "Total books in the library: " << library.getNumBooks() << endl;
                    }
                    break;
                case 2:
                    cout << "Enter a user file name:" << endl;
                    cin >> userFileName;
                    numUsers = library.readRatings(userFileName);
                    if(numUsers == -1)
                    {
                        cout << "No users saved to the library." << endl;
                    }
                    else
                    {
                        cout << "Total users in the library: " << library.getNumUsers() << endl;
                    }
                    break;
                case 3:
                    cout << "Enter a user name:" << endl;
                    cin >> username;
                    cout << "Enter a minimum rating:" << endl;
                    cin >> min_rating;
                    library.viewRatings(username, min_rating);
                    break;
                case 4:
                    library.printAllBooks();
                    break;
                case 5:
                    cout << "Enter a user name:" << endl;
                    cin >> username;
                    cin.ignore();
                    cout << "Enter a book title:" << endl;
                    getline(cin, title);
                    
                    cout << "Enter a new rating:" << endl;
                    cin >> new_rating;
                    library.updateRating(username, title, new_rating);
                    break;
                case 6:
                    cout << "Enter a user name:" << endl;
                    cin >> username;
                    library.addUser(username);
                    break;
                case 7:
                    cout << "Enter a user name:" << endl;
                    cin >> username;
                    library.getRecommendations(username);
                    break;
                case 8:
                    cout << "Enter a user name: " << endl;
                    cin >> username;
                    library.averageRating(username);
                case 9:
                    cout << "Good bye!" << endl;
                    break;
                default:
                    cout << "Invalid option." << endl;
                    break;
            }
        }
        
    }while(uI != 9);
    
    return 0;
}