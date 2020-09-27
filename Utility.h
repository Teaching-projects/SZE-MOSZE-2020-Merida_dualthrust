#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>
#include "Character.h"


class Utility {

    public:
        static bool isNumber(const std::string&);
        static std::vector<std::string> split(const std::string&, char);
        static void safeDeleteCharacters(const std::vector<Character*>&);
};

#endif // UTILITY_HEADER