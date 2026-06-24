/**
 * @file Validation.cpp
 * @brief Input validation functions for menus and integer numbers.
 */

#include <iostream>
#include "../Headers/InfixToPostfix.h"
#include "../Headers/Config.h"

using namespace std;

/**
 * @brief Validates that the input is a valid menu option within limits.
 * @param input The input stream.
 * @param upperLimit The maximum valid option.
 * @param option The option entered by the user.
 * @return true if valid, false otherwise.
 */
bool validateMenuInput(istream &input, int upperLimit, int option) {
    char nextChar;

    if (!input) {
        input.clear();
        while (getchar() != '\n'); 
        cout << "\nError: Invalid value\n\n";
        return false;
    }
    nextChar = getchar();
    if (nextChar == '\n') {
        if (option > upperLimit || option < 1) {
            cout << "\nError: Option must be within the established limit\n\n";
            return false;
        } 
        return true;
    }

    if (nextChar == '.' || nextChar == ',' || nextChar == ' ') {
        while (getchar() != '\n'); 
        cout << "\nError: Decimals and spaces are not allowed\n\n";
        return false;
    }

    if (isAlpha(nextChar)) {
        while (getchar() != '\n'); 
        cout << "\nError: Only numbers are allowed\n\n";
        return false;
    }

    while (getchar() != '\n'); 
    cout << "\nError: Only numbers are allowed\n\n";
    return false;
}

/**
 * @brief Validates that the input is a valid integer.
 * @param input The input stream.
 * @return true if valid, false otherwise.
 */
bool validateInteger(istream &input) {
    char nextChar;

    if (!input) {
        input.clear();
        while (getchar() != '\n'); 
        cout << "\nError: Invalid value\n\n";
        return false;
    }

    nextChar = getchar();
    if (nextChar == '\n') {
         return true;
    }

    if (nextChar == '.' || nextChar == ',' || nextChar == ' ') {
        while (getchar() != '\n'); 
        cout << "\nError: Decimals and spaces are not allowed\n\n";
        return false;
    }

    if (isAlpha(nextChar)) {
        while (getchar() != '\n'); 
        cout << "\nError: Only numbers are allowed\n\n";
        return false;
    }
    
    while (getchar() != '\n'); 
    cout << "\nError: Only numbers are allowed\n\n";
    return false;
}
