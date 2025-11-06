// Created by Suleiman Hajj on 2025-10-30.

#include "numberGuessing.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void guess() {
    int num = 0;
    int userGuess;
    int tries = 10;
    int difficulty;
    cout << "--- Number Guessing ---" << endl;
    cout << "Set Difficulty (1 - 2 - 3): ";
    cin >> difficulty;
    if (difficulty == 1) {
        tries = 5;
        num = rand() % 10 + 1;
        cout << "Range: 1 - 10, 5 tries" << endl;
    } else if (difficulty == 2) {
        tries = 5;
        num = rand() % 15 + 1;
        cout << "Range: 1 - 15, 5 tries" << endl;
    } else if (difficulty == 3) {
        tries = 3;
        num = rand() % 20 + 1;
        cout << "Range: 1 - 20, 3 tries" << endl;
    } else {
        cout << "Invalid difficulty, setting to 1" << endl;
    }

    for (int i = tries; i > 0; i--) {
        cout << tries << " Tries left\nEnter guess: ";
        cin >> userGuess;
        if (userGuess == num) {
            cout << "Congratulations! You got it!" << endl;
            break;
        } else {
            tries--;
            if (userGuess > num) {
                cout << "Incorrect guess! Number is Lower" << endl;
            } else if (userGuess < num) {
                cout << "Incorrect guess! Number is Higher" << endl;
            }
        }
    }
    if (userGuess != num) {
        cout << "You didn't get it, the number was " << num << endl;
    }
    cout << "--- End of Game ---" << endl;

}

void newGame() {
    bool start = true;
    while (start) {
        string startInput;
        cout << "Start new game (yes - no): ";
        cin >> startInput;
        if (startInput == "yes") {
            guess();
            start = true;
        } else {
            start = false;
            break;
        }
    }
}

int main() {
    newGame();
    return 0;
}