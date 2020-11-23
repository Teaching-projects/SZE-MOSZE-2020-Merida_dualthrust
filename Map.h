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
    private:
        /**
         * @brief Data structure that contains the map.
         * 
         */
        std::vector<std::string> map; 
    public:
        /**
         * @brief Types that the map may contain.
         * 
         */
        enum type 
        {
            Free,
            Wall
        };
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
         * Takes x and y coordinates.
         * 
         * @param x Longitudinal coordinate. (Which "column")
         * @param y Latitudinal coordinate. (Which "row")
         * @return type 
         * 
         */
        Map::type get(int x, int y) const;

    class WrongIndexException : std::exception
	{
		public:
            /**
             * @brief Constructor for the exception
             * @param key A hiba leirasa
            */
		    WrongIndexException(){}
	};
};

#endif // MAP_HEADER