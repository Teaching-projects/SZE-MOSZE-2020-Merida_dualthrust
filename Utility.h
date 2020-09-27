#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>
#include "Character.h"


class Utility {

    public:
        static bool isNumber(std::string);
        static std::vector<std::string> split(std::string, char);
        static void safeDeleteCharacters(std::vector<Character*>);
};

#endif // UTILITY_HEADER