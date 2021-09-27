/* CSCI 261 Lab 4B: Loop Errors
 *
 * Author: Nathan Panzer
 *
 * Your task for this lab is to fix a program that has several loops and several errors.
 */

/*
Copyright 2019 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = The inputted number should be included in the sum, so line 63 was changed from < to <=.
//       I also initialized sum because adding to it when it's uninitialized is undefined behavior.
//       Also now it keeps you from entering negative numbers, which results in the wrong answer.
// TESTS: 2 --> 3. 4 --> 10. 5 --> 15.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum = 0;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> numIter;

    while (numIter < 0)
    {
        cout << "The entered number is less than 0. Choose another number: ";
        cin >> numIter;
    }

    for (i = 1; i <= numIter; ++i)
    {
        sum += i;
    }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Line 99 was moved out of the while loop since it was resetting the total on every iteration.
//       It's now initialized when it's declared on line 89.
// TESTS: 3 items (1, 2, 3) --> 6. 1 item (8) --> 8. 5 items (1, 1, 1, 1, 1) --> 5.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total = 0;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    while (counter <= numItems)
    {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        cout << endl;
        total += price;
        counter++;
    }
    cout << "The total price is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = counter2 is now incremented every loop iteration. Instead of testing if counter2 is greater than sum2,
//       it now tests if counter2 is greater than numIter2 (which I think is what the program is intended to do).
//       Also it keeps the user from entering a negative input, which results in the wrong answer.
// TESTS: 5 --> 15. 7 --> 28. 2 --> 3.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    int sum2 = 0;
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum to?" << endl;
    cin >> numIter2;

    while (numIter2 < 0)
    {
        cout << "The entered number is less than 0. Choose another number: ";
        cin >> numIter2;
    }

    do
    {
        sum2 += counter2;
        counter2++;
        cout << "Sum so far: " << sum2 << endl;
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = The order of the for loop statements on line 162 was wrong. Now i3 initializes to 0,
//       and it goes until it's greater* than numIter3, not the other way around.
//       *Also that means it's now inclusive.
//       Also it doesn't accept negative numbers because that gives the wrong output.
// TESTS: 4 --> 30. 8 --> 204.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of squares from 1 to ? (inclusive)" << endl;

    int numIter3;
    cin >> numIter3;

    while (numIter2 < 0)
    {
        cout << "The entered number is less than 0. Choose another number: ";
        cin >> numIter3;
    }

    int sum3 = 0;
    for (int i3 = 0; i3 <= numIter3; i3++)
    {
        sum3 += i3 * i3;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = counter4 now increments after every iteration, fixing the infinite loop.
//       The loop goes until counter4 is greater than numIter4, not equal to 10.
//       AND IT DOESN'T ACCEPT NEGATIVE INPUTS BECAUSE THAT OUTPUTS THE WRONG ANSWER.
// TESTS: 4 --> 100. 7 --> 784.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of cubes from 1 to ? (inclusive)" << endl;

    int numIter4;
    cin >> numIter4;

    while (numIter2 < 0)
    {
        cout << "The entered number is less than 0. Choose another number: ";
        cin >> numIter4;
    }

    int sum4 = 0;
    int counter4 = 1;

    while (counter4 <= numIter4)
    {
        sum4 += (counter4 * counter4 * counter4);
        counter4++;
    }

    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}