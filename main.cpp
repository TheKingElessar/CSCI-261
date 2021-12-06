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

//    cout << "Enter one name per line, corresponding to the correct files.\nWhen finished, press enter." << endl;
//    while (true)
//    {
//        string input;
//        getline(cin, input);
//        while (cin.fail())
//        {
//            cin.clear();
//            char errInput = cin.get();
//            while (errInput != '\n')
//            {
//                errInput = cin.get();
//            }
//            getline(cin, input);
//        }
//
//        if (input.empty())
//        {
//            break;
//        }
//
//        personStrings.push_back(input);
//    }

    personStrings.push_back("Nathan Panzer");
    personStrings.push_back("Mr. Potato Head");

    cout << "Entered names: " << endl;
    for (const string &name : personStrings)
    {
        cout << " - " << name << endl;
    }
    cout << endl;

    vector<Person *> people;
    vector<AvailableTimeBlock> allTimeBlocks;
    for (const string &name : personStrings)
    {
        vector<AvailableTimeBlock *> personTimeBlocks;

        // Todo: inline pointer constructor
        auto *newPersonPtr = new Person;
        Person newPerson(name, personTimeBlocks);
        *newPersonPtr = newPerson;

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
            EventTime startEventTime = EventTime(newPersonPtr, tStart, false);
            *startEventTimePtr = startEventTime;

            auto *endEventTimePtr = new EventTime;
            EventTime endEventTime = EventTime(newPersonPtr, tEnd, true);
            *endEventTimePtr = endEventTime;

            vector<Person *> blockOwners;
            blockOwners.push_back(newPersonPtr);

            auto *newTimeBlockPtr = new AvailableTimeBlock;
            AvailableTimeBlock newTimeBlock = AvailableTimeBlock(blockOwners, startEventTimePtr, endEventTimePtr);
            *newTimeBlockPtr = newTimeBlock;

            newPerson.addTimeBlock(newTimeBlockPtr);
            allTimeBlocks.push_back(newTimeBlock);
        }

        people.push_back(newPersonPtr);
    }
    cout << endl;

    vector<AvailableTimeBlock *> validTimeBlocks;
    for (int i = 0; i < allTimeBlocks.size(); i++)
    {
        AvailableTimeBlock timeBlock = allTimeBlocks.at(i);

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
                auto startTime = timeBlock.getStartEvent().getTime();
                auto endTime = timeBlock.getEndEvent().getTime();

                cout << "Overlapping blocks: " << timeBlock.getStartEvent().getID() << " " << ctime(&startTime)
                     << " and " << otherTimeBlock.getStartEvent().getID() << " " << ctime(&endTime) << endl;
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

        for (int p = 0; p < timeline.size() - 1; p++)
        {
            int earliestIndex = p;
            time_t earliestTime = timeline.at(p).getTime();
            for (int j = p + 1; j < timeline.size(); j++)
            {
                if (timeline.at(j).getTime() < earliestTime)
                {
                    earliestIndex = j;
                    earliestTime = timeline.at(earliestIndex).getTime();
                }
            }

            if (earliestIndex == p) continue;

            int origIndex = p;
            EventTime origTime = timeline.at(p);

            timeline.at(origIndex) = timeline.at(earliestIndex);
            timeline.at(earliestIndex) = origTime;
        }

        vector<Person> addedPeople;
        auto *allStart = new EventTime;
        vector<EventTime> passedEventTimes;
        for (EventTime &eventTime : timeline)
        {
            if (eventTime.getIsEnding())
            {
                bool hasEveryone = true;
                for (Person *person : people)
                {
                    bool inFlag = false;
                    for (const Person &otherPerson : addedPeople)
                    {
                        if (person->getName() == otherPerson.getName())
                        {
                            inFlag = true;
                            break;
                        }
                    }
                    if (inFlag) continue;
                    else
                    {
                        hasEveryone = false;
                        break;
                    }
                }

                if (hasEveryone)
                {
                    auto *validBlock = new AvailableTimeBlock;
                    auto *allEnd = new EventTime;
                    *allEnd = eventTime;
                    *validBlock = AvailableTimeBlock(people, allStart, allEnd);
                    validTimeBlocks.push_back(validBlock);
                }
            }

            const Person &person = eventTime.getOwner();
            addedPeople.push_back(person);

            // Todo: repeated code. Comparing two vectors
            bool hasEveryone = true;
            for (Person *person1 : people)
            {
                bool inFlag = false;
                for (const Person &otherPerson : addedPeople)
                {
                    if (person1->getName() == otherPerson.getName())
                    {
                        inFlag = true;
                        break;
                    }
                }
                if (inFlag) continue;
                else
                {
                    hasEveryone = false;
                    break;
                }
            }

            if (hasEveryone)
            {
                allStart = &eventTime;
            }
        }
    }

    for (AvailableTimeBlock *availableTimeBlock : validTimeBlocks)
    {
        auto startTime = availableTimeBlock->getStartEvent().getTime();
        auto endTime = availableTimeBlock->getEndEvent().getTime();

        cout << "Valid block: " << ctime(&startTime) << " to " << ctime(&endTime) << endl;
    }

    return 0;
}