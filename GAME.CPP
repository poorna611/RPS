#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to get user's choice
char getUserChoice() {
    cout << "Choose (R)ock, (P)aper, or (S)cissors: ";
    char choice;
    cin >> choice;
    return toupper(choice);  // Convert to uppercase for case-insensitive comparison
}

// Function to get computer's choice
char getComputerChoice() {
    srand(time(0));  // Seed the random number generator
    int randNum = rand() % 3;  // Generate a random number between 0 and 2
    switch (randNum) {
        case 0: return 'R';
        case 1: return 'P';
        case 2: return 'S';
    }
    return ' ';  // Default case (should not happen)
}

// Function to determine the winner
void determineWinner(char userChoice, char computerChoice) {
    cout << "Computer chose: " << computerChoice << endl;
    cout << "You chose: " << userChoice << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if (
        (userChoice == 'R' && computerChoice == 'S') ||
        (userChoice == 'P' && computerChoice == 'R') ||
        (userChoice == 'S' && computerChoice == 'P')
    ) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    char userChoice;
    char computerChoice;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    do {
        userChoice = getUserChoice();
        computerChoice = getComputerChoice();
        determineWinner(userChoice, computerChoice);

        // Ask the user if they want to play again
        cout << "Do you want to play again? (Y/N): ";
        char playAgain;
        cin >> playAgain;

        // If the user enters anything other than 'Y' or 'y', exit the loop
        if (playAgain != 'Y' && playAgain != 'y') {
            break;
        }

    } while (true);

    cout << "Thanks for playing!" << endl;

    return 0;
}
