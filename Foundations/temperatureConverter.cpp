// Created by Suleiman Hajj on 2025-10-29.

#include "temperatureConverter.h"
#include <iostream>
using namespace std;

double CtoF(double C) {return (C * (9.0/5)) + 32;}
double FtoC(double F) {return (F - 32) * (5.0/9);}
double CtoK(double C) {return C + 273.15;}
double KtoC(double K) {return (K - 273.15);}
double KtoF(double K) {return CtoF(KtoC(K));}
double FtoK(double F) {return CtoK((FtoC(F)));}

void errorMessage(char unit) {
    cout << unit << " is not a valid unit." << endl;
}

void finalMessage(double temp, char unit, double convertedTemp, char unitConvert) {
    cout << temp << " " << unit << " is " << convertedTemp << " " << unitConvert << endl;
}
void convert() {
    char convertTo;
    char temperatureUnit;
    double temperature;
    double convertedTemperature = 0.00;

    cout << "Temperature: ";
    cin >> temperature;

    cout << "Unit (F-C-K): ";
    cin >> temperatureUnit;

    cout << "Convert to (F-C-K): ";
    cin >> convertTo;

    if (temperatureUnit == 'F') {
        switch (convertTo) {
            case 'F':
                convertedTemperature = temperature;
                break;
            case 'C':
                convertedTemperature = FtoC(temperature);
                break;
            case 'K':
                convertedTemperature = FtoK(temperature);
            default:
                errorMessage(convertTo);
                break;

        }
    } else if (temperatureUnit == 'C') {
        switch (convertTo) {
            case 'C':
                convertedTemperature = temperature;
                break;
            case 'F':
                convertedTemperature = CtoF(temperature);
                break;
            case 'K':
                convertedTemperature = CtoK(temperature);
                break;
            default:
                errorMessage(convertTo);
                break;
        }

    } else if (temperatureUnit == 'K') {
        switch (convertTo) {
            case 'C':
                convertedTemperature = KtoC(temperature);
                break;
            case 'F':
                convertedTemperature = KtoF(temperature);
                break;
            case 'K':
                convertedTemperature = temperature;
                break;
            default:
                errorMessage(convertTo);
                break;
        }
    } else {
        errorMessage(convertTo);
    }

    finalMessage(temperature, temperatureUnit, convertedTemperature, convertTo);
}

int main() {
    bool convertAgain = true;
    string userInput;
    cout << "Temperature Converter" << endl;
    while (convertAgain) {
        convert();
        cout << "Make another conversion: ";
        cin >> userInput;
        if (userInput == "yes") {
            convertAgain = true;
        } else {
            convertAgain = false;
        }
    }
    return 0;
}