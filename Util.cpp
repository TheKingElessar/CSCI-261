#include <string>
#include <iomanip>
#include "Util.h"
#include <iostream>
#include <ctime>

time_t stringToTime(const string &timeString, const string &formatting)
{
    struct tm tm{};
    stringstream ss(timeString);
    string test;
    ss >> get_time(&tm, "%m/%d/%y %H:%M");
    tm.tm_isdst = -1;
    tm.tm_year += 100;

    time_t timet = mktime(&tm);

    return timet;
}

time_t stringToTime(const string &timeString)
{
    time_t timet = stringToTime(timeString, "%m/%d/%y %H:%M");
    return timet;
}

string replaceChar(string inputString, const char &origChar, const string &replaceChar)
{
    int count = 0;
    while (inputString.find(origChar) != string::npos)
    {
        int foundIndex = inputString.find(origChar);
        inputString.replace(foundIndex, 1, replaceChar);
        count++;
    }

    return inputString;
}