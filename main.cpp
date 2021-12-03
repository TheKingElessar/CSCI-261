/* CSCI 261 Final Project: Scheduling App
 *
 * Author: Nathan Panzer
 *
 * Have you ever tried to organize a Dungeons and Dragons session with five other people?
 * Everybody has their own busy schedules, so it’s hard to find a _time that works for everyone.
 * This program will ease those pains by taking everyone’s schedules (in the form of available
 * _time blocks) and automatically finding _time blocks that the most people are available for.
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "EventTime.h"
#include "Person.h"
#include "AvailableTimeBlock.h"

using namespace std;

int main()
{
    vector<string> personStrings;

    cout << "Enter one name per line, corresponding to the correct files.\nWhen finished, press enter." << endl;
    while (true)
    {
        string input;
        getline(cin, input);
        while (cin.fail())
        {
            cin.clear();
            char errInput = cin.get();
            while (errInput != '\n')
            {
                errInput = cin.get();
            }
            getline(cin, input);
        }

        if (input.empty())
        {
            break;
        }

        personStrings.push_back(input);
    }

    cout << "Entered names: " << endl;
    for (const string &name : personStrings)
    {
        cout << " - " << name << endl;
    }

    vector<Person> people;
    for (const string &name : personStrings)
    {
        vector<AvailableTimeBlock *> personTimeBlocks;
        Person newPerson(name, personTimeBlocks);

        string filePath = "people/" + name + ".txt";
        ifstream nameFile(filePath);
        if (nameFile.fail())
        {
            cout << "File " << filePath << " could not be opened. Skipping." << endl;
            return -1;
        }

        string discardName;
        getline(nameFile, discardName);

        string readLine;
        while (getline(nameFile, readLine))
        {
            vector<string> splitLine;
            while (readLine.find(' ') != string::npos)
            {
                int foundIndex = readLine.find(' ');
                string substring = readLine.substr(0, foundIndex);
                splitLine.push_back(substring);
                readLine.replace(0, foundIndex + 1, "");
            }
            splitLine.push_back(readLine);


            /*
             * Parsing times from https://stackoverflow.com/questions/48800745/how-to-convert-date-string-to-time-t
             */
//            std::istringstream time1(splitLine.at(0) + " " + splitLine.at(1));
            struct tm ttttt;
            std::istringstream time1("12/08/21 08:00");
            time1 >> std::get_time(&ttttt, "%m/%d/%y %H:%M");
            time_t startTime = mktime(&ttttt);
            cout << "Start time: " << startTime << endl;

            std::istringstream time2(splitLine.at(0) + " " + splitLine.at(2));
            time2 >> std::get_time(&ttttt, "%m/%d/%y %H:%M");
            time_t endTime = mktime(&ttttt);

            EventTime startEventTime(&newPerson, startTime, false);
            EventTime endEventTime(&newPerson, endTime, true);

            vector<Person *> blockOwners;
            blockOwners.push_back(&newPerson);
            AvailableTimeBlock newTimeBlock(blockOwners, &startEventTime, &endEventTime);

            newPerson.addTimeBlock(&newTimeBlock);
        }

        people.push_back(newPerson);
    }

    for (const Person &person : people)
    {

        cout << person.getName() << " has " << person.getTimeBlocks().size() << " time blocks." << endl;
        for (AvailableTimeBlock *timeBlock : person.getTimeBlocks())
        {
            time_t time1 = timeBlock->getStartEvent().getTime();
            time_t time2 = timeBlock->getEndEvent().getTime();

            cout << "Starts at " << ctime(&time1) << ". Ends at " << ctime(&time2) << "." << endl;
        }
    }

    return 0;
}