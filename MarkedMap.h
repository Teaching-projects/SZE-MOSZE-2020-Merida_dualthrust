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
public:

    /**
     * @brief Gives back a MarkedMap constructed from a txt file.
     * 
     * @param path Path of the input file from which the MarkedMap is parsed.
     * 
     * @return MarkedMap 
     * 
     */
    explicit MarkedMap(std::string);

    /**
     * @brief Destructor for MarkedMap class.
     * 
     */
    ~MarkedMap(){};
};
#endif
