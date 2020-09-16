#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>

class Utility {

    public:
        static bool isNumber(std::string);
        Utility* getInstance();
        Utility();

    protected:
        static Utility* instance;
};

#endif // UTILITY_HEADER