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

#include <Map.h>
#include <string>

class MarkedMap : public Map
{
private:
    /* data */
public:
    MarkedMap(std::string);
    ~MarkedMap();
    const std::pair<int,int> getHeroPosition();
    const std::pair<int,int> getMonsterPositions(char);
};
#endif
/* PÉLDA INPUTRA
##############
# H #  ####  #
# ####22##  #
# 12# 3##  #
###1# ##  #
#     1   #
######### 

A korabbiakhoz kepest H es szamjegyek fordulhatnak meg elo.
Az elobbi a hero indulohelyet, az utobbiak pedig szornyek helyet jelolik.

A get ugyanugy mukodik, mint az osnel
*/