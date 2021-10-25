/* CSCI 261 Lab 6A: Yahtzee!
 *
 * Author: Nathan Panzer
 *
 * For this lab, we are going to collectively implement most of a Yahtzee game.
 */

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int *sortDiceArray(int dieRolled[]);

bool isSmallStraight(int die1, int die2, int die3, int die4, int die5);

int main()
{
    int dieRolled[5];
    srand(time(nullptr));
    rand();

    for (int i = 0; i < 5; i++)
    {
        dieRolled[i] = rand() % 6 + 1;
    }

    bool isRollFours = isSmallStraight(dieRolled[0], dieRolled[1], dieRolled[2], dieRolled[3], dieRolled[4]);

    return 0;
}

bool isFours(int die1, int die2, int die3, int die4, int die5)
{
    /*
    int dieRolled[5] = {die1, die2, die3, die4, die5};
    int fourCount = 0;
    for (int i = 0; i < 5; i++)
    {
        if (dieRolled[i] == 4)
        {
            fourCount++;
        }
    }
    return fourCount > 0;
    */

    return true;
}

int *sortDiceArray(int dieRolled[5])
{
    int arrayCopy[5];
    for (int i = 0; i < 5; i++)
    {
        arrayCopy[i] = dieRolled[i];
    }

    for (int j = 0; j < 5; j++)
    {
        int smallestIndex = j;
        int smallestValue = arrayCopy[smallestIndex];
        for (int i = j; i < 5; i++)
        {
            if (arrayCopy[i] < smallestValue)
            {
                smallestIndex = i;
                smallestValue = arrayCopy[i];
            }
        }

        int original = arrayCopy[j];
        arrayCopy[j] = smallestValue;
        arrayCopy[smallestIndex] = original;
    }

    return arrayCopy;
}

int scoreFours(int die1, int die2, int die3, int die4, int die5)
{
}

bool isSmallStraight(int die1, int die2, int die3, int die4, int die5)
{
    int dieRolled[5] = {die1, die2, die3, die4, die5};
    int *sortedRolls = sortDiceArray(dieRolled);
}

int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5)
{
}