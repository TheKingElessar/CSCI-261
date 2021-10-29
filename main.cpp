/* CSCI 261 Lab 6A: Yahtzee!
 *
 * Author: Nathan Panzer
 *
 * For this lab, we are going to collectively implement most of a Yahtzee game.
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void sortDiceArray(const int dieRolled[], int targetArray[]);

vector<int> removeDuplicates(int targetArray[5]);

bool isSmallStraight(int die1, int die2, int die3, int die4, int die5);

bool isFours(int die1, int die2, int die3, int die4, int die5);

int scoreFours(int die1, int die2, int die3, int die4, int die5);

int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5);

const int SMALL_STRAIGHT_SCORE = 30;

int main()
{
    int dieRolled[5];
    srand(time(nullptr));
    rand();

    for (int i = 0; i < 5; i++)
    {
        dieRolled[i] = rand() % 6 + 1;
        cout << dieRolled[i] << endl;
    }

    bool rollIsSmallStraight = isSmallStraight(dieRolled[0], dieRolled[1], dieRolled[2], dieRolled[3], dieRolled[4]);
    cout << "Roll is small straight: " << rollIsSmallStraight << endl;
    cout << "Score: " << scoreSmallStraight(dieRolled[0], dieRolled[1], dieRolled[2], dieRolled[3], dieRolled[4]) << endl;
    bool rollIsFours = isFours(dieRolled[0], dieRolled[1], dieRolled[2], dieRolled[3], dieRolled[4]);
    cout << "Roll is fours: " << rollIsFours << endl;
    cout << "Score: " << scoreFours(dieRolled[0], dieRolled[1], dieRolled[2], dieRolled[3], dieRolled[4]) << endl;
    return 0;
}

/*
 * Determine if scoring as fours will award points
 */
bool isFours(int die1, int die2, int die3, int die4, int die5)
{
    int dieRolled[5] = {die1, die2, die3, die4, die5};
    int fourCount = 0;
    for (int i : dieRolled)
    {
        if (i == 4)
        {
            fourCount++;
        }
    }
    return fourCount > 0;
}

/*
 * Returns score of fours
 */
int scoreFours(int die1, int die2, int die3, int die4, int die5)
{
    int dieRolled[5] = {die1, die2, die3, die4, die5};
    int fourCount = 0;
    for (int i : dieRolled)
    {
        if (i == 4)
        {
            fourCount++;
        }
    }
    return fourCount * 4;
}

/*
 * Removes duplicates from a sorted array of numbers > -1
 */
vector<int> removeDuplicates(int targetArray[5])
{
    for (int i = 0; i < 4; i++)
    {
        if (targetArray[i] == targetArray[i + 1])
        {
            targetArray[i] = -1;
        }
    }
    vector<int> removedDuplicates;
    for (int i = 0; i < 5; i++)
    {
        if (targetArray[i] != -1)
        {
            removedDuplicates.push_back(targetArray[i]);
        }
    }

    return removedDuplicates;
}

/*
 * Sorts an array of 5 numbers
 */
void sortDiceArray(const int dieRolled[5], int targetArray[5])
{
    for (int i = 0; i < 5; i++)
    {
        targetArray[i] = dieRolled[i];
    }

    for (int j = 0; j < 5; j++)
    {
        int smallestIndex = j;
        int smallestValue = targetArray[smallestIndex];
        for (int i = j; i < 5; i++)
        {
            if (targetArray[i] < smallestValue)
            {
                smallestIndex = i;
                smallestValue = targetArray[i];
            }
        }

        int original = targetArray[j];
        targetArray[j] = smallestValue;
        targetArray[smallestIndex] = original;
    }
}

/*
 * Determine if scoring as small straight will award points
 */
bool isSmallStraight(int die1, int die2, int die3, int die4, int die5)
{
    int dieRolled[5] = {die1, die2, die3, die4, die5};
    int sortedRolls[5];
    sortDiceArray(dieRolled, sortedRolls);
    vector<int> deDuped = removeDuplicates(sortedRolls);

    if (deDuped.size() < 4)
    {
        return false;
    }

    bool firstInvalid = false;
    bool lastInvalid = false;
    bool gap = false;
    for (int i = 0; i < deDuped.size(); i++)
    {
        if (i == 0)
        {
            if (deDuped.at(i) != deDuped.at(i + 1) - 1)
            {
                firstInvalid = true;
            }
        }
        else if (i != deDuped.size() - 1)
        {
            if (i == deDuped.size() - 2 && lastInvalid) continue;

            if (deDuped.at(i) != deDuped.at(i + 1) - 1)
            {
                gap = true;
                break;
            }
        }


        if (i == deDuped.size() - 1)
        {
            if (deDuped.at(i) != deDuped.at(i - 1) + 1)
            {
                lastInvalid = true;
            }
        }
        else if (i != 0)
        {
            if (i == 1 && firstInvalid) continue;

            if (deDuped.at(i) != deDuped.at(i - 1) + 1)
            {
                gap = true;
                break;
            }
        }
    }
    return !gap;
}

/*
 * Returns score of small straight
 */
int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5)
{
    if (isSmallStraight(die1, die2, die3, die4, die5))
    {
        return SMALL_STRAIGHT_SCORE;
    }
    else
    {
        return 0;
    }
}