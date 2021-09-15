/* CSCI 261 Assignment 2: This One Goes To 11
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * First you get the numbers then you get the bounds then you classify it and get a random value that's pretty neat
 */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

bool isValid(float valueOne, float valueTwo);

float TOLERANCE = 0.000001;

int main()
{
    float valueOne;
    float valueTwo;

    cout << "Enter the first value of the range: ";
    cin >> valueOne;

    cout << "Enter the second value of the range: ";
    cin >> valueTwo;

    if (!isValid(valueOne, valueTwo))
    {
        cout << "Invalid values! :(" << endl;
        return 0;
    }

    cout << "\nValid!" << endl;

    float lower;
    float upper;
    if (valueOne < valueTwo)
    {
        lower = valueOne;
        upper = valueTwo;
    }
    else
    {
        lower = valueTwo;
        upper = valueOne;
    }

    cout << "Min: " << lower << endl;
    cout << "Max: " << upper << endl;

    float bound1 = lower + ((upper - lower) * 1 / 3.0);
    float bound2 = lower + ((upper - lower) * 2 / 3.0);;

    cout << "\nLow/Medium Boundary: " << bound1 << endl;
    cout << "Medium/High Boundary: " << bound2 << endl;

    cout << "\nEnter a temperature: ";
    float temperature;
    cin >> temperature;
    cout << "\n";

    srand(time(nullptr));
    float scaledRandom = static_cast<float>(rand());
    scaledRandom = scaledRandom / RAND_MAX;

    float exampleTemp;
    if (temperature >= (lower - TOLERANCE) && temperature <= bound1)
    {
        cout << temperature << " is a Low temperature." << endl;
        exampleTemp = (bound1 - lower) * scaledRandom + lower;
    }
    else if (temperature >= bound1 && temperature <= bound2)
    {
        cout << temperature << " is a Medium temperature." << endl;
        exampleTemp = (bound2 - bound1) * scaledRandom + bound1;
    }
    else if (temperature >= bound2 && temperature <= (upper + TOLERANCE))
    {
        cout << temperature << " is a High temperature." << endl;
        exampleTemp = (upper - bound2) * scaledRandom + bound2;
    }
    else
    {
        cout << temperature << " is out of range." << endl;
        return 0;
    }

    exampleTemp = round(exampleTemp * 100) / 100;
    cout << "\nYou could also use " << exampleTemp << " as a temperature." << endl;

    return 0;
}

bool isValid(float valueOne, float valueTwo)
{
    if (valueOne == valueTwo)
    {
        return false;
    }
    if (fabs(valueOne - valueTwo) < TOLERANCE)
    {
        return false;
    }

    return true;
}