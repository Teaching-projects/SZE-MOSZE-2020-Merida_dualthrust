#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>

/* Utility class (Singleton)
   This class was created to have easy access to utility functions like vartype checks
   and other things that may later need to be added to the project.
*/
class Utility {

    public:
        static bool isNumber(std::string);
        Utility* getInstance();
        Utility();

    protected:
        static Utility* instance;
};

#endif // UTILITY_HEADER