/* CSCI 261 Lab 00: Name
 *
 * Author: Nathan Panzer
 *
 * Description
 */

#include <iostream>
#include <fstream>

using namespace std;

const string COUNTER_CONTROLLED_FILE = "counter_controlled.txt";
const string SENTINEL_CONTROLLED_FILE = "sentinel_controlled.txt";
const float TOLERANCE = 0.000006;

int main()
{
    cout << "Which file would you like to open?" << endl;
    cout << "1. Counter Controlled" << endl;
    cout << "2. Sentinel Controlled" << endl;
    int fileNum;
    cin >> fileNum;

    while ((fileNum != 1) && (fileNum != 2))
    {
        cout << "Invalid input. Please try again." << endl;
        cout << "1. Counter Controlled" << endl;
        cout << "2. Sentinel Controlled" << endl;
        cin >> fileNum;
    }

    if (fileNum == 1)
    {
        ifstream counterControlledFile(COUNTER_CONTROLLED_FILE);
        if (counterControlledFile.fail())
        {
            cout << "Error opening " << COUNTER_CONTROLLED_FILE << ". Exiting." << endl;
            return -1;
        }

        int numEntries;
        counterControlledFile >> numEntries;
        cout << "There are " << numEntries << " values in the file." << endl;
        cout << "The values in the file are:" << endl;

        double entry;
        double sum = 0;
        for (int i = 0; i < numEntries; i++)
        {
            counterControlledFile >> entry;
            cout << entry << endl;
            sum += entry;
        }

        double average = sum / numEntries;
        cout << "The average is " << average << "." << endl;
    }
    else if (fileNum == 2)
    {
        ifstream sentinelControlledFile(SENTINEL_CONTROLLED_FILE);
        if (sentinelControlledFile.fail())
        {
            cout << "Error opening " << SENTINEL_CONTROLLED_FILE << ". Exiting." << endl;
            return -1;
        }

        cout << "The values in the file are:" << endl;

        int numEntries = 0;
        double sum = 0;
        double entry;
        while (!sentinelControlledFile.eof())
        {
            sentinelControlledFile >> entry;

            if (entry - (-9999.) < TOLERANCE)
            {
                break;
            }

            cout << entry << endl;
            sum += entry;
            numEntries++;
        }

        cout << "There are " << numEntries << " values in the file." << endl;
        double average = sum / numEntries;
        cout << "The average is " << average << "." << endl;
    }

    return 0;
}