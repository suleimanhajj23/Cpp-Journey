//
// Created by Suleiman Hajj on 2025-11-05.
//
#include "fileCreating.h"
#include <string>
#include <fstream>

int main() {
    std::string fileName1 = "test1.txt";
    std::string fileName2 = "test2.txt";
    std::string fileName3 = "test3.txt";

    std::ofstream file1(fileName1);
    std::ofstream file2(fileName2);
    std::ofstream file3(fileName3);

    file1 << "This is file 1";
    file2 << "This is file 2";
    file3 << "This is file 3";

    file1.close();
    file2.close();
    file3.close();
}