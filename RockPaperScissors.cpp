#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    const int roundsToPlay = 3;

    // Seed the random number generator
    srand(time(0));

    for (int round = 1; round <= roundsToPlay; ++round) {
        cout << "Round " << round << endl;
        cout << "Choose (1) Rock, (2) Paper, or (3) Scissors: ";
        cin >> playerChoice;

        // Generate a random computer choice (1-3)
        computerChoice = rand() % 3 + 1;

        // Display the computer's choice
        switch (computerChoice) {
            case 1:
                cout << "Computer chose Rock." << endl;
                break;
            case 2:
                cout << "Computer chose Paper." << endl;
                break;
            case 3:
                cout << "Computer chose Scissors." << endl;
                break;
        }

        // Determine the winner of this round
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) || 
                   (playerChoice == 2 && computerChoice == 1) || 
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "Player wins this round!" << endl;
            playerScore++;
        } else {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }
    }

    // Determine the overall winner
    cout << "Game Over!" << endl;
    cout << "Player Score: " << playerScore << endl;
    cout << "Computer Score: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Player wins the game!" << endl;
    } else if (playerScore < computerScore) {
        cout << "Computer wins the game!" << endl;
    } else {
        cout << "It's a tie game!" << endl;
    }

    return 0;
}
