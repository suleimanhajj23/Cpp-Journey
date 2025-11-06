// Created by Suleiman Hajj on 2025-11-04.
#include "bankSim.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class database {
    public:
        std::vector<std::string>users = {};
        std::vector<int>passcodes = {};
        std::vector<int>balance = {};
        database() {
            loadFromFile();  // Load existing data
            // Only add default user if file doesn't exist
            if (users.empty()) {
                users.emplace_back("suleimanhajj");
                passcodes.emplace_back(1234);
                balance.emplace_back(1009);
            }
        }

    void saveToFile() {
            std::ofstream file("bankData.txt");
            if (file.is_open()) {
                for (int i = 0; i < users.size(); i++) {
                    file << users[i] << "\n";
                    file << passcodes[i] << "\n";
                    file << balance[i] << "\n";
                }
                file.close();
            }
        }

    void loadFromFile() {
            std::ifstream file("bankData.txt");
            if (file.is_open()) {
                int size;
                file >> size;
                file.ignore();

                for (int i = 0; i < size; i++) {
                    std::string user;
                    int pin, bal;

                    std::getline(file, user);
                    file >> pin >> bal;
                    file.ignore();

                    users.push_back(user);
                    passcodes.push_back(pin);
                    balance.push_back(bal);
                }
                file.close();
            }
        }
};

class accounts {
    public:
        static int countDigit(int n) {
            if (n == 0) {
                return 0;
            }
            int count = 0;
            while (n != 0) {
                n /= 10;
                count++;
            }
            return count;
        }

        static void login(database& db) {
            bool loggedIn = false;
            bool correctPin = false;
            int accountPin;
            int accountNum = 0;
            std::string username;
            std::cout << "Log in\n";
            while (!loggedIn) {
                std::cout << "Enter username: ";
                std::cin >> username;
                if (username.empty()) {
                    std::cout << "Invalid username\n";
                    loggedIn = false;
                } else {
                    for (int i = 0; i < db.users.size(); i++) {
                        if (username == db.users[i]) {
                            std::cout << "Enter pin: ";
                            std::cin >> accountPin;
                            if (accountPin == db.passcodes[i]) {
                                std::cout << "Logged in!\n";
                                accountNum = i;
                                correctPin = true;
                                break;
                            }
                        }
                    }
                    if (!correctPin) {
                        std::cout << "Incorrect pin!\n";
                        loggedIn = false;
                    } else {
                        loggedIn = true;
                        actions(db, accountNum);
                    }
                }
            }

        }

        static void signup(database& db) {
            std::string username;
            bool unique = false;
            while (!unique) {
                std::cout << "Create username: ";
                std::cin >> username;
                if (username.empty()) {
                    std::cout << "Invalid username\n";
                } else {
                    for (int i = 0; i < db.users.size(); i++) {
                        if (username == db.users[i]) {
                            unique = false;
                        } else {
                            db.users.push_back(username);
                            unique = true;
                            break;
                        }
                    }
                    if (!unique) {
                        std::cout << "That username is taken! Try again\n";
                        unique = false;
                    } else {
                        unique = true;
                    }
                }
            }
            bool valid = false;
            int userPin;
            while (!valid) {
                std::cout << "Create pin (4 digits max.): ";
                std::cin >> userPin;
                if (countDigit(userPin) == 4) {
                    valid = true;
                    std::cout << "Pin set!\n";
                    db.passcodes.push_back(userPin);
                    db.balance.push_back(0);
                    db.saveToFile();
                } else {
                    std::cout << "Invalid user pin (4 digits max.)\n";
                    valid = false;
                }
            }
            std::cout << "Signed up!\n";
            login(db);
        }

        static void actions(database& db, const int accountNum) {
            bool exitBank = false;
            while (!exitBank) {
                std::cout << "1. Withdraw\n";
                std::cout << "2. Deposit\n";
                std::cout << "3. View Balance\n";
                std::cout << "4. Quit\n";
                int choice;
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        std::cout << "Enter amount: $";
                        int amount = 0;
                        std::cin >> amount;
                        if (amount < 0 || amount > db.balance[accountNum]) {
                            std::cout << "Invalid amount $";
                        } else {
                            db.balance[accountNum] -= amount;
                            db.saveToFile();
                            std::cout << "Balance: $" << db.balance[accountNum] << "\n";
                        }
                    }
                        break;
                    case 2: {
                        std::cout << "Enter amount: $";
                        int amount = 0;
                        std::cin >> amount;
                        db.balance[accountNum] += amount;
                        db.saveToFile();
                        std::cout << "Balance: $" << db.balance[accountNum] << "\n";
                    }
                        break;
                    case 3:
                        std::cout << "Balance: $" << db.balance[accountNum] << "\n";
                        break;
                    case 4:
                        std::cout << "Quiting bank.\n";
                        exit(0);
                    default:
                        std::cout << "Invalid choice\n\n";
                }
                std::cout << "Make another transaction? yes/no: ";
                std::string answer;
                std::cin >> answer;
                if (answer == "yes") {
                    exitBank = false;
                } else {
                    exitBank = true;
                }
            }
            std::cout << "\nExiting bank.\n";
            exit(0);
        }

        static void accountHandling() {
            database db;
            std::cout << "(S)ign up / (L)ogin: ";
            char userChoice;
            std::cin >> userChoice;
            // Sign up user
            if (userChoice == 'S' || userChoice == 's') {
                signup(db);
            } else if (userChoice == 'L' || userChoice == 'l') {
                login(db);
            }
        }
};

int main() {
    accounts::accountHandling();
    return 0;
}