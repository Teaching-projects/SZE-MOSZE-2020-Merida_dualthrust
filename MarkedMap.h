/**
 * @file Hero.h
 * @author LilikF
 * @brief MarkedMap class
 * 
 * This class contains basic methods for handling our marked maps.
 * 
 * @version 1.0
 * @date 2020-12-03
 * 
 */
#ifndef MARKEDMAP_HEADER
#define MARKEDMAP_HEADER
#include <string>
#include <map>
#include "Map.h"

class MarkedMap : public Map
{
private:
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

public:

    /**
     * @brief Gives back a MarkedMap constructed from a txt file.
     * 
     * @param path Path of the input file from which the MarkedMap is parsed.
     * 
     * @return MarkedMap 
     * 
     */
    MarkedMap(std::string);

    /**
     * @brief Destructor for MarkedMap class.
     * 
     */
    ~MarkedMap(){};
};
#endif
