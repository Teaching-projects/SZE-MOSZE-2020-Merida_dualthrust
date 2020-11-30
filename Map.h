/**
 * @file Map.h
 * @author NemesTom
 * @brief Map class
 * 
 * This class contains basic methods for handling the map.
 * 
 * 
 * @version 1.0
 * @date 2020-11-22
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
    /* INDEXING OF THE MAP STARTS FROM THE UPPER LEFT CORNET, FIRST INDEX IS ROW, SECOND IS COLUMN */
    private:
        /**
         * @brief Data structure that contains the map.
         * 
         */
        std::vector<std::vector<int>> map;
        unsigned int longest_row_size;
    public:
        /**
         * @brief Types that the map may contain.
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
         * @brief Constructor for an empty map.
         * 
         * @return Map 
         * 
         */
        Map(/**There's no input parameter here.*/);
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
        Map(std::string filename);
        /**
         * @brief Gives back the type of terrain based on coordinates.
         * 
         * Takes y and x coordinates.
         * 
         * @param Which row
         * @param Which column
         * @return type 
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
         */
        void drawMap(unsigned const int viewrange, unsigned int hero_row, unsigned int hero_column) const;
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