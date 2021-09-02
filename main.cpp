/* CSCI 261 A1: Hello ASCII Art!
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *
 *
 *  In this homework assignment, we focus on three of our programming concepts: (1) defining variables, (2) using input, and (3) using output.
 */

#include <iostream>

using namespace std;

int main()
{

    cout <<
         "                  /////                    \n"
         "               /////////////               \n"
         "            ////////...../////             \n"
         "          ////..................           \n"
         "          .....ooo.......ooo.....          \n"
         "          .....oooo.....oooo.....          \n"
         "          .......................          \n"
         "          .......................          \n"
         "           ....wwwwwwwwwwww.....           \n"
         "           ;:;....wwwwwwww...;;            \n"
         "            ;;;;;;;:;;;:;;:;;:             \n"
         "             ;:;;;;;:;;;;:;:;              \n"
         "               :;:;;:;;;:;;                \n"
         "                   :;;;:                   \n"
         << endl;

    int ssn = 0;
    float milesFromPrison = 0.0;
    bool convictedOfTreason = false;

    cout << "What's your SSN (digits only)? ";
    cin >> ssn;
    cout << "How many miles are you from the nearest prison? ";
    cin >> milesFromPrison;
    cout << "Have you ever been convicted of treason (true/false)? ";
    cin >> convictedOfTreason;

    cout << "Your SSN is " << ssn << "." << endl;
    cout << "You are " << milesFromPrison << " miles from the nearest prison." << endl;

    if (convictedOfTreason)
    {
        cout << "You HAVE been convicted of treason." << endl;
    }
    else
    {
        cout << "You have NEVER been convicted of treason (yet)." << endl;
    }

    return 0;
}