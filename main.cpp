/* CSCI 261 Lab 7C: Classes Part II: Godzilla vs Mechagodzilla
 *
 * Author: Nathan Panzer
 *
 * Focus on expanding the Godzilla class from Lab7B.
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
    cout << endl;

    godzilla.greet(mechagodzilla);
    mechagodzilla.greet(godzilla);
    cout << endl;

    godzilla.attack(mechagodzilla);
    while (godzilla.getHealth() > 0)
    {
        mechagodzilla.attack(godzilla);
    }

    return 0;
}