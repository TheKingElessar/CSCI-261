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

    cout << "\nPlayer 1 chooses: " << player1Word << endl;

    srand(time(nullptr));

    int randomChoice = rand();
    randomChoice = randomChoice % 3;

    string computerWord;
    if (randomChoice == 0) computerWord = "Rock";
    if (randomChoice == 1) computerWord = "Paper";
    if (randomChoice == 2) computerWord = "Scissors";

    cout << "Computer chooses: " << computerWord << "\n" << endl;

    if (player1Word == computerWord)
    {
        cout << "Both chose " << player1Word << ".\nIt's a tie!" << endl;
    }
    else if ((player1Word == "Rock" && computerWord == "Scissors") || (player1Word == "Scissors" && computerWord == "Paper") || (player1Word == "Paper" && computerWord == "Rock"))
    {
        cout << player1Word << " beats " << computerWord << ".\nPlayer wins!" << endl;
    }
    else if ((computerWord == "Rock" && player1Word == "Scissors") || (computerWord == "Scissors" && player1Word == "Paper") || (computerWord == "Paper" && player1Word == "Rock"))
    {
        cout << computerWord << " beats " << player1Word << ".\nComputer wins!" << endl;
    }

    return 1;
}