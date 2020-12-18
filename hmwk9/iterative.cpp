#include <iostream>
#include <sstream>
using namespace std;

string decimalToBinaryIterative(int dividend)
{
    const int divisor = 2;
    int expo = 1;
    int remainder;
    int binary = 0;
    string binary_str;
    
    while(dividend != 0)
    {
        remainder = dividend % divisor;
        dividend = dividend / divisor;

        binary += remainder * expo;
        expo = expo * 10;
    }
    stringstream intTostr;
    intTostr << binary;
    intTostr >> binary_str;
    return binary_str;
}

int main()
{
    int dividend;
    
    cout << "Number to convert into a decimal: " << endl;
    cin >> dividend;
    cout << decimalToBinaryIterative(dividend) << endl;
    return 0;
}