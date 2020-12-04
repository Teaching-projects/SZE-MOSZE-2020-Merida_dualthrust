/**
 * @file Hero.h
 * @author NemesTom
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

#include "Map.h"
#include <string>

class MarkedMap : public Map
{
private:
    /* data */
    std::vector<std::pair<int,int>> monsterPositions;
    std::pair<int,int> heroPosition;
public:
    //Constructors, destructor
    MarkedMap(std::string);
    ~MarkedMap();

};
#endif
