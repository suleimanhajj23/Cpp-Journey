//
// Created by Suleiman Hajj on 2025-11-01.
//

#include "bank.h"
#include <iostream>

int balance = 100;

void withdraw(int amount) {
    if (amount > balance) {
        std::cout << "\nInsufficient Funds!\n\n";
    } else {
        balance -= amount;
        std::cout << "Withdrew $ " << amount << "\n\n";
    }
}

void deposit (int amount) {
    balance += amount;
    std::cout << "\nDeposited $" << amount << "\n\n";
}

void viewBalance() {
    std::cout << "\nBalance: $" << balance << "\n\n";
}

void atm() {
    bool exit = false;
    while (!exit) {
        std::cout << "--- Bank of Milton ---\n\t1. Withdraw\n\t2. Deposit\n\t3. View Balance\n\t4. Exit\nSelection: ";
        int selection;
        std::cin >> selection;
        switch (selection) {
            case 1:
                if (balance > 0) {
                    std::cout << "Withdrawal amount : $";
                    int amount;
                    std::cin >> amount;
                    withdraw(amount);
                } else {
                    std::cout << "Insufficient Funds!\n";
                }
                break;
            case 2:
                std::cout << "Deposit amount: $";
                int amount;
                std::cin >> amount;
                deposit(amount);
                break;
            case 3:
                viewBalance();
                break;
            case 4:
                exit = true;
                break;
            default:
                std::cout << "Invalid selection!\n";
                break;
        }
    }
    std::cout << "Exiting..." << std::endl;
}

int main() {
    atm();
    return 0;
}