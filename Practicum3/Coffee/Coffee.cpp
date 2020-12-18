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
    roastType = roastType_;
    temp = temp_;
}

void Coffee::setRoastType(string roastType_)
{
    roastType = roastType_;
}

string Coffee::getRoastType() const
{
    return roastType;
}

void Coffee::setTemp(float temp_)
{
    temp = temp_;
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
    else if(160.0 <= temp && temp < 180)
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
    Coffee account("Light", 160.0);

    account.setTemp(190.0);
    if (account.drinkability() != "Too Hot")
        cout<<"Incorrect drinkability for too hot" << endl;

        cout << "Roast Type: " << account.getRoastType() << endl;
        cout << "Temperature: " << account.getTemp() << endl;
        cout << "Drinkability: " << account.drinkability() << endl;
}