#include <string>
#include <iomanip>
#include "Util.h"
#include "AvailableTimeBlock.h"
#include <iostream>
#include <ctime>
#include "Person.h"
#include "EventTime.h"

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

void printTimeBlocks(const vector<Person> &people)
{
    for (const Person &person : people)
    {
        cout << person.getName() << " has " << person.getTimeBlocks().size() << " time blocks." << endl;
        for (AvailableTimeBlock *timeBlock : person.getTimeBlocks())
        {
            time_t time1 = timeBlock->getStartEvent().getTime();
            time_t time2 = timeBlock->getEndEvent().getTime();


            cout << "Starts at " << replaceChar(ctime(&time1), '\n', "") << ". Ends at "
                 << replaceChar(ctime(&time2), '\n', "") << "." << endl;
        }
    }
}