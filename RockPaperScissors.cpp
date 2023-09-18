#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;
// Function to read val from cin with a time limit
int getVal()
{
   
    int val = 0;
    std::thread t1([&]() {
        std::cin >> val;
        });
    std::this_thread::sleep_for(std::chrono::seconds(7));
    t1.detach();

    return val;
}

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int roundsToPlay = 3;
    int temp;
    char answer;
    //COLORE TXET
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //Choose the number of game rounds
    //COLORE TXET
    SetConsoleTextAttribute(h, 0xc);
    cout << "Do you want to choose the number of rounds?" << endl;
    //COLORE TXET
    SetConsoleTextAttribute(h, 3);
    cout << "If the answer is yes, type y, otherwise type n." << endl;

    cin >> answer;
    if (answer == 'y')
    {//COLORE TXET
        SetConsoleTextAttribute(h, 0xc);
        cout << "Please enter the number of rounds " << endl;
        cin >> temp;
        roundsToPlay = temp;


    }



    // Seed the random number generator
    srand(time(0));

    for (int round = 1; round <= roundsToPlay; ++round) {
        //COLORE TXET
        SetConsoleTextAttribute(h, 2);
        cout << "Round " << round << endl;
        //COLORE TXET
        SetConsoleTextAttribute(h, 1);
        cout << "Choose (1) Rock " << endl;
        //COLORE TXET
        SetConsoleTextAttribute(h, 5);
        cout << " (2) Paper " << endl;
        //COLORE TXET
        SetConsoleTextAttribute(h, 6);
        cout << " (3) Scissors: " << endl;
        //COLORE TXET
        SetConsoleTextAttribute(h, 0xc);
        cout << "You only have 7 seconds." << endl;
        // Add a timer (7 seconds) before the next round

        playerChoice = getVal();

        // Generate a random computer choice (1-3)
        computerChoice = rand() % 3 + 1;

        // Display the computer's choice
        switch (computerChoice) {
        case 1:
            //COLORE TXET
            SetConsoleTextAttribute(h, 2);
            cout << "Computer chose Rock." << endl;
            break;
        case 2:
            //COLORE TXET
            SetConsoleTextAttribute(h, 1);
            cout << "Computer chose Paper." << endl;
            break;
            //COLORE TXET
            SetConsoleTextAttribute(h, 6);
        case 3:
            cout << "Computer chose Scissors." << endl;
            break;
        }

        // Determine the winner of this round
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        }
        else if ((playerChoice == 1 && computerChoice == 3) ||
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2)) {
            //COLORE TXET
            SetConsoleTextAttribute(h, 2);
            cout << "Player wins this round!" << endl;
            playerScore++;
        }
        else {
            //COLORE TXET
            SetConsoleTextAttribute(h, 0xc);
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }
    }

    // Determine the overall winner
    
    cout << "Game Over!" << endl;
    //COLORE TXET
    SetConsoleTextAttribute(h, 8);
    cout << "Player Score: " << playerScore << endl;
    cout << "Computer Score: " << computerScore << endl;

    if (playerScore > computerScore) {
        //COLORE TXET
        SetConsoleTextAttribute(h, 2);
        cout << "Player wins the game!" << endl;
    }
    else if (playerScore < computerScore) {
        //COLORE TXET
        SetConsoleTextAttribute(h, 0xc);
        cout << "Computer wins the game!" << endl;
    }
    else {
        //COLORE TXET
        SetConsoleTextAttribute(h, 8);
        cout << "It's a tie game!" << endl;
    }

    return 0;
}
