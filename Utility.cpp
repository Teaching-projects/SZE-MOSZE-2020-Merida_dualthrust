#include "Utility.h"
#include <iostream>
#include <string>
#include <ctype.h>

//Method for checking if a given input is a number or not
bool Utility::isNumber(std::string input) {
    if (input.size() == 0) return false;
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}