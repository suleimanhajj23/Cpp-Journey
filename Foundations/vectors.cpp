//
// Created by Suleiman Hajj on 2025-10-31.
//

#include "vectors.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void loopInventory() {
    vector<string> inventory = {"Wallet", "Phone", "Airpods"};
    cout << "--- Pockets ---\n";
    bool loop = true;
    while (loop) {
        cout << "1. Add item\n2. Remove item\n3. Exit\nChoice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter item name: ";
            string itemName;
            cin >> itemName;
            inventory.push_back(itemName);
            cout << "\nItem added!\n";
            cout << "\n--- Inventory ---\n";
            for (const auto& item : inventory) {
                cout << "- " << item << endl;
            }
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter item name: ";
            string itemName;
            cin >> itemName;
            inventory.erase(remove(inventory.begin(), inventory.end(), itemName), inventory.end());
            cout << "\nItem removed!\n";
            cout << "\n--- Inventory ---\n";
            for (const auto& item : inventory) {
                cout << "- " << item << endl;
            }
            cout << endl;
        } else if (choice == 3) {
            cout << "Exiting...\n";
            loop = false;
        } else {
            cout << "Invalid\n";
        }
    }
}

int main() {
    loopInventory();
    return 0;
}