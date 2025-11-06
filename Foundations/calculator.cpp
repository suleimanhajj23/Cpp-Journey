//
// Created by Suleiman Hajj on 2025-10-28.
//

#include "calculator.h"
#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
double divide(double a, double b) {
    if (a != 0 && b != 0) {
        return a / b;
    } else {
        return 0;
    }
}

void calculate() {
    cout << "Enter first number: ";
    int first;
    cin >> first;
    cout << "Enter operator: ";
    char oper;
    cin >> oper;
    cout << "Enter second number: ";
    int second;
    cin >> second;
    switch (oper) {
        case '+':
            cout << first << oper << second << "=" << add(first, second) << endl;
            break;
        case '-':
            if (second < 0) {
                cout << first << oper << "(" << second << ")" << "=" << sub(first, second) << endl;
                break;
            } else {
                cout << first << oper << second << "=" << sub(first, second) << endl;
                break;
            }
        case '*':
            cout << first << oper << second << "=" << mul(first, second) << endl;
            break;
        case '/':
            cout << first << oper << second << "=" << divide(first, second) << endl;
            break;
        default:
            cout << endl;
    }


}

int main() {
    bool calculateCont = true;
    while (calculateCont) {
        calculate();
        cout << "Calculate again? ";
        string input;
        cin >> input;
        if (input == "yes") {
            calculateCont = true;
        } else {
            calculateCont = false;
        }
    }
}