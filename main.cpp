/* CSCI 261 Assignment 2: This One Goes To 11
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
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

    if (temperature >= (lower - TOLERANCE) && temperature <= bound1)
    {
        cout << temperature << " is a Low temperature." << endl;
    }
    else if (temperature >= bound1 && temperature <= bound2)
    {
        cout << temperature << " is a Medium temperature." << endl;
    }
    else if (temperature >= bound2 && temperature <= (upper + TOLERANCE))
    {
        cout << temperature << " is a High temperature." << endl;
    }
    else
    {
        cout << temperature << " is out of range." << endl;
        return 0;
    }

    srand(time(nullptr));
    float randomFloat = static_cast<float>(rand());

    float upperScale = upper * 100;
    float lowerScale = lower * 100;

    float remainder = randomFloat % (upperScale - lowerScale);

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