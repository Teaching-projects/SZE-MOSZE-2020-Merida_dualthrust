#include "Utility.h"
#include <iostream>
#include <string>
#include <ctype.h>

Utility::Utility() {

};

Utility* Utility::getInstance() {
    if (!this->instance)
        this->instance = new Utility;
    return this->instance;
}

bool Utility::isNumber(std::string input) {
    if (input.size() == 0) return false;
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}