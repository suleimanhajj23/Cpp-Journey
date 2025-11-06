//
// Created by Suleiman Hajj on 2025-11-01.
//

#include "todolist.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

struct listStruct {
    std::vector<std::string> list;
};

void actions() {
    listStruct l;
    bool repeat = true;
    int action;
    std::string task;

    while (repeat) {
        std::cout << "\n1. Add task\n2. Remove Task\n3. View Tasks\n4. Exit\nYour selection: ";
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid selection. Please enter a number from the menu.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (action) {
            case 1:
                std::cout << "Enter task name: ";
                std::getline(std::cin, task);
                if (!task.empty()) {
                    l.list.push_back(task);
                    std::cout << "\nTask Added!\n";
                } else {
                    std::cout << "No task entered. Nothing added.\n";
                }
                break;

            case 2:
                std::cout << "Enter task name to remove: ";
                std::getline(std::cin, task);
                if (task.empty()) {
                    std::cout << "No task entered. Nothing removed.\n";
                    break;
                }
                {
                    auto oldSize = l.list.size();
                    l.list.erase(std::remove(l.list.begin(), l.list.end(), task), l.list.end());
                    if (l.list.size() < oldSize) {
                        std::cout << "\nTask Removed\n\n";
                    } else {
                        std::cout << "\nTask not found. Nothing removed.\n\n";
                    }
                }
                break;

            case 3:
                if (l.list.empty()) {
                    std::cout << "\nYou have no tasks.\n";
                } else {
                    std::cout << "\nYour tasks\n";
                    for (const auto& listItem : l.list) {
                        std::cout << "- " << listItem << std::endl;
                    }
                }
                break;

            case 4:
                repeat = false;
                break;

            default:
                std::cout << "Invalid Selection\n";
                break;
        }
    }
}

int main() {
    std::cout << "\n-- My ToDo List --\n";
    actions();
    return 0;
}
