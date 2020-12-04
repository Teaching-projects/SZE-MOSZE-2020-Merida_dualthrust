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
    
public:
    MarkedMap(std::string);
    ~MarkedMap();
    const std::pair<int,int> getHeroPosition();
    const std::vector<std::pair<int,int>> getMonsterPositions(char);
    int longest_row_size;
};
#endif
