#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Library.h"
#include "User.h"
#include "Book.h"

using namespace std;

string unzip(string bookOrUserFile, int oneOrTwo, string lineToSeparate)
{
    istringstream dataLine;
    dataLine.str(lineToSeparate);
    string one, two;
    if(bookOrUserFile == "book")
    {
        //One = author || Two = title
        getline(dataLine, one, ',');
        getline(dataLine, two, ',');
    }
    else if(bookOrUserFile == "user")
    {
        //One = username || Two = ratings
        getline(dataLine, one, '|');
        getline(dataLine, two, '|');
    }
    if(oneOrTwo == 1)
    {
        return one;
    }
    return two;
}

string insensitiveCase(string convertMe)
{
    for(int i = 0; i < convertMe.length(); i++)
    {
        // 97-122 lowercase letters
        // The difference between lower and upper case value from ascii: 32
        //search for uppercase letters in ACSII table 
        for(int j = 65; j <= 90; j++)
        {
            if(convertMe[i] == char(j))
            {
                convertMe[i] = char(j + 32);
            }
        }
    }
    return convertMe;
}

////////////////////////////////////////////////////////////////////////////////
Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

int Library::getNumBooks() const
{
    return numBooks;
}

int Library::getNumUsers() const
{
    return numUsers;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int Library::readBooks(string fileName)
{
    string bookInfo, concat;
    ifstream readBookFile;
    readBookFile.open(fileName);
    if(readBookFile.fail())
    {
        return -1;
    }
    else
    {
        while(getline(readBookFile, bookInfo))
        {
            //bookInfo = author,title,
            if(numBooks > 49)
            {
                return numBooks;
            }
            concat = bookInfo + ',';
            books[numBooks] = concat;
            concat = "";
            // cout << books[numBooks] << endl;
            numBooks++;
        }
    }
    readBookFile.close();
    return numBooks;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int Library::readRatings(string fileName)
{
    ifstream readUserFile;
    readUserFile.open(fileName);
    if(readUserFile.fail())
    {
        return -1;
    }
    else
    {
        //concat users|ratings| in this format
        string line, concat;
        int lineCounter = 1;
        while(getline(readUserFile, line))
        {
            if(numUsers > 99)
            {
                return numUsers;
            }
            concat += line + "|";
            if(lineCounter % 2 == 0)
            {
                users[numUsers] = concat;
                // cout << concat << endl;
                concat = "";
                numUsers++;
            }
            lineCounter++;
        }
        readUserFile.close();
    }
    // cout << "numUsers: " << numUsers << endl;
    // for(int i = 0; i < numUsers; i++)
    // {
    //     cout << "users[" << i << "] = " << users[i] << endl;
    // }
    return numUsers;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Library::viewRatings(string username_, int min_rating)
{
    //Checks for fully initialized library
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "The library has not been fully initialized." << endl;
    }
    else
    {
        //Iterates through user string
        string temperedUsername = insensitiveCase(username_);
        
        ////////////////////////////////////////////////////////////////////////////
        //Separate user and ratings
        // istringstream userRatingsLine;
        string data;
        bool usernameDNE = true;
        bool higherRating = false;
        int ratingLocation = 0;
        for(int x = 0; x < numUsers; x++)
        {
            string user = unzip("user", 1, users[x]);
            
            //cout << "temperedUsername[" << temperedUsername << "] == " << "user[" << user << "]" << endl;
            if(temperedUsername == user)
            {
                usernameDNE = false;
                User userFound;
                userFound.setUsername(user);
                
                //Separate string into int ratings
                istringstream strToint_ratings;
                string ratings = unzip("user", 2, users[x]);
                strToint_ratings.str(ratings);
                while(getline(strToint_ratings, data, ','))
                {
                    userFound.setRatingAt(ratingLocation, stoi(data));
                    ratingLocation++;
                    
                }
                // cout << user << endl << ratings << endl;
                bool useOnce = true;
                for(int i = 0; i < numBooks; i++)
                {
                    if(userFound.getRatingAt(i) >= min_rating)
                    {
                        if(useOnce)
                        {
                            cout << "Here are the books that " << username_ << " rated" << endl;
                            useOnce = false;
                        }
                        higherRating = true;
                        
                        //Separate author and title
                        string author = unzip("book", 1, books[i]);
                        string title = unzip("book", 2, books[i]);
                        
                        cout << "Title : " << title << endl;
                        cout << "Rating : " << userFound.getRatingAt(i) << endl;
                        cout << "-----" << endl;
                    }
                }
            }
        }
        //Checks if the username exists in the user array
        if(usernameDNE)
        {
            cout << username_ << " does not exist." << endl;
        }
        //Checks if a rating exist that is greater than or equal to the min rating
        if(!higherRating && !usernameDNE)
        {
            cout << username_ << " has not rated any books with " << min_rating << " or higher." << endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Library::printAllBooks() const
{
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "The library has not been fully initialized." << endl;
    }
    else
    {
        for(int i = 0; i < numBooks;i++)
        {
            int sum = 0;
            int ratingLocation = 0;
            double dividend, average;
            
            string author = unzip("book", 1, books[i]);
            string title = unzip("book", 2, books[i]);
            
            //Iterates through the users array
            for(int x = 0; x < numUsers; x++)
            {
                string data;
                string user = unzip("user", 1, users[x]);
                string ratings = unzip("user", 2, users[x]);
                
                User userRatings;
                //Separate string into int ratings
                istringstream strToint_ratings;
                strToint_ratings.str(ratings);
                
                //Turns str to int ratings, call users class and store int into ratings array
                while(getline(strToint_ratings, data, ','))
                {
                    userRatings.setRatingAt(ratingLocation, stoi(data));
                    ratingLocation++;
                }
                ratingLocation = 0;
                // cout << user;
                // cout << "| userRatings.getRatingAt(" << i << "): " << userRatings.getRatingAt(i) << endl;
                if(userRatings.getRatingAt(i) != 0)
                {
                    sum += userRatings.getRatingAt(i);
                    dividend++;
                }
            }
            // cout << "sum: " << sum << " dividend: " << dividend << endl;
            average = sum / dividend;
            sum = 0;
            dividend = 0;
            cout << "(" << fixed << setprecision(2) << average<< ") " << title << " by " << author << endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Library::addUser(string username_)
{
    if(numUsers > 99)
    {
        cout << "The library is already full. " << username_ << " was not added." << endl;
    }
    else
    {
        //turns all names to lowercase
        string temperedUsername = insensitiveCase(username_);
        bool newUserExists = true;
        for(int i = 0; i < numUsers; i++)
        {
            string user = unzip("user", 1, users[i]);
            if(temperedUsername == user)
            {
                cout << username_ << " already exists in the library." << endl;
                newUserExists = false;
            }
        }
        string concat = "";
        if(newUserExists)
        {
            cout << "Welcome to the library " << username_ << endl;
            concat += temperedUsername + "|";
            for(int i = 0; i < numBooks; i++)
            {
                if(i > 0)
                {
                    concat += ",";
                }
                concat += "0";
                
                if(i == numBooks - 1)
                {
                    concat += "|";
                }
            }
            users[numUsers] = concat;
            numUsers++;
        }
        // for(int i = 0; i < numUsers; i++)
        // {
        //     cout << users[i] << endl;
        // }
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Library::updateRating(string username_, string title_, int rating)
{
    //Checks for the library if fully initialized.
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "The library has not been fully initialized." << endl;
    }
    else
    {
        //Converts userinput into insensitive case
        string converted_username = insensitiveCase(username_);
        string converted_title = insensitiveCase(title_);
        // cout << converted_username << endl << converted_title << endl;
        
        //Checks for existing username
        string username;
        bool usernameDNE = true;
        int userLocation;
        for(int i = 0; i < numUsers; i++)
        {
            string username = unzip("user", 1, users[i]);
            if(converted_username == username)
            {
                usernameDNE = false;
                userLocation = i;
            }
        }
        if(usernameDNE)
        {
            cout << username_ << " does not exist." << endl;
        }
        else
        {
            //Checks for existing title
            bool titleDNE = true;
            int titleLocation;
            for(int i = 0; i < numUsers; i++)
            {
                string author = unzip("book", 1, books[i]);
                string title = unzip("book", 2, books[i]);
                
                string converted_title_Existing = insensitiveCase(title);
                if(converted_title == converted_title_Existing)
                {
                    //cout << "converted_title[" << converted_title << "] == " << "converted_title_Existing[" << converted_title_Existing << "]" << endl;
                    titleDNE = false;
                    titleLocation = i;
                }
            }
            
            if(titleDNE)
            {
                cout << title_ << " does not exist." << endl;
            }
            else
            {
                //Checks if rating is within bound 0-5
                if(!(0 <= rating && rating <= 5))
                {
                    cout << rating << " is not valid." << endl;
                }
                else
                {
                    //Insertion of rating
                    string data;
                    string user = unzip("user", 1, users[userLocation]);
                    string ratings = unzip("user", 2, users[userLocation]);
                    
                    User updated;
                    updated.setUsername(user);
                    istringstream updatedRating;
                    updatedRating.str(ratings);
                    
                    int tracker = 0;
                    while(getline(updatedRating, data, ','))
                    {
                        updated.setRatingAt(tracker, stoi(data));
                        tracker++;
                    }
                    updated.setRatingAt(titleLocation, rating);
                    
                    
                    //Zip
                    string concat;
                    int intToConvert;
                    string convertedInt;
                    for(int i = 0; i < numBooks; i++)
                    {
                        intToConvert = updated.getRatingAt(i);
                        stringstream intTostr;
                        intTostr << intToConvert;
                        intTostr >> convertedInt;
                        
                        if(i == 0)
                        {
                            concat += updated.getUsername() + '|';
                        }
                        if(i > 0)
                        {
                            concat += ',';
                        }
                        concat += convertedInt;
                        if(i == numBooks -1)
                        {
                            concat += '|';
                        }
                    }
                    users[userLocation] = concat;
                    // for(int i = 0; i < numBooks; i++)
                    // {
                    //     cout << "ratings[" << i << "] = " << updated.getRatingAt(i) << endl;
                    // }
                    cout << "The rating has been updated." << endl;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Library::getRecommendations(string username)
{
    string temperedUsername = insensitiveCase(username);
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "The library has not been fully initialized." << endl;
    }
    else
    {
        //mario = main User
        //luigi = compared user
        User mario;
        User luigi;
        User randomPerson;
        
        //Find mario
        string user, ratings, data;
        bool usernameDNE = true;
        for(int i = 0; i < numUsers; i++)
        {
            user = unzip("user", 1, users[i]);
            ratings = unzip("user", 2, users[i]);
            
            //Finding mario
            if(temperedUsername == user)
            {
                usernameDNE = false;
                int tracker = 0;
                mario.setUsername(user);
                istringstream strToint_ratings;
                strToint_ratings.str(ratings);
                while(getline(strToint_ratings, data, ','))
                {
                    mario.setRatingAt(tracker, stoi(data));
                    tracker++;
                }
                // cout << mario.getUsername() << endl;
                // for(int k = 0; k < numBooks; k++)
                // {
                //     cout << mario.getRatingAt(k) << endl;
                // }
            }
        }
        
        if(usernameDNE)
        {
            cout << username << " does not exist." << endl;
        }
        else
        {
            //Find randomPerson
            int randomPersonLocation;
            double minSSD = -1;
            for(int i = 0; i < numUsers; i++)
            {
                user = unzip("user", 1, users[i]);
                ratings = unzip("user", 2, users[i]);
                if(temperedUsername != user)
                {
                    string data;
                    int tracker = 0;
                    randomPerson.setUsername(user);
                    istringstream strToint_ratings;
                    strToint_ratings.str(ratings);
                    while(getline(strToint_ratings, data, ','))
                    {
                        randomPerson.setRatingAt(tracker, stoi(data));
                        tracker++;
                    }
                    
                    double SSD;
                    //Finding mario brother, luigi
                    for(int x = 0; x < numBooks; x++)
                    {
                        SSD += pow((mario.getRatingAt(x) - randomPerson.getRatingAt(x)), 2);
                    }
                    
                    // cout << randomPerson.getUsername() << ": SSD = " << SSD << endl;
                    //This for loop checks if there is any ratings, if all equal zero anyRatings remains false
                    bool anyRatings = false;
                    for(int y = 0; y < numBooks; y++)
                    {
                        if(randomPerson.getRatingAt(y) != 0)
                        {
                            anyRatings = true;
                        }
                    }
                    if((minSSD == -1 || SSD < minSSD) && anyRatings)
                    {
                        minSSD = SSD;
                        luigi.setUsername(randomPerson.getUsername());
                        for(int x = 0; x < numBooks; x++)
                        {
                            luigi.setRatingAt(x, randomPerson.getRatingAt(x));
                        }
                        // cout << luigi.getUsername() << " is the winner!" << endl;
                    }
                    SSD = 0;
                }
            }
            // cout << luigi.getUsername() << endl;
            // cout << "minSSD: " << minSSD << endl;
            // // for(int i = 0; i < numBooks; i++)
            // // {
            // //     cout << luigi.getRatingAt(i) << endl;
            // // }
            
            //Finding recommendations
            bool anyRecommendations = true;
            int numRecommended = 0;
            bool usedOnce = true;
            for(int i = 0; i < numBooks; i++)
            {
                if(mario.getRatingAt(i) == 0 && (luigi.getRatingAt(i) >= 3) && (numRecommended != 5))
                {
                    if(usedOnce)
                    {
                        cout << "Here is the list of recommendations" << endl;
                        usedOnce = false;
                    }
                    numRecommended++;
                    anyRecommendations = false;
                    string author = unzip("book", 1, books[i]);
                    string title = unzip("book", 2, books[i]);
                    
                    cout << title << " by " << author << endl;
                }
            }
            if(anyRecommendations)
            {
                cout << "There are no recommendations for " << username << " at present." << endl;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void Library::averageRating(string username)
{
    string temperedUsername = insensitiveCase(username);
    string user, ratings;
    bool userFound = false;
    
    for(int i = 0; i < numUsers; i++)
    {
        user = unzip("user", 1, users[i]);
        if(user == temperedUsername)
        {
            userFound = true;
            ratings = unzip("user", 2, users[i]);
        }
    }
    
    if(!userFound)
    {
        cout << username << " does not exist." << endl;
    }
    else
    {
        string data;
        int booksRead = 0;
        double sum, avg;
        bool noRatings = true;
        istringstream strToint_ratings;
        strToint_ratings.str(ratings);
        while(getline(strToint_ratings, data, ','))
        {
            if(stoi(data) != 0)
            {
                booksRead++;
                sum += stoi(data);
                noRatings = false;
            }
        }
        if(noRatings)
        {
            cout << username << " has not rated any books." << endl;
        }
        else
        {
            avg = sum / booksRead;
            cout << username << " average rating is " << fixed << setprecision(2) << avg << endl;
        }
    }
}
