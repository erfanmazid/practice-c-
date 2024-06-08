#include <iostream>

using namespace std;

int main()
{
    // get user birthday date
    int birthDay, birthMonth, birthYear;
    cout << "Enter your birth day: ";
    cin >> birthDay;
    cout << "Enter your birth month (as a number): ";
    cin >> birthMonth;
    cout << "Enter your birth year: ";
    cin >> birthYear;

    // today Date
    time_t today = time(nullptr);
    tm *t = localtime(&today);
    int currentDay = t->tm_mday;
    int currentMonth = t->tm_mon + 1;
    int currentYear = t->tm_year + 1900;

    // all years user live
    int fullYears = currentYear - birthYear;

    // all month user live
    int fullMonth;
    int month = 12;
    if (currentMonth >= birthMonth)
    {
        fullMonth = currentMonth - birthMonth;
    }
    else
    {
        fullMonth = (month - birthMonth) + currentMonth;
    }
    // all day user live
    int fullDay;
    int day = 30;
    if (currentDay >= birthDay)
    {
        fullDay = currentDay - birthDay;
    }
    else
    {
        fullDay = 30 - birthDay + currentDay;
    }

    // calculate all we need
    int allDayInLife = (fullYears * 365) + (fullMonth * 30) + fullDay;
    int allHourInLife = allDayInLife * 24;
    int allMinutesInLife = allHourInLife * 60;
    int allSecondsInLife = allMinutesInLife * 60;

    // printe all we need
    cout << "all days you live in world: " << allDayInLife << endl;
    cout << "all hours you live in world: " << allHourInLife << endl;
    cout << "all minutes you live in world: " << allMinutesInLife << endl;
    cout << "all Seconds you live in world: " << allSecondsInLife << endl;

    return 0;
}