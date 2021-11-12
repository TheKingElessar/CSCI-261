/* CSCI 261 Lab 7B: Classes Part I: Godzilla
 *
 * Author: Nathan Panzer
 *
 * Focus on defining a Godzilla class from scratch.
 */

#include <iostream>
#include "Godzilla.h"

using namespace std;

int main()
{
    double healthInput, powerInput;
    cout << "Enter the health of Godzilla: ";
    cin >> healthInput;
    cout << "Enter the power of Godzilla: ";
    cin >> powerInput;
    Godzilla godzilla;
    godzilla.setHealth(healthInput);
    godzilla.setPower(powerInput);
    cout << endl;

    string nameInput;
    cout << "Enter the name of the second creature: ";
    cin >> nameInput;
    cout << "Enter the health of the second creature: ";
    cin >> healthInput;
    cout << "Enter the power of the second creature: ";
    cin >> powerInput;
    cout << endl;
    Godzilla mechagodzilla(nameInput, healthInput, powerInput);

    cout << "The two creatures are:" << endl;
    cout << godzilla.getName() << " (P: " << godzilla.getPower() << ") - H: " << godzilla.getHealth() << endl;
    cout << mechagodzilla.getName() << " (P: " << mechagodzilla.getPower() << ") - H: " << mechagodzilla.getHealth()
         << endl;

    return 0;
}