/* CSCI 261 Lab 2C: RPS: And The Winner Is
 *
 * Author: Nathan Panzer
 *
 * In which Spock and a piece of Paper fight to the death
 */

#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    cout << "Welcome one and all to a round of Rock, Paper, Scissors, Lizard, Spock! (Enter R, P, S, L, or O)" << endl;
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
    else if (player1Choice == 'l' || player1Choice == 'L')
    {
        player1Word = "Lizard";
    }
    else if (player1Choice == 'o' || player1Choice == 'O')
    {
        player1Word = "Spock";
    }
    else
    {
        cout << "That's not a real thing..." << endl;
        return 1;
    }

    cout << "\nPlayer 1 chooses: " << player1Word << endl;

    srand(time(nullptr));

    int randomChoice = rand();
    randomChoice = randomChoice % 5;

    string computerWord;
    if (randomChoice == 0) computerWord = "Rock";
    if (randomChoice == 1) computerWord = "Paper";
    if (randomChoice == 2) computerWord = "Scissors";
    if (randomChoice == 3) computerWord = "Lizard";
    if (randomChoice == 4) computerWord = "Spock";

    cout << "Computer chooses: " << computerWord << "\n" << endl;

    if (player1Word == computerWord)
    {
        cout << "Both chose " << player1Word << ".\nIt's a tie!" << endl;
    }
    else if ((player1Word == "Rock" && (computerWord == "Scissors" || computerWord == "Lizard")) ||
             (player1Word == "Paper" && (computerWord == "Rock" || computerWord == "Spock")) ||
             (player1Word == "Scissors" && (computerWord == "Paper" || computerWord == "Lizard")) ||
             (player1Word == "Lizard" && (computerWord == "Spock" || computerWord == "Paper")) ||
             (player1Word == "Spock" && (computerWord == "Scissors" || computerWord == "Rock")))
    {
        cout << player1Word << " beats " << computerWord << ".\nPlayer wins!" << endl;
    }
    else if ((computerWord == "Rock" && (player1Word == "Scissors" || player1Word == "Lizard")) ||
             (computerWord == "Paper" && (player1Word == "Rock" || player1Word == "Spock")) ||
             (computerWord == "Scissors" && (player1Word == "Paper" || player1Word == "Lizard")) ||
             (computerWord == "Lizard" && (player1Word == "Spock" || player1Word == "Paper")) ||
             (computerWord == "Spock" && (player1Word == "Scissors" || player1Word == "Rock")))
    {
        cout << computerWord << " beats " << player1Word << ".\nComputer wins!" << endl;
    }

    return 1;
}