/* CSCI 261 Lab 3C: Pretty Math Solver
 *
 * Author: Nathan Panzer
 *
 * making the math problems look pretty :)))))
 */

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int makeFile();

const string FILE_NAME = "mathWorksheet.txt";

int main()
{
    int fail = makeFile();
    if (fail == -1) return -1;

    ifstream inputFile(FILE_NAME);
    if (inputFile.fail())
    {
        cout << "Couldn't open " << FILE_NAME << "!";
        return -1;
    }

    double num1;
    inputFile >> num1;

    string mathOp;
    inputFile >> mathOp;

    double num2;
    inputFile >> num2;

    double answer;
    if (mathOp == "+")
    {
        answer = num1 + num2;
    }
    else if (mathOp == "-")
    {
        answer = num1 - num2;
    }
    else if (mathOp == "*")
    {
        answer = num1 * num2;
    }
    else if (mathOp == "/")
    {
        answer = num1 / num2;
    }
    else
    {
        cout << "Invalid operator: " << mathOp;
        return -1;
    }

    cout << right << setprecision(5) << setw(11) << num1 << endl;
    cout << left << setprecision(5) << setw(11) << mathOp << right << num2 << endl;
    cout << "=" << endl;
    cout << answer << endl;

//    cout << num1 << " " << mathOp << " " << num2 << " = " << answer << endl;

    return 0;
}

// From L-3A. Copied for testing convenience.
int makeFile()
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

    ofstream outputFile(FILE_NAME);
    if (outputFile.fail())
    {
        cout << "Error opening file " << FILE_NAME << "!" << endl;
        return -1;
    }

    outputFile << rand1 << " " << mathOpString << " " << rand2 << " = ?";
    outputFile.close();

    return 0;
}