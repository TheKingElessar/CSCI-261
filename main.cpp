/* CSCI 261 Lab 5A: Array Input/Output
 *
 * Author: Nathan Panzer
 *
 * The goal of this assignment is to gain practice with arrays: how to declare (and initialize) arrays, how to access array values, and how to store values in arrays.
 */

#include <iostream>

using namespace std;

int main()
{
    cout << "Hey! Witness my first array mojo!\n"
            "Enter 15 numbers and I will tell you what they are." << endl;

    int intArray[15];
    int input;
    for (int i = 1; i <= 15; i++)
    {
        cout << "Number " << i << ": ";
        cin >> input;
        while (cin.fail())
        {
            cin.clear();
            char errInput = cin.get();
            while (errInput != '\n')
            {
                errInput = cin.get();
            }
            cout << "Invalid. Number " << i << ": ";
            cin >> input;
        }

        intArray[i - 1] = input;
    }

    cout << "So awesome!" << endl;
    cout << "The numbers are: ";

    for (int i = 0; i < 15; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl << "Have a nice day!" << endl;

    return 0;
}