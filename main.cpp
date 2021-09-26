/* CSCI 261 Lab 3C: Pretty Math Solver
 *
 * Author: Nathan Panzer
 *
 * making the math problems look pretty :)))))
 * and i did the extra credit fyi
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
//    int fail = makeFile();
//    if (fail == -1) return -1;

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

    cout << setw(11) << right << setprecision(5) << num1 << endl;
    cout << setw(1) << left << mathOp << setw(10) << right << setprecision(5) << num2 << left << endl;
    cout.fill('=');
    cout << setw(11) << "" << endl;
    cout.fill(' ');
    cout << right << setw(11) << fixed << setprecision(3) << answer << endl;

    ofstream outputFile("solved_problem.txt");
    if (outputFile.fail())
    {
        cout << "Error opening file " << "solved_problem.txt" << "!" << endl;
        return -1;
    }

    outputFile << setw(11) << right << setprecision(5) << num1 << endl;
    outputFile << setw(1) << left << mathOp << setw(10) << right << setprecision(5) << num2 << left << endl;
    outputFile.fill('=');
    outputFile << setw(11) << "" << endl;
    outputFile.fill(' ');
    outputFile << right << setw(11) << fixed << setprecision(3) << answer << endl;
    outputFile.close();

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