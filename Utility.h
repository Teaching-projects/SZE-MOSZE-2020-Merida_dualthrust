#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>
#include "Character.h"
#include <map>
#include <any>
#include <fstream>
#include <sstream>

namespace Utility {
    bool isNumber(const std::string&);
    std::vector<std::string> split(const std::string&, char);

    std::map<std::string, std::any> parseString(std::string);
    std::map<std::string, std::any> parseStream(std::ifstream&);
    std::map<std::string, std::any> parseFile(const std::string&);

    void deleteCharacters(const std::vector<Character*>&);
};

#endif // UTILITY_HEADER