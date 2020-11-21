#ifndef MAP_HEADER
#define MAP_HEADER

#include <string>

class Map
{
    private:

    public:

        enum type 
        {
            Free,
            Wall
        };

        Map::type get(int x, int y) const;

        Map(std::string filename); // Betolt fajlbol egy terkepet

};

#endif // MAP_HEADER