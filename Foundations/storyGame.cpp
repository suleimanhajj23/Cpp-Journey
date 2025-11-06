// Created by Suleiman Hajj on 2025-10-30.
#include "storyGame.h"
#include <iostream>
#include <random>
#include <map>
using namespace std;

string playerName;
int hungerLvl = 0;

int randInt(int min, int max) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

void credits() {
    map<string, string> creditsTxt;
    cout << "--- Credits ---" << endl;
    creditsTxt["Head Programmer"] = "Suleiman Hajj";
    creditsTxt["Code Editor"] = "Suleiman Hajj";
    creditsTxt["Program Director"] = "Suleiman Hajj";
    creditsTxt["Program Supervisor"] = "Suleiman Hajj";
    creditsTxt["Story Director"] = "Suleiman Hajj";
    creditsTxt["Story Writer"] = "Suleiman Hajj";
    creditsTxt["Project Manager"] = "Suleiman Hajj";
    creditsTxt["Project Coordinator"] = "Suleiman Hajj";
    for (auto const &pair : creditsTxt) {
        cout << pair.first << " - " << pair.second << endl;
    }
    cout << "--- End of Credits ---" << endl;
}

void showHunger() {
    cout << "Hunger/Thirst levels: " << hungerLvl << "%" << endl;
}

void die(const string &reason) {
    cout << playerName << " died! Reason: " << reason << endl;
    credits();
}

void treasure(const string &place) {
    int treasureRandom = randInt(0,2);
    string treasure;
    switch (treasureRandom) {
        case 0:
            treasure = "Gold and Silver";
            break;
        case 1:
            treasure = "iPhone 17 Pro Max";
            break;
        case 2:
            treasure = "Coal";
            break;
        default:
            treasure = "$1,000,000";
            break;
    }
    cout << "--- Treasure Box ---\n" << treasure << endl;
    if (place == "island") {
        cout << "You got bored and swam back to your home!" << endl;
    } else {
        if (treasure == "coal") {
            cout << "You were disappointed with your treasure and went to rob a village." << endl;
            cout << "You were unsuccessful..." << endl;
            die("Public execution by guillotine");
        }
    }
    cout << playerName << ", you completed the game!" << endl;
    credits();
}

void findFood() {
    cout << "--- Island ---" << endl;
    string food;
    int foodRandom = randInt(0,2);
    switch (foodRandom) {
        case 0:
            food = "Steak";
            break;
        case 1:
            food = "Chicken wings";
            break;
        case 2:
            food = "Banana";
            break;
        default:
            food = "Chips";
    }
    cout << "You walked around the island and found " << food << endl;
    hungerLvl = 0;
    showHunger();
    die("Got too full...");
}

void sail() {
    cout << "--- Sailing ---" << endl;
    cout << "You sailed for 1 and a half days and ended up in open waters" << endl;
    hungerLvl += 20;
    showHunger();
    cout << "You found an island" << endl;
    cout << "1. Land on the island" << endl;
    cout << "2. Keep sailing" << endl;
    cout << "Choice: ";
    int sailChoice = 0;
    cin >> sailChoice;
    if (sailChoice == 1) {
        cout << "You landed on the island and found a treasure box." << endl;
        hungerLvl += 20;
        showHunger();
        cout << "1. Open the treasure box" << endl;
        cout << "2. Find food" << endl;
        cout << "Your choice: ";
        int islandChoice = 0;
        cin >> islandChoice;
        if (islandChoice == 1) {
            treasure("island");
        } else {
            findFood();
        }
    } else if (sailChoice == 2) {
        hungerLvl = 95;
        showHunger();
        cout << "You continued sailing for 7 days without seeing land" << endl;
        die("Got too hungry...");
    } else {
        cout << "You waited too long and a wave flipped your raft." << endl;
        die("Drowning");
    }
}

void cave() {
    cout << "--- Cave ---" << endl;
    cout << "You entered a cave." << endl;
    cout << "1. Go deeper" << endl;
    cout << "2. Relax" << endl;
    cout << "3. Find food" << endl;
    int caveChoice = 0;
    cin >> caveChoice;
    if (caveChoice == 1) {
        int caveOutcome = randInt(0,1);
        if (caveOutcome == 0) {
            cout << "You encountered a giant spider 10ft wide..." << endl;
            die("Eaten by spider");
        } else if (caveOutcome == 1) {
            cout << "A dinosaur appeared out of no where..." << endl;
            die("Swallowed by dinosaur");
        }
    } else if (caveChoice == 2) {
        hungerLvl = 95;
        showHunger();
        cout << "You fell asleep and a gorilla found you." << endl;
        die("Became a gorilla's dinner");
    } else if (caveChoice == 3) {
        findFood();
    } else {
        cout << "You waited too long..." << endl;
        die("Giant rock crushed you.");
    }
}

void explore() {
    cout << "--- Exploring ---" << endl;
    cout << playerName << ", you found a village" << endl;
    cout << "1. Stay with the locals\n2. Rob them\nYour choice: ";
    int exploreChoice = 0;
    cin >> exploreChoice;
    if (exploreChoice == 1) {
        cout << "You settled in the village and became one with the locals." << endl;
        cout << playerName << " completed the game!" << endl;
        credits();
    } else if (exploreChoice == 2) {
        cout << "You tried robbing the village." << endl;
        die("Public Execution.");
    } else {
        cout << "You didn't know what to do, so you robbed the village" << endl;
        die("Public hanging");
    }
}

void junglePath1() {
    cout << "--- River Trail ---" << endl;
    int raftChoice;
    cout << playerName << ", you've encountered a river and a raft.\n1. Continue exploring in the jungle\n2. Sail on the raft\nChoice: ";
    cin >> raftChoice;
    if (raftChoice == 1) {
        explore();
    } else if (raftChoice == 2) {
        sail();
    }
}

void junglePath2() {
    cout << "--- Jungle Trail" << endl;
    int jungleChoice;
    cout << playerName << ", you've encountered a temple!" << endl;
    cout << "1. Keep exploring and skip the temple" << endl;
    cout << "2. Go inside" << endl;
    cout << "3. Find a cave" << endl;
    cout << "Choice: ";
    cin >> jungleChoice;
    if (jungleChoice == 1) {
        explore();
    } else if (jungleChoice == 2) {
        int templeOutcome = randInt(0,1);
        if (templeOutcome == 0) {
            cout << "You get greeted by an unfriendly tiger!" << endl;
            die("Eaten by tiger.");
        } else if (templeOutcome == 1) {
            cout << "You find a treasure box" << endl;
            treasure("jungle");
        }
    }
    else if (jungleChoice == 3) {
        cave();
    } else {
        cout << "You waited too long..." << endl;
        die("Eaten by rat");
    }
}

void startGame() {
    cout << "--- Story Game ---" << endl;
    cout << "Enter player name: ";
    cin >> playerName;
    cout << "Welcome, " << playerName << "!\n" << endl;
    showHunger();
    cout << "You awake in the jungle, in front of you lies 2 trails.\nChoose a trail (1 / 2): ";
    int junglePath = 0;
    cin >> junglePath;
    if (junglePath == 1) {
        junglePath1();
    } else if (junglePath == 2) {
        junglePath2();
    } else {
        int pathRandom = randInt(0,1);
        if (pathRandom == 0) {
            cout << "That path does not exist, You decided to walk into the first trail." << endl;
            junglePath1();
        } else if (pathRandom == 1) {
            cout << "That path does not exist, You decided to walk into the second trail." << endl;
            junglePath2();
        }

    }
}

int main() {
    startGame();
    return 0;
}