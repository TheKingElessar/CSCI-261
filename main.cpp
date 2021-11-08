/* CSCI 261 Lab 6C: Function Errors
 *
 * Author: Nathan Panzer
 *
 * To gain more practice with functions, as well as provide experience to read/fix someone else's code.
 *
Copyright 2021 Dr. Jeffrey Paone

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

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/// \desc adds five to the given parameter
/// \param x integer to be added to
/// \returns nothing
int addFive(int x)
{
    x += 5;
    return x;
}

/// \desc generates a single random number
/// \returns a random number
int generateRandomNumber()
{
    return rand() % 100;
}

/// \desc sums three integer values
/// \param x first value to be added
/// \param y second value to be added
/// \param z third value to be added
/// \returns the sum of all three parameters
int sum(int x, int y, int z)
{
    return x + y + z;
}

/// \desc sums three double values
/// \param x first value to be added
/// \param y second value to be added
/// \param z third value to be added
/// \returns the sum of all three parameters
double sum(double x, double y, double z)
{
    return x + y + z;
}

/// \desc multiplies two doubles together
/// \param a first value to multiply
/// \param b second value to multiply
/// \returns the product of the two double parameters
double multiply(double a, double b)
{
    return a * b;
}

/// \desc Recursive solution to move N disks from a starting peg to a destination peg
/// \desc Outputs the series of moves to solve the problem for N disks
/// \param N the number of disks to move
/// \param start ID of the peg the disks are currently on
/// \param target ID of the peg the disks need to move to
/// \param spare ID of the peg that can be used as temporary storage
/// \returns nothing
void towersOfHanoi(int N, int start, int target, int spare)
{
    // if there are no more disks to move, then we are done!
    if (N == 0)
    {
        return;
    }

    // Step 1: recursively move the top N-1 disks from our current peg
    // to the non-target peg
    towersOfHanoi(N - 1, start, spare, target);

    cout << "Move disk " << N << " from " << start << " to " << target << endl;

    // Step 2: move the largest disk that was on the bottom from our
    // current peg to the target peg
//    towersOfHanoi(1, start, target, spare);

    // Step 3: recursively move the remaining N-1 disks from the non-target
    // peg to our target peg on top of the largest disk we just moved
    towersOfHanoi(N - 1, spare, target, start);
}

void printSmileyFace()
{
    cout << "    |    |    " << endl;
    cout << "  \\         /" << endl;
    cout << "   --------- " << endl;
}

int main()
{
    cout << "Welcome to Function World" << endl;

    // SECTION I: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = addFive now returns the int result of the addition. The result is printed instead of numTrees.
    // TESTS: 3 --> 8, -1 --> 4

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    cout << "We planted five trees, there are now " << addFive(numTrees) << " trees." << endl;

    // SECTION II: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = implemented printSmileyFace() function
    // TESTS: nothing --> smiley face

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    printSmileyFace();

    // SECTION III: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = rand() is seeded once with nullptr, before the first generateRandomNumber() call
    // TESTS: nothing --> five random numbers between 0 and 100

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    cout << "Five different random numbers are: " << endl;
    srand(time(nullptr));
    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << generateRandomNumber() << endl;
    }


    // SECTION IV: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = num3 should be passed to sum(). sum() returns the sum of all three, not of num1 three times.
    // TESTS: 1,1,1 --> 3, 1,2,3 --> 6

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three integer numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum(num1, num2, num3) << endl;

    // SECTION V: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = value of field generateRandomNumber is changed to function call generateRandomNumber()
    // TESTS: nothing --> random number between 0 and 100

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "Another random number is " << generateRandomNumber() << endl;

    // SECTION VI: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = define the multiply function instead of just declaring it
    // TESTS: 1.5,2.5 --> 3.75, 1.0,1.0 --> 1.0

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VI" << endl;
    cout << "******************" << endl;

    double doub1, doub2;
    cout << "Enter two doubles: ";
    cin >> doub1 >> doub2;
    cout << "Their product is: " << multiply(doub1, doub2) << endl;

    // SECTION VII: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = sum() returns sum of all three instead of sum of doub2 three times. sum() returns double instead of int
    // TESTS: 1.0,1.0,1.0 --> 3.0, 1.5,0,0 --> 1.5

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VII" << endl;
    cout << "******************" << endl;

    double doub3;
    cout << "Enter three double numbers: ";
    cin >> doub1 >> doub2 >> doub3;
    cout << "The sum of all three is " << sum(doub1, doub2, doub3) << endl;

    // SECTION VIII: update comment below on how you fixed this section's code, and tests run
    // that show function is working properly
    // FIX = only returns when there are 0 disks left, added parameters
    // TESTS: 3 --> proper sequence

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VIII" << endl;
    cout << "******************" << endl;

    const int STARTING_PEG = 0;         // 0 - ID of the peg our disks start on
    const int TARGET_PEG = 2;           // 2 - ID of the peg we need to move our disks to
    const int SPARE_PEG = 1;            // 1 - ID of the peg that can be used for temp storage

    int numberOfDisks;
    cout << "Enter number of disks to solve: ";
    cin >> numberOfDisks;               // user enters the number of disks to solve for

    // solve Towers of Hanoi problem for numberOfDisks disks
    // disks are initially on our starting peg and need to move to our target peg
    towersOfHanoi(numberOfDisks, STARTING_PEG, TARGET_PEG, SPARE_PEG);

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}