#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>
#include "Character.h"


namespace Utility {
    bool isNumber(const std::string&);
    std::vector<std::string> split(const std::string&, char);
    void deleteCharacters(const std::vector<Character*>&);
    std::vector<std::string> getJsonData(const std::string&);
};

#endif // UTILITY_HEADER