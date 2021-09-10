// I cannot feel my teeth

#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl;
    cout << "Player 1: ";

    char player1Choice = '0';
    cin >> player1Choice;

    string player1Word;
    if (player1Choice == 'r' || player1Choice == 'R')
    {
        player1Word = "Rock";
    }
    else if (player1Choice == 'p' || player1Choice == 'P')
    {
        player1Word = "Paper";
    }
    else if (player1Choice == 's' || player1Choice == 'S')
    {
        player1Word = "Scissors";
    }
    else
    {
        cout << "That's not a real thing..." << endl;
        return 1;
    }

    cout << "Player 1 chooses: " << player1Word << "\n" << endl;

    srand(time(nullptr));

    int randomChoice = rand();
    randomChoice = randomChoice % 3;

    string computerChoice;
    if (randomChoice == 0) computerChoice = "Rock";
    if (randomChoice == 1) computerChoice = "Paper";
    if (randomChoice == 2) computerChoice = "Scissors";

    cout << "Computer chooses: " << computerChoice << endl;

    return 0;
}