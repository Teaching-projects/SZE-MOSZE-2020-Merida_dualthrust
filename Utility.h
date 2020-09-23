#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>

class Utility {

    public:
        static bool isNumber(std::string);
        static std::vector<std::string> split(std::string, char);
        static void writeToFile(std::string, std::string);
};

#endif // UTILITY_HEADER