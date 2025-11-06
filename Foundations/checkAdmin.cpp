//
// Created by Suleiman Hajj on 2025-10-29.
//

#include "checkAdmin.h"
#include <iostream>
using namespace std;

void checkAdmin() {
    string admins[] = {"suleiman", "ayman", "rayyan", "abdulrahman", "joseph"};
    int ttlAdmins = sizeof(admins) / sizeof(admins[0]);
    cout << "\tDatabase\nEnter name: ";
    string name;
    cin >> name;
    bool isAdmin = false;
    for (int i = 0; i < ttlAdmins; i++) {
        cout << i*8 << "--- ";
        for (int p = 0; p < 4; p++) {
            cout << "#";
        }

        cout << endl;

        if (name == admins[i]) {
            isAdmin = true;
            cout << "-- Access Granted --" << endl;
            break;
        }
    }
    if (!isAdmin) {
        cout << "-- Access Denied --" << endl;
    }
}

int main() {
    bool checkAdminLoop = true;
    while (checkAdminLoop) {
        checkAdmin();
        cout << "Login: ";
        string login;
        cin >> login;
        if (login == "yes") {
            checkAdminLoop= true;
        } else {
            checkAdminLoop = false;
        }
    }
}