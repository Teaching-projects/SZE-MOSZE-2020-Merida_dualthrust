/**
 * @file Map.h
 * @author NemesTom
 * @brief Map class
 * 
 * This class contains basic methods for handling the map.
 * 
 * @version 2.0
 * @date 2020-12-08
 * 
 */

#ifndef MAP_HEADER
#define MAP_HEADER

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>


class Map
{
    protected:

        /**
         * @brief Data structure that contains the map.
         * 
         */
        std::vector<std::vector<int>> map = std::vector<std::vector<int>>();
    
    public:
        int longest_row_size=0;
        int longest_column_size=0;
        
        std::vector<std::vector<int>> getMap(){
            return map;
        }

        /**
         * @brief Copy constructor for Map
         * 
         */
        Map(const Map &map2):map(map2.map), longest_row_size(map2.longest_row_size),longest_column_size(map2.longest_column_size){}

        /**
         * @brief Vector holding the positions of all monsters.
         * 
         * The vector itself holds pair type values, the first of the pair representing the row in which the monster is, the second of the pair representing the column.
         * 
         */
        std::vector<std::pair<int,int>> monsterPositions;

        /**
         * @brief Pair type holding the hero's position.
         * 
         * The first of the pair represents the row in which the hero is, the second of the pair represents the column.
         * 
         */
        std::pair<int,int> heroPosition;

        /**
         * @brief Getter for the hero's position.
         * 
         * @return const pair Returns a pair type. First of the pair is the row, the second is the column.
         * 
         */
        const std::pair<int,int> getHeroPosition(){return heroPosition;};

        /**
         * @brief Getter for the position of monsters' positions.
         * 
         * @return Returns a vector which holds the monsters' positions.
         * 
         */
        const std::vector<std::pair<int,int>> getMonsterPositions(char){return monsterPositions;};

        /**
         * @brief Setter for the hero's position.
         * 
         * @param pos Takes a pair type. First of the pair is the row, the second is the column.
         * 
         */
        void setHeroPosition(std::pair<int,int> pos){heroPosition=pos;};

        /**
         * @brief Holds tile types.
         * 
         */
        enum type 
        {
            Free,       /* 0 */
            Wall,       /* 1 */
            Hero,       /* 2 */
            Monster,    /* 3 */
            Monsters    /* 4 */
        };

        /**
         * @brief Holds the string representations of tile types.
         * 
         */
        std::string tileString [5]={
            "░░",
            "██",
            "┣┫",
            "M░",
            "MM",
        };

        std::string svg [5]={
            "./SVGs/free.svg",
            "./SVGs/wall.svg",
            "./SVGs/hero.svg",
            "./SVGs/monster.svg",
            "./SVGs/monsters.svg",
        };

        /**
         * @brief Constructor for an empty map.
         * 
         * @return Map 
         * 
         */
        Map(/**There's no input parameter here.*/);

        /**
         * @brief Virtual destructor for Map - MarkedMap inherits this class.
         * 
         */
        virtual ~Map(/**There's no input parameter here.*/){};

        /**
         * @brief Gives back a map constructed from a txt file.
         * 
         * When the given input is incorrect, it returns with an exception.
         * 
         * @param filename Name of the input file.
         * 
         * @return Map 
         * 
         */
        explicit Map(std::string filename);

        /**
         * @brief Gives back the type of tile based on coordinates.
         * 
         * Takes y and x coordinates.
         * 
         * @param Which row
         * @param Which column
         * 
         * @return Type of the tile 
         * 
         */
        Map::type get(unsigned int row, unsigned int column) const;

        /**
         * @brief Draws our map to the standard output.
         * 
         * Draws the map around the hero, based on its viewrange - lightradius - and its x and y coordinates.
         * 
         * @param viewrange, lightradius of hero object. 
         * @param Hero row
         * @param Hero column
         * 
         */
        void drawMap(const int viewrange, int hero_row, int hero_column) const;

        /**
         * @brief Sets the type of a certain tile.
         * 
         * @param Which row
         * @param Which column
         * @param Type of the tile 
         * 
         */
        void setTile(int, int, int);

    class WrongIndexException : std::exception
	{
		public:
            /**
             * @brief Prevents out of bound indexing 
             * 
            */
		    WrongIndexException(){}
	};
};

#endif // MAP_HEADER