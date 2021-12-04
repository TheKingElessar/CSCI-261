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
#include "EventTime.h"
#include "Person.h"
#include "AvailableTimeBlock.h"
#include "Util.h"
#include <ctime>

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
    cout << endl;

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
            string startTimeString = splitLine.at(0) + " " + splitLine.at(1);
            time_t tStart = stringToTime(startTimeString);

            string endTimeString = splitLine.at(0) + " " + splitLine.at(2);
            time_t tEnd = stringToTime(endTimeString);

            EventTime startEventTime(&newPerson, tStart, false);
            EventTime endEventTime(&newPerson, tEnd, true);

            vector<Person *> blockOwners;
            blockOwners.push_back(&newPerson);
            AvailableTimeBlock newTimeBlock(blockOwners, &startEventTime, &endEventTime);
            time_t time1 = startEventTime.getTime();
            time_t time2 = endEventTime.getTime();
            cout << "Starts at " << replaceChar(ctime(&time1), '\n', "") << ". Ends at "
                 << replaceChar(ctime(&time2), '\n', "") << "." << endl;

            newPerson.addTimeBlock(&newTimeBlock);
        }

        people.push_back(newPerson);
    }
    cout << endl;

    for (const Person &person : people)
    {

        cout << person.getName() << " has " << person.getTimeBlocks().size() << " time blocks." << endl;
        for (AvailableTimeBlock *timeBlock : person.getTimeBlocks())
        {
            time_t time1 = timeBlock->getStartEvent().getTime();
            time_t time2 = timeBlock->getEndEvent().getTime();

            // todo: this always uses the last time block. are the others deleted??

            cout << "Starts at " << replaceChar(ctime(&time1), '\n', "") << ". Ends at "
                 << replaceChar(ctime(&time2), '\n', "") << "." << endl;
        }
    }

    return 0;
}