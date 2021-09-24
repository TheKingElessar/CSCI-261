/* CSCI 261 Lab 3A: Math Worksheet Generator
 *
 * Author: Nathan Panzer
 *
 * The focus of this lab is on one concept: how to write data to an "output file stream" or ofstream object.
 */
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    srand(time(nullptr));
    rand();

    double rand1 = (rand() / (double) RAND_MAX) * 200 - 100;
    double rand2 = (rand() / (double) RAND_MAX) * 200 - 100;

    int mathOp = rand() % 4;

    string mathOpString;

    switch (mathOp)
    {
        case 0:
            mathOpString = "+";
            break;
        case 1:
            mathOpString = "-";
            break;
        case 2:
            mathOpString = "*";
            break;
        case 3:
            mathOpString = "/";
            break;
        default:
            cout << "bruh" << endl;
            return -1;
    }

    ofstream outputFile("mathWorksheet.txt");
    if (outputFile.fail())
    {
        cout << "Error opening file mathWorksheet.txt!" << endl;
        return -1;
    }

    outputFile << rand1 << " " << mathOpString << " " << rand2 << " = ?";
    outputFile.close();

    return 0;
}