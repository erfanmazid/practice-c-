#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number1 = 0;
    int number2 = 0;
    int sum = 0;

    cout << "Hi, Enter your first number: ";
    cin >> number1;

    cout << "Enter your second number: ";
    cin >> number2;

    sum = number1 + number2;

    cout << "Resault is: " << sum;

    return 0;
}