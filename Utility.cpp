#include "Utility.h"
#include <iostream>
#include <string>
#include <ctype.h>

Utility::Utility() {

};

//Method used for getting the only instance of the Utility class
//If the instance doesn't exist yet, it creates the object, otherwise it returns it
Utility* Utility::getInstance() {
    if (!this->instance)
        this->instance = new Utility;
    return this->instance;
}

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