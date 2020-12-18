#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Probability
{
    private:
        float prob_values[50];
        string event[50];
    public:
        Probability();
        void ReadFile(string fileName_);
        string getMostLikelyEvent();
        string getMostLikelyEvent(float threshold_);
};

Probability::Probability()
{
    for(int i = 0; i < 50; i++)
    {
        prob_values[i] = 0.0;
        event[i] = "";
    }
}

void Probability::ReadFile(string fileName_)
{
    string splitData[2];
    int max = 2;
    int counter = 0;
    string line;
    ifstream myFile;
    myFile.open(fileName_);
    while(getline(myFile, line))
    {
        split(line, ',', splitData, max);
        event[counter] = splitData[0];
        prob_values[counter] = stod(splitData[1]);
        counter++;
    }
    myFile.close();
}

string Probability::getMostLikelyEvent(float threshold)
{
    string statement;
    bool breakTie = true;
    int mostLikelyEvent;
    for(int i = 0; (i < 50) && breakTie; i++)
    {
        if(threshold <= prob_values[i])
        {
            breakTie = false;
            mostLikelyEvent = i;
        }
    }
    if(!breakTie)
    {
        statement = event[mostLikelyEvent];
    }
    else
    {
        statement = "";
    }
    return statement;
}

// Rainfall,0.1
// Sunny,0.8
// Cloudy,0.67
// Thunderstorm,0.2
// Hurricane,0.01