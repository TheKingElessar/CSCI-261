/* CSCI 261 Final Project: Scheduling App
 *
 * Author: Nathan Panzer
 *
 * Have you ever tried to organize a Dungeons and Dragons session with five other people?
 * Everybody has their own busy schedules, so it’s hard to find a time that works for everyone.
 * This program will ease those pains by taking everyone’s schedules (in the form of available
 * time blocks) and automatically finding time blocks that the most people are available for.
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
    vector<AvailableTimeBlock> allTimeBlocks;
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
            /*
             * Parse a line like: 12/08/21 08:00 10:30
             * into a vector of three strings.
             */
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

            /*
             * Allocate memory to store the necessary objects contained in
             * AvailableTimeBlock, because apparently if you don't do that
             * they're just deleted/overwritten. Ah, Rosie, I love this language!
             *
             * Ignore the cries of the damned below.
             */

            /*
             * WHY
             * WHY MUST YOU TORMENT ME SO
             * WHY CAN'T THIS BE EASY, LIKE IN JAVA
             * WHY WHAT DOES THIS MEAAAAAAAAAAAAAAAAAAAAAAAAAAN
             */
            auto *startEventTimePtr = new EventTime;
            EventTime startEventTime = EventTime(&newPerson, tStart, false);
            *startEventTimePtr = startEventTime;

            auto *endEventTimePtr = new EventTime;
            EventTime endEventTime = EventTime(&newPerson, tEnd, true);
            *endEventTimePtr = endEventTime;

            vector<Person *> blockOwners;
            blockOwners.push_back(&newPerson);

            auto *newTimeBlockPtr = new AvailableTimeBlock;
            AvailableTimeBlock newTimeBlock = AvailableTimeBlock(blockOwners, startEventTimePtr, endEventTimePtr);
            *newTimeBlockPtr = newTimeBlock;

            newPerson.addTimeBlock(newTimeBlockPtr);
            allTimeBlocks.push_back(newTimeBlock);
        }

        people.push_back(newPerson);
    }
    cout << endl;

    for (const Person& person : people)
    {
        cout << person.getName() << endl;
    }

    cout << "Blocks length: " << allTimeBlocks.size() << endl;
    vector<AvailableTimeBlock> validTimeBlocks;
    for (int i = 0; i < allTimeBlocks.size(); i++)
    {
        AvailableTimeBlock timeBlock = allTimeBlocks.at(i);
        cout << i << ": "<< timeBlock.getOwners().at(0)->getName() << endl;
        /*
         * Add all time blocks that overlap this time block.
         */
        vector<AvailableTimeBlock> overlapTimeBlocks;
        for (AvailableTimeBlock &otherTimeBlock : allTimeBlocks)
        {
            // Skip if it's the same
            if (timeBlock.getStartEvent().getID() == otherTimeBlock.getStartEvent().getID()) continue;

            if (timeBlock.doesOverlap(otherTimeBlock))
            {
                overlapTimeBlocks.push_back(otherTimeBlock);
            }
        }

        if (overlapTimeBlocks.empty())
        {
            continue;
        }

        /*
         * Check which people are represented in the overlapping time blocks.
         */
        vector<Person> overlapPeople;
        overlapPeople.push_back(*(timeBlock.getOwners().at(0)));
        for (const AvailableTimeBlock &overlapTimeBlock : overlapTimeBlocks)
        {
            bool flag = false;
            for (const Person &overlapPerson : overlapPeople)
            {
                if (overlapPerson.getName() == overlapTimeBlock.getOwners().at(0)->getName())
                {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            else
            {
                overlapPeople.push_back(*(overlapTimeBlock.getOwners().at(0)));
            }
        }

        cout << "Owner: " << timeBlock.getOwners().at(0)->getName() << endl;
        cout << "Overlapping time blocks: " << overlapTimeBlocks.size() << ". People represented: "
             << overlapPeople.size() << endl;

        // If not everyone is represented, move to the next time block.
        if (overlapPeople.size() != people.size())
        {
            continue;
        }

        vector<EventTime> timeline;
        for (const AvailableTimeBlock &overlapTimeBlock : overlapTimeBlocks)
        {
            timeline.push_back(overlapTimeBlock.getStartEvent());
            timeline.push_back(overlapTimeBlock.getEndEvent());
        }

        int earliestIndex = 0;
        time_t earliestTime = timeline.at(0).getTime();
        for (int i = 0; i < timeline.size(); i++)
        {
            for (int j = i; j < timeline.size(); j++)
            {
                if (timeline.at(j).getTime() < earliestTime)
                {
                    earliestIndex = j;
                    earliestTime = timeline.at(j).getTime();
                }
            }

            int origIndex = i;
            EventTime origTime = timeline.at(i);

            timeline.at(origIndex) = timeline.at(earliestIndex);
            timeline.at(earliestIndex) = origTime;
        }

        for (EventTime eventTime : timeline)
        {
            cout << eventTime.getTime() << endl;
        }
    }

    return 0;
}