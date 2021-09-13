/* CSCI 261 Lab 2A: RPS: Human vs. Computer
 *
 * Author: Nathan Panzer
 *
 * look mom i can generate random numbers between 0 and 2
 */

#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl;
    cout << "Player 1: ";

    char player1Choice = '0';
    cin >> player1Choice;
    cout << "\nPlayer 1 chooses: " << player1Choice << endl;

    srand(time(nullptr));

    int randomChoice = rand();
    randomChoice = randomChoice % 3;
    cout << "Computer chooses: " << randomChoice << endl;

    return 0;
}