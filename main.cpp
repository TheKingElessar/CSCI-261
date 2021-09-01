/* CSCI 261 Lab01C: Math Equations
 *
 * Author: Brick Dalsis, Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used: None
 *
 * Description: Code for two math equations (calculations for stress and voltage)
 */
#include <iostream>

using namespace std;


int main() {
    double force;
    double accl;
    double stress;
    double current;
    double resistance;
    double voltage;

    //stress equation
    cout << "What is the force? ";
    cin >> force;
    cout << "What is the acceleration? ";
    cin >> accl;
    stress = force / accl;
    cout << "The stress of the object is: " << stress << " N/m^2" << endl;

    //ohms law
    cout << "\nWhat is the resistance? ";
    cin >> resistance;
    cout << "What is the current? ";
    cin >> current;
    voltage = current * resistance;
    cout << "The voltage of the object is: " << voltage << " V";

    return 0;
}