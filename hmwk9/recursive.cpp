#include <iostream>
#include <sstream>
using namespace std;

string decimalToBinaryRecursive(int dividend)
{
    const int divisor = 2;
    int binary_int;
    
    if(dividend != 0)
    {
        binary_int = (dividend % divisor) + (10 * stoi(decimalToBinaryRecursive(dividend / divisor)));
    }
    else
    {
        binary_int = 0;
    }
    // int remainder = dividend % divisor;
    // int expo = 10 * decimalToBinaryRecursive(dividend / divisor);
    // cout << decimalToBinaryRecursive(dividend / divisor) << endl;
    // cout << remainder << " + " << expo << " = " << remainder + expo << endl;
    // cout << decimalToBinaryRecursive(dividend / divisor) << "|" << endl;
    return to_string(binary_int);
}

int main()
{
    int dividend;
    
    cout << "Number to convert into a decimal: " << endl;
    cin >> dividend;
    string student = decimalToBinaryRecursive(dividend);
    cout << student << endl;
    return 0;
}