#include <iostream>

using namespace std;
class Coffee
{
    private:
        string roastType;
        float temp;

    public:
        Coffee();
        Coffee(string roastType_, float temp_);

        void setRoastType(string roastType_);
        string getRoastType() const;

        void setTemp(float temp_);
        int getTemp() const;

        string drinkability() const;
};

Coffee::Coffee()
{
    temp = 180;
}

Coffee::Coffee(string roastType_, float temp_)
{
    roastType = roastType;
    temp = temp;
}

void Coffee::setRoastType(string roastType_)
{
    roastType = roastType;
}

string Coffee::getRoastType() const
{
    return roastType;
}

void Coffee::setTemp(float temp_)
{
    temp = temp;
}

int Coffee::getTemp() const
{
    return temp;
}

string Coffee::drinkability() const
{
    string statement;
    if(temp < 100.0)
    {
        statement = "Too Cold";
    }
    else if(100.0 <= temp && temp < 160.0)
    {
        statement = "Just Right";
    }
    else if(temp >= 160.0)
    {
        statement = "Hot";
    }
    else if(temp >= 180.0)
    {
        statement = "Too Hot";
    }
    return statement;
}

int main()
{
    Coffee brew("Light", 160.0);
}