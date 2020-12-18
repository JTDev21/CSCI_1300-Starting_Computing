#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Stats
{
    private:
        vector <string> data;

    public:
        Stats();
        void ReadFile(string fileName_);
        float getAvgStringLength();
        string getLongestString(); 
};

Stats::Stats()
{
    //Nothing needed for initalization
}
void Stats::ReadFile(string fileName_)
{
    ifstream myFile;
    myFile.open(fileName_);
    string line;
    while(getline(myFile, line))
    {
        data.push_back(line);
    }
    myFile.close();
}
float Stats::getAvgStringLength()
{
    float sum = 0;
    float Ave;
    for(int i = 0; i < data.size(); i++)
    {
        sum += data[i].length();
    }
    Ave = sum / data.size();
    return Ave;
}
string Stats::getLongestString()
{
    int loongestString_loc;
    int longestString_Size = 0;
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i].length() >= longestString_Size)
        {
            loongestString_loc = i;
            longestString_Size = data[i].length();
        }
    }
    return data[loongestString_loc];
}