#include <iostream>
using namespace std;

class DogProfile
{
    private:
        string name;
        string temperament;
        float bitingProbability;
    public:
        DogProfile();
        DogProfile(string name_, string temperament, float bitingProbability);

        void setName(string name_);
        string getName() const;

        void setTemperament(string temperament_);
        string getTemperament() const;

        void setBitingProbability(float bitingProbability);
        float getBitingProbability() const;

        string goodBoy();

};

DogProfile::DogProfile()
{
    name = "Fido";
    temperament = "always wags tail";
    bitingProbability = -100.0;
}

DogProfile::DogProfile(string name_, string temperament_, float bitingProbability_)
{
    name = name_;
    temperament = temperament_;
    bitingProbability = bitingProbability_;
}

void DogProfile::setName(string name_)
{
    name = name_;
}
string DogProfile::getName() const
{
    return name;
}
void DogProfile::setTemperament(string temperament_)
{
    temperament = temperament_;
}
string DogProfile::getTemperament() const
{
    return temperament;
}
void DogProfile::setBitingProbability(float bitingProbability_)
{
    bitingProbability = bitingProbability_;
}
float DogProfile::getBitingProbability() const
{
    return bitingProbability;
}
string DogProfile::goodBoy()
{
    string statement;
    if(bitingProbability <= 1000.0)
    {
        statement = "Good Boy";
    }
    else if (bitingProbability > 1000.0)
    {
        statement = "Bad Boy";
    }
    return statement;
}

int main()
{
    return 0;
}